import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React from "react";
import { faPhone, faEnvelope } from "@fortawesome/free-solid-svg-icons";
import { SocialIcon } from "react-social-icons";
function PureFooter() {
	return (
		<div className="container footer">
			<div style={{ flex: "1" }}>
				<h2>Contact Us</h2>
				<ul className="list-unstyled">
					<li>
						<FontAwesomeIcon icon={faPhone} />
						+91 12345678 90
					</li>
					<li>
						<a href="https://gmail.com" style={{ color: "white" }}>
							<FontAwesomeIcon icon={faEnvelope} />{" "}
							contact@global.com
						</a>
					</li>
				</ul>
			</div>
			<div style={{ flex: "1" }}>
				<h2>Address</h2>
				<p>H.NO 123/456</p>
				<p>Heaven street</p>
				<p>London</p>
			</div>
			<div style={{ flex: "1" }}>
				<SocialIcon
					style={{ margin: "5px" }}
					url="https://facebook.com"
					fgColor="white"
				/>
				<SocialIcon
					style={{ margin: "5px" }}
					url="https://twitter.com"
					fgColor="white"
				/>
				<SocialIcon
					style={{ margin: "5px" }}
					url="https://linkedin.com"
					fgColor="white"
				/>
				<SocialIcon
					style={{ margin: "5px" }}
					url="https://github.com/sainikhil1605"
					fgColor="white"
				/>
			</div>
		</div>
	);
}

export default PureFooter;
