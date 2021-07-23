import axios from "axios";
import React, { Component } from "react";
import { Link } from "react-router-dom";
import { Nav, NavItem, NavLink, Table } from "reactstrap";
import Cookies from "js-cookie";
class PatientAppointments extends Component {
	constructor(props) {
		super(props);
		this.state = {
			appointments: [],
		};
	}
	async componentDidMount() {
		const headers = {
			authorization: Cookies.get("token"),
		};
		await axios
			.post(
				"http://localhost:12347/patientAppointment",
				{
					Email: Cookies.get("patientEmail"),
				},
				{ headers: headers }
			)
			.then((res) => {
				console.log(res);
				this.setState({ appointments: res.data });
			});
		console.log(this.state);
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
						<NavLink>
							<Link to="/patientLogin/getPatientProfile">
								Edit Profile
							</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink active>
							<Link to="/patientLogin/patientAppointments">
								View Appointments
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Table>
					<thead>
						<th>Application Id</th>
						<th>Name</th>
						<th>Email</th>
						<th>Prescription</th>
					</thead>
					<tbody>
						{this.state.appointments.map((appointment) => {
							return (
								<tr>
									<td>{appointment.Apid}</td>
									<td>{appointment.Name}</td>
									<td>{appointment.Email}</td>
									<td>{appointment.Prescription}</td>
								</tr>
							);
						})}
					</tbody>
				</Table>
			</div>
		);
	}
}

export default PatientAppointments;
