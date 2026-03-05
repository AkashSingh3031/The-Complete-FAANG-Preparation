import React, { useState } from "react";
import { Link, useLocation } from "react-router-dom";
import { useWeb3 } from "../context/Web3Context";
import "./Navbar.css";

const Navbar = () => {
    const location = useLocation();
    const { account, isConnected, isConnecting, connectWallet, disconnectWallet } = useWeb3();
    const [menuOpen, setMenuOpen] = useState(false);

    const NAV_LINKS = [
        { to: "/", label: "Home" },
        { to: "/manual", label: "User Manual" },
        { to: "/about", label: "About" },
    ];

    const shortAddr = (addr) =>
        addr ? `${addr.slice(0, 6)}…${addr.slice(-4)}` : "";

    return (
        <header className="navbar">
            <div className="navbar-inner">
                {/* Logo */}
                <Link to="/" className="navbar-logo" aria-label="PriveX Home">
                    <span className="logo-icon">⬡</span>
                    <span className="logo-text">PriveX</span>
                    <span className="logo-version">3.0</span>
                </Link>

                {/* Desktop nav */}
                <nav className="navbar-links" aria-label="Main navigation">
                    {NAV_LINKS.map((link) => (
                        <Link
                            key={link.to}
                            to={link.to}
                            className={`nav-link ${location.pathname === link.to ? "nav-link--active" : ""}`}
                        >
                            {link.label}
                        </Link>
                    ))}
                </nav>

                {/* Wallet button */}
                <div className="navbar-actions">
                    {isConnected ? (
                        <div className="wallet-connected">
                            <span className="wallet-dot" />
                            <span className="wallet-addr">{shortAddr(account)}</span>
                            <button
                                className="btn-ghost btn-sm"
                                onClick={disconnectWallet}
                                aria-label="Disconnect wallet"
                            >
                                Disconnect
                            </button>
                        </div>
                    ) : (
                        <button
                            id="btn-connect-wallet"
                            className="btn-primary btn-sm"
                            onClick={connectWallet}
                            disabled={isConnecting}
                            aria-label="Connect MetaMask wallet"
                        >
                            {isConnecting ? (
                                <><span className="spinner" style={{ width: 14, height: 14 }} /> Connecting…</>
                            ) : (
                                <><span>🦊</span> Connect Wallet</>
                            )}
                        </button>
                    )}

                    {/* Hamburger */}
                    <button
                        className={`hamburger ${menuOpen ? "open" : ""}`}
                        onClick={() => setMenuOpen(!menuOpen)}
                        aria-label="Toggle menu"
                        aria-expanded={menuOpen}
                    >
                        <span /><span /><span />
                    </button>
                </div>
            </div>

            {/* Mobile menu */}
            {menuOpen && (
                <nav className="mobile-menu" aria-label="Mobile navigation">
                    {NAV_LINKS.map((link) => (
                        <Link
                            key={link.to}
                            to={link.to}
                            className={`mobile-nav-link ${location.pathname === link.to ? "active" : ""}`}
                            onClick={() => setMenuOpen(false)}
                        >
                            {link.label}
                        </Link>
                    ))}
                </nav>
            )}
        </header>
    );
};

export default Navbar;
