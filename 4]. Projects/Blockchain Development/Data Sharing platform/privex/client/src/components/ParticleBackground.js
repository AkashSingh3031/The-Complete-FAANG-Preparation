import React, { useEffect, useRef } from "react";

const PARTICLES = [
    { size: 500, left: "-10%", top: "-10%", duration: 24, delay: 0, color: "59,130,246" },
    { size: 400, left: "70%", top: "60%", duration: 30, delay: -8, color: "6,182,212" },
    { size: 300, left: "40%", top: "30%", duration: 20, delay: -4, color: "139,92,246" },
];

const ParticleBackground = () => (
    <div aria-hidden="true" style={{ pointerEvents: "none", position: "fixed", inset: 0, zIndex: 0, overflow: "hidden" }}>
        {PARTICLES.map((p, i) => (
            <div
                key={i}
                className="bg-particle"
                style={{
                    width: p.size,
                    height: p.size,
                    left: p.left,
                    top: p.top,
                    background: `radial-gradient(circle, rgba(${p.color},0.18) 0%, transparent 70%)`,
                    animationDuration: `${p.duration}s`,
                    animationDelay: `${p.delay}s`,
                    borderRadius: "50%",
                }}
            />
        ))}
    </div>
);

export default ParticleBackground;
