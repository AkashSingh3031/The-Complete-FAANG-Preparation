import React, { useState, useEffect, useCallback } from "react";
import "./Modal.css";

const Modal = ({ setModalOpen, contract, userFiles, account }) => {
    const [tab, setTab] = useState("share");
    const [shareAddr, setShareAddr] = useState("");
    const [multiAddrs, setMultiAddrs] = useState("");
    const [selectedIds, setSelectedIds] = useState([]);
    const [accessList, setAccessList] = useState([]);
    const [loading, setLoading] = useState(false);
    const [message, setMessage] = useState({ type: "", text: "" });

    const loadAccessList = useCallback(async () => {
        if (!contract) return;
        try {
            const list = await contract.shareAccess();
            setAccessList(list.filter((item) => item.access));
        } catch {
            // silence — non-critical
        }
    }, [contract]);

    useEffect(() => { loadAccessList(); }, [loadAccessList]);

    const toggleFile = (id) =>
        setSelectedIds((prev) =>
            prev.includes(id) ? prev.filter((x) => x !== id) : [...prev, id]
        );

    const notify = (type, text) => {
        setMessage({ type, text });
        setTimeout(() => setMessage({ type: "", text: "" }), 4000);
    };

    const handleShare = async () => {
        const targets = tab === "multi"
            ? multiAddrs.split(",").map((a) => a.trim()).filter(Boolean)
            : [shareAddr.trim()];

        if (targets.length === 0 || !targets[0]) return notify("error", "Enter at least one address.");
        if (selectedIds.length === 0) return notify("error", "Select at least one file to share.");

        setLoading(true);
        try {
            const ids = selectedIds.map(Number);
            for (const addr of targets) {
                const tx = await contract.allow(addr, ids, { gasLimit: 500_000 });
                await tx.wait();
            }
            await loadAccessList();
            setShareAddr("");
            setMultiAddrs("");
            setSelectedIds([]);
            notify("success", `Access granted to ${targets.length} address${targets.length > 1 ? "es" : ""}.`);
        } catch (err) {
            notify("error", err.reason || err.message || "Failed to share.");
        } finally {
            setLoading(false);
        }
    };

    const handleRevoke = async (addr) => {
        setLoading(true);
        try {
            const tx = await contract.disallow(addr);
            await tx.wait();
            await loadAccessList();
            notify("success", "Access revoked.");
        } catch (err) {
            notify("error", err.reason || err.message || "Failed to revoke.");
        } finally {
            setLoading(false);
        }
    };

    const shortAddr = (a) => `${a.slice(0, 8)}…${a.slice(-6)}`;

    return (
        <div className="modal-overlay" role="dialog" aria-modal="true" aria-label="Manage file access">
            <div className="modal-box glass">
                <div className="modal-header">
                    <h3 className="modal-title">Manage Access</h3>
                    <button
                        id="btn-close-modal"
                        className="modal-close"
                        onClick={() => setModalOpen(false)}
                        aria-label="Close"
                    >✕</button>
                </div>

                {message.text && (
                    <div className={message.type === "success" ? "success-banner" : "error-banner"}>
                        {message.text}
                    </div>
                )}

                <div className="modal-tabs">
                    {[
                        { key: "share", label: "Share Files" },
                        { key: "multi", label: "Multi-Address" },
                        { key: "access", label: `Who Has Access (${accessList.length})` },
                    ].map((t) => (
                        <button
                            key={t.key}
                            className={`tab-btn ${tab === t.key ? "tab-btn--active" : ""}`}
                            onClick={() => setTab(t.key)}
                        >
                            {t.label}
                        </button>
                    ))}
                </div>

                <div className="modal-body">
                    {tab !== "access" && (
                        <>
                            <div className="modal-field">
                                <label className="field-label">
                                    {tab === "multi" ? "Ethereum Addresses (comma separated)" : "Recipient Address"}
                                </label>
                                {tab === "multi" ? (
                                    <textarea
                                        id="input-multi-address"
                                        className="field-textarea"
                                        placeholder="0xABC…, 0xDEF…, 0x123…"
                                        value={multiAddrs}
                                        onChange={(e) => setMultiAddrs(e.target.value)}
                                        rows={3}
                                    />
                                ) : (
                                    <input
                                        id="input-share-address"
                                        type="text"
                                        className="field-input"
                                        placeholder="0x..."
                                        value={shareAddr}
                                        onChange={(e) => setShareAddr(e.target.value)}
                                        spellCheck={false}
                                    />
                                )}
                            </div>

                            <div className="modal-field">
                                <label className="field-label">Select Files to Share</label>
                                {userFiles.length === 0 ? (
                                    <p className="field-hint">No files available.</p>
                                ) : (
                                    <div className="file-checklist">
                                        {userFiles.map((file) => (
                                            <label key={file.id} className="file-check-item">
                                                <input
                                                    type="checkbox"
                                                    checked={selectedIds.includes(file.id)}
                                                    onChange={() => toggleFile(file.id)}
                                                />
                                                <span>{file.fileName || `File #${file.id}`}</span>
                                            </label>
                                        ))}
                                    </div>
                                )}
                            </div>

                            <button
                                id="btn-confirm-share"
                                className="btn-primary"
                                style={{ width: "100%", justifyContent: "center" }}
                                onClick={handleShare}
                                disabled={loading}
                            >
                                {loading ? <><span className="spinner" /> Processing…</> : "Grant Access"}
                            </button>
                        </>
                    )}

                    {tab === "access" && (
                        <div className="access-list">
                            {accessList.length === 0 ? (
                                <p className="field-hint" style={{ textAlign: "center", padding: "24px 0" }}>
                                    No active access grants yet.
                                </p>
                            ) : (
                                accessList.map((item, i) => (
                                    <div key={i} className="access-row">
                                        <span className="access-addr font-mono">{shortAddr(item.user)}</span>
                                        <span className="access-files">{item.fileIds.length} file{item.fileIds.length !== 1 ? "s" : ""}</span>
                                        <button
                                            className="btn-danger"
                                            onClick={() => handleRevoke(item.user)}
                                            disabled={loading}
                                        >
                                            Revoke
                                        </button>
                                    </div>
                                ))
                            )}
                        </div>
                    )}
                </div>
            </div>
        </div>
    );
};

export default Modal;
