import React, { useState } from "react";
import "./UserManual.css";

const STEPS = [
    {
        icon: "🦊",
        title: "Install & Connect MetaMask",
        points: [
            "Install the MetaMask browser extension from metamask.io.",
            "Create a wallet and safely back up your seed phrase.",
            "Connect it to the Hardhat local network (chainId 31337) or Sepolia testnet.",
            "Click 'Connect Wallet' on PriveX to link your account.",
        ],
    },
    {
        icon: "☁️",
        title: "Upload a File",
        points: [
            "Open the App dashboard by clicking 'Launch App'.",
            "Drag & drop or select a file (max 50 MB).",
            "PriveX encrypts it with AES-256 in your browser.",
            "The encrypted blob is pinned to IPFS via Pinata.",
            "The IPFS hash is recorded on-chain via the smart contract.",
        ],
    },
    {
        icon: "🔗",
        title: "Share Access",
        points: [
            "Click 'Manage Access' inside the dashboard.",
            "Select files you want to share and enter a recipient Ethereum address.",
            "For group sharing, use the Multi-Address tab with comma-separated addresses.",
            "A blockchain transaction records the access grant — no middlemen.",
        ],
    },
    {
        icon: "📂",
        title: "View Shared Files",
        points: [
            "Enter another user's Ethereum address in the search bar.",
            "If they've granted you access, their files will appear.",
            "Click a file to decrypt and open it in a new tab.",
        ],
    },
    {
        icon: "🔒",
        title: "Revoke Access",
        points: [
            "Open 'Manage Access' → switch to 'Who Has Access'.",
            "You'll see all active grants with their file counts.",
            "Click 'Revoke' to remove access — the smart contract enforces it immediately.",
        ],
    },
];

const UserManual = () => {
    const [open, setOpen] = useState(null);

    return (
        <div className="manual-page">
            <div className="manual-hero">
                <h1 className="manual-title">User Manual</h1>
                <p className="manual-subtitle">
                    Everything you need to get started with PriveX — the decentralized file vault.
                </p>
            </div>

            <div className="manual-steps">
                {STEPS.map((step, i) => (
                    <div
                        key={i}
                        className={`step-card glass ${open === i ? "step-card--open" : ""}`}
                        onClick={() => setOpen(open === i ? null : i)}
                        role="button"
                        tabIndex={0}
                        onKeyDown={(e) => e.key === "Enter" && setOpen(open === i ? null : i)}
                    >
                        <div className="step-header">
                            <div className="step-left">
                                <span className="step-num">0{i + 1}</span>
                                <span className="step-icon">{step.icon}</span>
                                <h3 className="step-title">{step.title}</h3>
                            </div>
                            <span className="step-chevron">{open === i ? "▲" : "▼"}</span>
                        </div>

                        {open === i && (
                            <ul className="step-points">
                                {step.points.map((p, j) => (
                                    <li key={j} className="step-point">
                                        <span className="point-dot" />
                                        {p}
                                    </li>
                                ))}
                            </ul>
                        )}
                    </div>
                ))}
            </div>
        </div>
    );
};

export default UserManual;
