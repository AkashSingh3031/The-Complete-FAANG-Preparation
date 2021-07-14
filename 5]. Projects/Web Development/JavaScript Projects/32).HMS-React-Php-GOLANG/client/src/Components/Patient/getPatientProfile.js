import axios from "axios";
import Cookies from "js-cookie";
import React, { Component } from "react";
import { Link } from "react-router-dom";
import {
	Button,
	Col,
	NavLink,
	Form,
	FormGroup,
	Input,
	Label,
	Nav,
	NavItem,
	Row,
} from "reactstrap";

class GetPatientProfile extends Component {
	constructor(props) {
		super(props);
		this.state = {
			Id: "",
			Name: "",
			Email: "",
			Address: "",
			Phone: "",
			Role: "patient",
		};
	}
	componentDidMount() {
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.post(
				"http://localhost:12347/getProfile",
				{
					Id: this.props.patient_id,
					Role: this.state.Role,
				},
				{ headers: headers }
			)
			.then((res) => {
				console.log(res.data);
				this.setState({
					Id: this.props.patient_id,
					Name: res.data.Name,
					Email: res.data.Email,
					Address: res.data.Address,
					Phone: res.data.Phone,
				});
			});
	}
	handleSubmit(e) {
		e.preventDefault();
		console.log(this.state.id);
		// alert("Submitted");
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.post("http://localhost:12347/editProfile", this.state, {
				headers: headers,
			})
			.then((res) => {
				console.log(res);
			});
	}
	render() {
		return (
			<div>
				<Nav tabs>
					<NavItem>
						<NavLink>
							<Link to="/patientLogin">Doctor List</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink>
							<Link to="/patientLogin/bookAppointment">
								Book Appointment
							</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink active>
							<Link to="/patientLogin/getPatientProfile">
								Edit Profile
							</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink>
							<Link to="/patientLogin/patientAppointments">
								View Appointments
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Row className="mt-4">
					<Col>
						<h1>Edit Profile</h1>
						<Form>
							<FormGroup>
								<Row mt="3">
									<Col sm="2">
										<Label>Name</Label>
									</Col>
									<Col sm="10">
										<Input
											value={this.state.Name}
											onChange={(e) =>
												this.setState({
													Name: e.target.value,
												})
											}
										/>
									</Col>
								</Row>
							</FormGroup>
							<FormGroup>
								<Row mt="3">
									<Col sm="2">
										<Label>Email</Label>
									</Col>
									<Col sm="10">
										<Input
											value={this.state.Email}
											onChange={(e) =>
												this.setState({
													Email: e.target.value,
												})
											}
										/>
									</Col>
								</Row>
							</FormGroup>
							<FormGroup>
								<Row mt="3">
									<Col sm="2">
										<Label>Phone Number</Label>
									</Col>
									<Col sm="10">
										<Input
											value={this.state.Phone}
											onChange={(e) =>
												this.setState({
													Phone: e.target.value,
												})
											}
										/>
									</Col>
								</Row>
							</FormGroup>
							<FormGroup>
								<Row mt="3">
									<Col sm="2">
										<Label>Adress</Label>
									</Col>
									<Col sm="10">
										<Input
											value={this.state.Address}
											onChange={(e) =>
												this.setState({
													Address: e.target.value,
												})
											}
										/>
									</Col>
								</Row>
							</FormGroup>
							<FormGroup>
								<Button onClick={(e) => this.handleSubmit(e)}>
									Submit
								</Button>
							</FormGroup>
						</Form>
					</Col>
					<Col sm="6"></Col>
				</Row>
			</div>
		);
	}
}

export default GetPatientProfile;
