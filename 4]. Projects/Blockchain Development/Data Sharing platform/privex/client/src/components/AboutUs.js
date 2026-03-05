import React from "react";
import "./AboutUs.css";

const TECH = [
    { name: "Solidity", icon: "📜", desc: "Smart contracts on Ethereum" },
    { name: "Hardhat", icon: "⛏️", desc: "Development & testing framework" },
    { name: "React 18", icon: "⚛️", desc: "Frontend UI library" },
    { name: "Ethers.js", icon: "🔌", desc: "Blockchain interactions" },
    { name: "IPFS", icon: "🌐", desc: "Decentralized file storage" },
    { name: "Pinata", icon: "📌", desc: "IPFS pinning service" },
    { name: "AES-256", icon: "🔐", desc: "Client-side encryption" },
    { name: "MetaMask", icon: "🦊", desc: "Web3 wallet integration" },
];

const PRINCIPLES = [
    { title: "No Servers", desc: "Files are stored on IPFS, not our servers. We don't exist between you and your data." },
    { title: "No Custody", desc: "Your private keys stay in MetaMask. We never see or store them." },
    { title: "Open Source", desc: "All smart contracts and frontend code are publicly auditable on GitHub." },
    { title: "Verifiable", desc: "Every access grant and revocation is an on-chain transaction you can verify." },
];

const AboutUs = () => (
    <div className="about-page">
        <section className="about-hero">
            <h1 className="about-title">
                Built on <span className="gradient-text">Trust</span>,<br />
                Not Promises.
            </h1>
            <p className="about-desc">
                PriveX is an open-source decentralized application for encrypted file
                storage and access control. No company controls your files — the
                blockchain does.
            </p>
        </section>

        <section className="about-principles">
            <h2 className="section-title">Our Principles</h2>
            <div className="principles-grid">
                {PRINCIPLES.map((p) => (
                    <div key={p.title} className="principle-card glass">
                        <h3 className="principle-title">{p.title}</h3>
                        <p className="principle-desc">{p.desc}</p>
                    </div>
                ))}
            </div>
        </section>

        <section className="about-tech">
            <h2 className="section-title">Tech Stack</h2>
            <div className="tech-grid">
                {TECH.map((t) => (
                    <div key={t.name} className="tech-card glass">
                        <span className="tech-card-icon">{t.icon}</span>
                        <span className="tech-card-name">{t.name}</span>
                        <span className="tech-card-desc">{t.desc}</span>
                    </div>
                ))}
            </div>
        </section>

        <section className="about-cta glass">
            <h2>Ready to own your files?</h2>
            <p>Connect your MetaMask wallet and start using PriveX in under 60 seconds.</p>
            <a href="/" className="btn-primary" style={{ display: "inline-flex", textDecoration: "none" }}>
                Get Started →
            </a>
        </section>
    </div>
);

export default AboutUs;
