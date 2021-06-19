import axios from "axios";
import React from "react";
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
class GetPatient extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			patients: [],
			searchTerm: "",
		};
		this.handleDelete = this.handleDelete.bind(this);
	}

	componentDidMount() {
		const headers = {
			authorization: Cookies.get("token"),
		};

		axios
			.get("http://localhost:12347/getPatient", { headers: headers })
			.then((res) => {
				this.setState({ patients: res.data });
				console.log(res);
			});
		console.log(this.state);
	}
	handleDelete(id) {
		console.log(id);
		axios
			.post("http://localhost:12347/deletePatient", {
				id: id,
			})
			.then((res) => {
				alert("User deleted");
				// window.location.reload(false);
			});
	}
	render() {
		console.log(this.state);
		return (
			<div>
				<Nav tabs>
					<NavItem>
						<NavLink>
							<Link to="/adminLogin/addPatient">Add Patient</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink active>
							<Link to="/adminLogin/patientList">
								Patient List
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Row>
					<Col className="mt-2" sm="3"></Col>
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
									<th>Patient Id</th>
									<th>Patient Name</th>
									<th>Patient Email</th>
								</tr>
							</thead>
							<tbody>
								{typeof this.state.patients != undefined ? (
									this.state.patients
										.filter((patient) => {
											if (this.state.searchTerm === "") {
												return patient;
											} else if (
												patient.Name.toLowerCase().includes(
													this.state.searchTerm.toLowerCase()
												)
											) {
												return patient;
											}
										})
										.map((patient) => {
											return (
												<tr>
													<th scope="row">
														{patient.Id}
													</th>
													<td>{patient.Name}</td>
													<td>{patient.Email}</td>
													<td>
														<Button
															id={patient.Id}
															color="danger"
															onClick={(e) =>
																this.handleDelete(
																	e.target.id
																)
															}
														>
															Delete
														</Button>
													</td>
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
export default GetPatient;
