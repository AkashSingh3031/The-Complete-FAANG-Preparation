import React from "react";
import { Link } from "react-router-dom";
import { useWeb3 } from "../context/Web3Context";
import "./Home.css";

const FEATURES = [
    {
        icon: "🔐",
        title: "AES-256 Encryption",
        desc: "Files are encrypted client-side before they ever leave your device.",
    },
    {
        icon: "⛓️",
        title: "Blockchain Access Control",
        desc: "Smart contracts enforce who can see what — immutably, on-chain.",
    },
    {
        icon: "🌐",
        title: "IPFS Storage",
        desc: "Encrypted files are pinned to IPFS, fully decentralized and censorship-resistant.",
    },
    {
        icon: "🔑",
        title: "Granular Sharing",
        desc: "Share or revoke access to individual files with any Ethereum address.",
    },
];

const Home = ({ onLaunchApp }) => {
    const { isConnected, isConnecting, connectWallet, account } = useWeb3();

    const shortAddr = (addr) => `${addr.slice(0, 6)}…${addr.slice(-4)}`;

    return (
        <div className="home">
            <section className="hero">
                <div className="hero-eyebrow">
                    <span className="eyebrow-dot" />
                    Decentralized · Encrypted · Open Source
                </div>

                <h1 className="hero-title">
                    Own Your Files,
                    <br />
                    <span className="gradient-text">Own Your Privacy.</span>
                </h1>

                <p className="hero-subtitle">
                    PriveX lets you upload, encrypt, and share files on the blockchain.
                    No servers. No middlemen. You hold the keys.
                </p>

                <div className="hero-actions">
                    {isConnected ? (
                        <>
                            <div className="connected-pill">
                                <span className="pulse-dot" />
                                {shortAddr(account)}
                            </div>
                            <button id="btn-launch-app" className="btn-primary" onClick={onLaunchApp}>
                                Launch App →
                            </button>
                        </>
                    ) : (
                        <>
                            <button
                                id="btn-hero-connect"
                                className="btn-primary"
                                onClick={connectWallet}
                                disabled={isConnecting}
                            >
                                {isConnecting ? (
                                    <><span className="spinner" />Connecting…</>
                                ) : (
                                    <>🦊 Connect MetaMask</>
                                )}
                            </button>
                            <Link to="/manual" className="btn-ghost">
                                How it works
                            </Link>
                        </>
                    )}
                </div>

                <div className="hero-badges">
                    {["Solidity 0.8", "Hardhat", "React 18", "Ethers.js", "IPFS + Pinata"].map((b) => (
                        <span key={b} className="tech-pill">{b}</span>
                    ))}
                </div>
            </section>

            <section className="features" aria-label="Features">
                <h2 className="section-title">Why PriveX?</h2>
                <div className="features-grid">
                    {FEATURES.map((f) => (
                        <div key={f.title} className="feature-card glass">
                            <div className="feature-icon">{f.icon}</div>
                            <h3 className="feature-title">{f.title}</h3>
                            <p className="feature-desc">{f.desc}</p>
                        </div>
                    ))}
                </div>
            </section>

            <section className="stats" aria-label="Stats">
                <div className="stats-row glass">
                    {[
                        { value: "256-bit", label: "AES Encryption" },
                        { value: "100%", label: "Decentralized" },
                        { value: "0", label: "Third-Party Access" },
                        { value: "∞", label: "File Access Control" },
                    ].map((s) => (
                        <div key={s.label} className="stat-item">
                            <div className="stat-value gradient-text">{s.value}</div>
                            <div className="stat-label">{s.label}</div>
                        </div>
                    ))}
                </div>
            </section>
        </div>
    );
};

export default Home;
