import React, { useState, useCallback } from "react";
import { useDropzone } from "react-dropzone";
import axios from "axios";
import CryptoJS from "crypto-js";
import "./FileUpload.css";

const PINATA_API_KEY = process.env.REACT_APP_PINATA_API_KEY;
const PINATA_SECRET = process.env.REACT_APP_PINATA_SECRET_KEY;
const SECRET_KEY = process.env.REACT_APP_ENC_KEY || "privex-default-key";

const FileUpload = ({ contract, account }) => {
    const [file, setFile] = useState(null);
    const [status, setStatus] = useState("idle");
    const [message, setMessage] = useState("");

    const onDrop = useCallback((accepted) => {
        if (accepted.length > 0) {
            setFile(accepted[0]);
            setMessage("");
        }
    }, []);

    const { getRootProps, getInputProps, isDragActive } = useDropzone({
        onDrop,
        multiple: false,
        maxSize: 50 * 1024 * 1024,
        onDropRejected: () => setMessage("File too large. Max size is 50 MB."),
    });

    const encryptFile = (file) =>
        new Promise((resolve, reject) => {
            const reader = new FileReader();
            reader.readAsDataURL(file);
            reader.onload = () => {
                const encrypted = CryptoJS.AES.encrypt(reader.result, SECRET_KEY).toString();
                resolve(encrypted);
            };
            reader.onerror = reject;
        });

    const handleUpload = async (e) => {
        e.preventDefault();
        if (!file) { setMessage("Please select a file first."); return; }
        if (!contract) { setMessage("Wallet not connected or contract not loaded."); return; }

        setStatus("uploading");
        setMessage("");

        try {
            const encrypted = await encryptFile(file);
            const blob = new Blob([encrypted], { type: "text/plain" });
            const form = new FormData();
            form.append("file", blob, file.name);

            const res = await axios.post(
                "https://api.pinata.cloud/pinning/pinFileToIPFS",
                form,
                {
                    headers: {
                        pinata_api_key: PINATA_API_KEY,
                        pinata_secret_api_key: PINATA_SECRET,
                        "Content-Type": "multipart/form-data",
                    },
                }
            );

            const ipfsUrl = `https://gateway.pinata.cloud/ipfs/${res.data.IpfsHash}`;
            const tx = await contract.add(account, file.name, ipfsUrl);
            await tx.wait();

            setStatus("success");
            setMessage(`✓ "${file.name}" uploaded successfully.`);
            setFile(null);
            setTimeout(() => { setStatus("idle"); setMessage(""); }, 4000);
        } catch (err) {
            setStatus("error");
            setMessage(err?.response?.data?.error?.details || err.message || "Upload failed.");
        }
    };

    const formatSize = (bytes) => {
        if (bytes < 1024) return `${bytes} B`;
        if (bytes < 1024 * 1024) return `${(bytes / 1024).toFixed(1)} KB`;
        return `${(bytes / (1024 * 1024)).toFixed(1)} MB`;
    };

    return (
        <div className="upload-section">
            <h3 className="section-label">Upload File</h3>

            <form onSubmit={handleUpload}>
                <div
                    {...getRootProps()}
                    id="dropzone"
                    className={`dropzone ${isDragActive ? "dropzone--active" : ""} ${file ? "dropzone--has-file" : ""}`}
                >
                    <input {...getInputProps()} />
                    {file ? (
                        <div className="file-ready">
                            <span className="file-ready-icon">📄</span>
                            <div>
                                <p className="file-ready-name">{file.name}</p>
                                <p className="file-ready-size">{formatSize(file.size)}</p>
                            </div>
                            <button
                                type="button"
                                className="file-clear"
                                onClick={(e) => { e.stopPropagation(); setFile(null); }}
                                aria-label="Remove file"
                            >
                                ✕
                            </button>
                        </div>
                    ) : (
                        <div className="dropzone-prompt">
                            <span className="dropzone-icon">☁</span>
                            <p className="dropzone-text">
                                {isDragActive ? "Drop your file here…" : "Drag & drop a file, or click to browse"}
                            </p>
                            <p className="dropzone-hint">Max 50 MB · Encrypted before upload</p>
                        </div>
                    )}
                </div>

                {message && (
                    <div className={`upload-message ${status === "success" ? "success-banner" : "error-banner"}`}>
                        {message}
                    </div>
                )}

                <button
                    id="btn-upload"
                    type="submit"
                    className="btn-primary upload-btn"
                    disabled={!file || status === "uploading"}
                >
                    {status === "uploading" ? (
                        <><span className="spinner" />Encrypting & Uploading…</>
                    ) : (
                        <>🔒 Encrypt & Upload to IPFS</>
                    )}
                </button>
            </form>
        </div>
    );
};

export default FileUpload;
