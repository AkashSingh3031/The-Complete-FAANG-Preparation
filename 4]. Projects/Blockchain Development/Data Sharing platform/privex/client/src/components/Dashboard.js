import React, { useState } from "react";
import { useWeb3 } from "../context/Web3Context";
import FileUpload from "./FileUpload";
import Display from "./Display";
import Modal from "./Modal";
import "./Dashboard.css";

const Dashboard = ({ onClose }) => {
    const { account, contract } = useWeb3();
    const [modalOpen, setModalOpen] = useState(false);
    const [userFiles, setUserFiles] = useState([]);

    const shortAddr = (addr) =>
        addr ? `${addr.slice(0, 8)}…${addr.slice(-6)}` : "Not connected";

    return (
        <div className="dash-overlay" role="dialog" aria-modal="true" aria-label="File Dashboard">
            <div className="dash-panel glass">
                <div className="dash-header">
                    <div>
                        <h2 className="dash-title">My Vault</h2>
                        <p className="dash-account">
                            <span className="dash-account-dot" />
                            <span className="font-mono">{shortAddr(account)}</span>
                        </p>
                    </div>
                    <button
                        id="btn-close-dashboard"
                        className="dash-close"
                        onClick={onClose}
                        aria-label="Close dashboard"
                    >
                        ✕
                    </button>
                </div>

                <div className="dash-body">
                    <FileUpload contract={contract} account={account} />
                    <Display
                        contract={contract}
                        account={account}
                        onFilesLoaded={setUserFiles}
                        onShareClick={() => setModalOpen(true)}
                    />
                </div>
            </div>

            {modalOpen && (
                <Modal
                    setModalOpen={setModalOpen}
                    contract={contract}
                    userFiles={userFiles}
                    account={account}
                />
            )}
        </div>
    );
};

export default Dashboard;
