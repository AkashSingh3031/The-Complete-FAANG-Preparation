import React from "react";
import axios from "axios";
import { Switch, Route, Redirect } from "react-router-dom";
import { Row, Col, Form } from "reactstrap";
import background from "../../assets/background.svg";
import Header from "../header";
import patient from "../../assets/patient.jpg";
import LogIn from "../loginIn";
import SecNavBar from "./secNavBar";
import LoginNav from "../LoginNav";
import PatientRoutes from "../../Routes/patientRoutes";
import LoginCard from "../LoginCard";
import jwt from "jwt-decode";
import Cookies from "js-cookie";
class PatientLogin extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			email: "",
			password: "",
			role: "patient",
			patient_id: "",
			error: "",
		};
		this.handleSubmit = this.handleSubmit.bind(this);
	}

	async handleSubmit(childEmail, childPswrd) {
		await this.setState({ email: childEmail, password: childPswrd });
		axios.post("http://localhost:12347/login", this.state).then((res) => {
			console.log(res);
			if (res.data.token) {
				// sessionStorage.setItem("token", res.data.token);
				Cookies.set("token", res.data.token);
				// sessionStorage.setItem("patientName", jwt(res.data.token).name);
				Cookies.set("patientName", jwt(res.data.token).name);
				// sessionStorage.setItem("patient_id", jwt(res.data.token).Id);
				Cookies.set("patient_id", jwt(res.data.token).Id);
				// sessionStorage.setItem("auth", jwt(res.data.token).auth);
				Cookies.set("auth", jwt(res.data.token).auth);

				// 	sessionStorage.setItem(
				// 		"patientName",
				// 		res.data.patient_data.patient_name
				// 	);
				// sessionStorage.setItem("patientEmail", res.data.email)
				Cookies.set("patientEmail", res.data.email);
				// 	sessionStorage.setItem(
				// 		"patientContact",
				// 		res.data.patient_data.phone
				// 	);
				// 	sessionStorage.setItem(
				// 		"patient_id",
				// 		res.data.patient_data.patient_id
				// 	);
				// 	sessionStorage.setItem(
				// 		"patient_email",
				// 		res.data.patient_data.email
				// 	);
				// 	this.setState({ patientredirectReq: true });
			} else {
				console.log(res);
				alert(res.data.message);
			}
		});
	}
	render() {
		if (Cookies.get("auth")) {
			return (
				<div>
					<SecNavBar
						data="patientData"
						name="patientName"
						link="/patientLogin"
					/>
					<Header msg={Cookies.get("patientName")} />
					<PatientRoutes />
				</div>
			);
		}
		return (
			<div style={{ backgroundImage: `url(${background})` }}>
				<div>
					<Switch>
						<Route exact path="/patientLogin">
							<LoginNav />
							<Row mt="7">
								<LoginCard src={patient} msg="Patient" />
								<Col md="6">
									<Form className="DocForm">
										<LogIn fun={this.handleSubmit} />
									</Form>
								</Col>
							</Row>
						</Route>
						<Route>
							<Redirect to="/patientLogin" />
						</Route>
					</Switch>
				</div>
			</div>
		);
	}
}
export default PatientLogin;
