import React from "react";
import axios from "axios";
import {
	Table,
	Nav,
	NavItem,
	NavLink,
	Button,
	Row,
	Col,
	Input,
} from "reactstrap";
import Cookies from "js-cookie";
import { Link } from "react-router-dom";
class GetDoctor extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			doctors: [],
			searchTerm: "",
		};
		this.handleDelete = this.handleDelete.bind(this);
	}
	componentDidMount() {
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.get("http://localhost:12347/getDoctor", { headers: headers })
			.then((resp) => {
				console.log("hi");
				console.log(resp);
				this.setState({ doctors: resp.data });
				// console.log(this.state.users);
			});
	}
	handleDelete(id) {
		console.log(id);

		axios
			.post("http://localhost:12347/deleteDoctor", {
				Id: id,
			})
			.then((res) => {
				alert("User deleted");
				window.location.reload(false);
			});
	}
	render() {
		return (
			<div>
				{this.props.msg ? (
					<Nav tabs>
						<NavItem>
							<NavLink active>
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
							<NavLink>
								<Link to="/patientLogin/patientAppointments">
									View Appointments
								</Link>
							</NavLink>
						</NavItem>
					</Nav>
				) : (
					<Nav tabs>
						<NavItem>
							<NavLink>
								<Link to="/adminLogin/addDoctor">
									Add Doctor
								</Link>
							</NavLink>
						</NavItem>
						<NavItem>
							<NavLink active>
								<Link to="/adminLogin/doctorlist">
									Doctor List
								</Link>
							</NavLink>
						</NavItem>
					</Nav>
				)}
				<Row>
					<Col className="mt-2 mr-5" sm="3">
						{" "}
					</Col>
					<Col className="mt-3">
						<Input
							style={{ width: "50%" }}
							placeholder="Search..."
							type="text"
							onChange={(e) =>
								this.setState({ searchTerm: e.target.value })
							}
						/>
						<Table
							striped
							style={{
								width: "50%",
								"box-shadow": "2px 2px 4px 4px #CCCCCC",
								marginTop: "30px",
							}}
						>
							<thead>
								<tr>
									<th>Doctor Id</th>
									<th>Doctor Name</th>
									<th>Department</th>
								</tr>
							</thead>
							<tbody>
								{typeof this.state.doctors != undefined ? (
									this.state.doctors
										.filter((doctor, index) => {
											if (this.state.searchTerm === "") {
												return doctor;
											} else if (
												doctor.Name.toLowerCase().includes(
													this.state.searchTerm.toLowerCase()
												)
											) {
												return doctor;
											}
										})
										.map((doctor, index) => {
											return (
												<tr>
													<th scope="row">
														{doctor.Id}
													</th>
													<td>{doctor.Name}</td>
													<td>{doctor.Department}</td>
													{this.props.msg ? (
														<h1></h1>
													) : (
														<td>
															<Button
																id={doctor.Id}
																color="danger"
																onClick={(e) =>
																	this.handleDelete(
																		e.target
																			.id
																	)
																}
															>
																Delete
															</Button>
														</td>
													)}
												</tr>
											);
										})
								) : (
									<h1>ok</h1>
								)}
							</tbody>
						</Table>
					</Col>
				</Row>
			</div>
		);
	}
}

export default GetDoctor;
