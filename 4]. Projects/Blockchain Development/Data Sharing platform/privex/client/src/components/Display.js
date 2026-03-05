import React, { useState, useEffect, useCallback } from "react";
import axios from "axios";
import CryptoJS from "crypto-js";
import "./Display.css";

const SECRET_KEY = process.env.REACT_APP_ENC_KEY || "privex-default-key";

const Display = ({ contract, account, onFilesLoaded, onShareClick }) => {
    const [files, setFiles] = useState([]);
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState("");
    const [searchAddr, setSearchAddr] = useState("");
    const [viewingOther, setViewingOther] = useState(false);

    const fetchFiles = useCallback(async (targetAddr = "") => {
        if (!contract || !account) return;
        setLoading(true);
        setError("");

        try {
            const addr = targetAddr.trim() || account;
            const raw = targetAddr.trim()
                ? await contract.display(addr)
                : await contract.getAllFiles(addr);

            const formatted = raw.map((f) => ({
                id: f.id.toString(),
                fileName: f.fileName,
                url: f.url,
            }));

            setFiles(formatted);
            setViewingOther(Boolean(targetAddr.trim()));
            onFilesLoaded?.(formatted);
        } catch (err) {
            setError(err.reason || err.message || "Failed to fetch files.");
        } finally {
            setLoading(false);
        }
    }, [contract, account, onFilesLoaded]);

    useEffect(() => {
        fetchFiles();
    }, [fetchFiles]);

    const openFile = async (file) => {
        try {
            const res = await axios.get(file.url);
            const bytes = CryptoJS.AES.decrypt(res.data, SECRET_KEY);
            const decrypted = bytes.toString(CryptoJS.enc.Utf8);
            if (!decrypted) throw new Error("Could not decrypt. Wrong key?");
            window.open(decrypted, "_blank", "noopener,noreferrer");
        } catch (err) {
            setError("Could not open file: " + (err.message || "Decryption error"));
            setTimeout(() => setError(""), 4000);
        }
    };

    const handleSearch = (e) => {
        e.preventDefault();
        fetchFiles(searchAddr);
    };

    const handleReset = () => {
        setSearchAddr("");
        fetchFiles("");
    };

    return (
        <div className="display-section">
            <div className="display-header">
                <h3 className="section-label">
                    {viewingOther ? "Shared Files (Viewing Other)" : "My Files"}
                </h3>
                <div className="display-actions">
                    <button id="btn-share-access" className="btn-ghost btn-sm" onClick={onShareClick}>
                        🔗 Manage Access
                    </button>
                    <button className="btn-ghost btn-sm" onClick={() => fetchFiles(searchAddr)}>
                        ↻ Refresh
                    </button>
                </div>
            </div>

            <form onSubmit={handleSearch} className="search-bar">
                <input
                    id="input-search-address"
                    type="text"
                    placeholder="Enter Ethereum address to view shared files…"
                    value={searchAddr}
                    onChange={(e) => setSearchAddr(e.target.value)}
                    className="search-input"
                    spellCheck={false}
                />
                <button type="submit" id="btn-search" className="btn-primary btn-sm">Search</button>
                {viewingOther && (
                    <button type="button" className="btn-ghost btn-sm" onClick={handleReset}>
                        My Files
                    </button>
                )}
            </form>

            {error && <div className="error-banner" role="alert">{error}</div>}
            {loading && <div className="files-loading"><span className="spinner" /> Loading files…</div>}

            {!loading && files.length === 0 && !error && (
                <div className="files-empty">
                    <span className="files-empty-icon">📂</span>
                    <p>{viewingOther ? "No shared files found for this address." : "No files uploaded yet."}</p>
                </div>
            )}

            {!loading && files.length > 0 && (
                <div className="files-grid">
                    {files.map((file) => (
                        <button
                            key={file.id}
                            className="file-card glass"
                            onClick={() => openFile(file)}
                            title={`Open ${file.fileName}`}
                        >
                            <span className="file-card-icon">📄</span>
                            <span className="file-card-name" title={file.fileName}>{file.fileName}</span>
                            <span className="file-card-id">#{file.id}</span>
                        </button>
                    ))}
                </div>
            )}
        </div>
    );
};

export default Display;
