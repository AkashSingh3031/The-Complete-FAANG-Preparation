import React, { useState } from "react";
import { BrowserRouter, Routes, Route, Navigate } from "react-router-dom";
import { useWeb3 } from "./context/Web3Context";
import Navbar from "./components/Navbar";
import Home from "./components/Home";
import Dashboard from "./components/Dashboard";
import UserManual from "./components/UserManual";
import AboutUs from "./components/AboutUs";
import ParticleBackground from "./components/ParticleBackground";
import "./App.css";

function App() {
    const [dashboardOpen, setDashboardOpen] = useState(false);
    const { error } = useWeb3();

    return (
        <BrowserRouter>
            <div className="app-shell">
                <ParticleBackground />
                <Navbar />

                {error && (
                    <div className="global-error-banner">
                        <span>⚠️</span>
                        <span>{error}</span>
                    </div>
                )}

                <main className="app-main">
                    <Routes>
                        <Route
                            path="/"
                            element={<Home onLaunchApp={() => setDashboardOpen(true)} />}
                        />
                        <Route path="/manual" element={<UserManual />} />
                        <Route path="/about" element={<AboutUs />} />
                        <Route path="*" element={<Navigate to="/" replace />} />
                    </Routes>
                </main>

                {dashboardOpen && (
                    <Dashboard onClose={() => setDashboardOpen(false)} />
                )}
            </div>
        </BrowserRouter>
    );
}

export default App;
