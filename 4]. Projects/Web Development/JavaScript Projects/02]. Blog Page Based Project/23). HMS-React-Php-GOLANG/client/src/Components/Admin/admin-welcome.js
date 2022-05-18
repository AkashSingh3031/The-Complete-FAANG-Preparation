import React from "react";

import { Switch, Route, Redirect } from "react-router-dom";
import background from "../../assets/background.svg";
import Header from "../header";
import NavBar from "../Navbar";
import axios from "axios";
import admin from "../../assets/admin.png";
import LogIn from "../loginIn";
import AdminRoutes from "../../Routes/adminRoutes";
import LoginNav from "../LoginNav";
import Cookies from "js-cookie";
import PureLoginCard from "../PureLoginCard";
import jwt from "jwt-decode";
class AdminWelcome extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			email: "",
			password: "",
			role: "admin",
			redirectReq: false,
			admin_id: "",
			error: "",
			isOpen: false,
			isActive: "Departments",
		};
		this.handleSubmit = this.handleSubmit.bind(this);
		this.logout = this.logout.bind(this);
	}
	async handleSubmit(childEmail, childPswrd) {
		await this.setState({ email: childEmail });
		await this.setState({ password: childPswrd });
		axios.post("http://localhost:12347/login", this.state).then((res) => {
			console.log(res);

			if (res.data.token) {
				console.log(res.data.token);
				Cookies.set("token", res.data.token);

				var name = jwt(res.data.token).name;
				var id = jwt(res.data.token).Id;
				var auth = jwt(res.data.token).authorized;
				// sessionStorage.setItem("token", res.data.token);
				// sessionStorage.setItem("auth", auth);
				Cookies.set("auth", auth);
				// sessionStorage.setItem("username", name);
				Cookies.set("username", name);
				// sessionStorage.setItem("user_id", id);
				Cookies.set("user_id", id);
				this.setState({ redirectReq: true });
			} else {
				alert(res.data.message);
			}
		});
	}
	logout() {
		// sessionStorage.setItem("userData", "");
		Cookies.remove("userData");
		// sessionStorage.setItem("username", "");
		Cookies.remove("username");
		Cookies.remove("auth");
		// sessionStorage.setItem("auth", "");
		// sessionStorage.setItem("token", "");
		Cookies.remove("token");
		// sessionStorage.clear();
		// sessionStorage.clear();
		this.setState({ redirectReq: false });
		<Redirect to="/adminLogin" />;
	}
	render() {
		if (this.state.redirectToReq || Cookies.get("auth")) {
			return (
				<div>
					<NavBar fun={() => this.logout()} />
					<Header msg={Cookies.get("username")} />
					<AdminRoutes />
				</div>
			);
		}
		return (
			<div
				style={{ backgroundImage: `url(${background})`, zIndex: "-1" }}
			>
				<div>
					<Switch>
						<Route exact path="/adminLogin">
							<LoginNav />
							<div
								className="container"
								style={{ padding: "0px" }}
							>
								{/* <LoginCard src={admin} msg="Admin" /> */}
								<PureLoginCard src={admin} msg="Admin" />
								{/* <div style={{ flex: "1" }}></div> */}
								<div className="DocForm" style={{ flex: "2" }}>
									<LogIn fun={this.handleSubmit} />
								</div>
								<div style={{ flex: "1" }}></div>
							</div>
						</Route>
						<Route>
							<Redirect to="/adminLogin" />
						</Route>
					</Switch>
				</div>
			</div>
		);
	}
}
export default AdminWelcome;
