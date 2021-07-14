import React from "react";

function PureLoginCard({ src, msg }) {
	return (
		<div
			style={{
				flex: "1",
				boxShadow: "0 4px 8px 0 rgba(0,0,0,0.2)",
			}}
		>
			<img src={src} alt="Admin" />
			<h1 style={{ margin: "20px" }}>Hello!! {msg}</h1>
		</div>
	);
}

export default PureLoginCard;
