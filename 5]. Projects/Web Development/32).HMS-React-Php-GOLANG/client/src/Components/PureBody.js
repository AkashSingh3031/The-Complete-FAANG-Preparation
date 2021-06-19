import React, { Component } from "react";
import { Link } from "react-router-dom";
import admin from "../assets/admin.png";
function PureBody({ role, src, link }) {
	return (
		<div
			style={{
				borderRight: "5px",
				borderStyle: "solid",
				borderColor: "ButtonFace",
				flex: "1",
			}}
		>
			<img width="100%" height="500px" src={src} alt="Admin" />
			<h1>{role}</h1>
			<p>Click Below to Login</p>
			<button
				style={{
					border: "0px",
					backgroundColor: "black",
					color: "white",
					width: "100px",
					height: "50px",
					borderRadius: "5px",
					marginBottom: "20px",
				}}
			>
				<Link style={{ color: "white" }} to={link}>
					Login
				</Link>
			</button>
		</div>
	);
}

export default PureBody;
