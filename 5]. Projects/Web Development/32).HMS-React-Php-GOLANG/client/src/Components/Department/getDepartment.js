import React from "react";
import axios from "axios";
import {
	Button,
	Col,
	Nav,
	NavItem,
	NavLink,
	Row,
	Input,
	Table,
} from "reactstrap";
import { Link } from "react-router-dom";
import Cookies from "js-cookie";
class GetDepartment extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			depts: [],
			searchTerm: "",
		};
	}
	componentDidMount() {
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.get("http://localhost:12347/getDepartment", { headers: headers })
			.then((resp) => {
				console.log(resp);
				this.setState({ depts: resp.data });
				// // console.log(this.state.users);
			});
	}
	handleDelete(id) {
		console.log(id);
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.post(
				"http://localhost:12347/deleteDepartment",
				{
					DeptId: id,
				},
				{ headers: headers }
			)
			.then((res) => {
				alert("Department deleted");
				window.location.reload(false);
			});
	}
	render() {
		console.log(this.state.users);
		return (
			<div>
				<Nav tabs>
					<NavItem>
						<NavLink>
							<Link to="/adminLogin">Add Department</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink active>
							<Link to="/adminLogin/deplist">
								Department List
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Row>
					<Col className="mt-3" sm="3">
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
									<th>Department Id</th>
									<th>Department Name</th>

									<th style={{ paddingBottom: "25px" }}>
										Department Description
									</th>
								</tr>
							</thead>
							<tbody>
								{this.state.depts
									.filter((dept) => {
										if (this.state.searchTerm === "") {
											return dept;
										} else if (
											dept.deptName
												.toLowerCase()
												.includes(
													this.state.searchTerm.toLowerCase()
												)
										) {
											return dept;
										}
										return "ok";
									})
									.map((dept, index) => {
										return (
											<tr>
												<th scope="row" id={index}>
													{dept.DeptId}
												</th>
												<td>{dept.DeptName}</td>
												<td>{dept.DeptDescription}</td>
												<td>
													<Button
														color="danger"
														id={dept.DeptId}
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
									})}
							</tbody>
						</Table>
					</Col>
				</Row>
			</div>
		);
	}
}
export default GetDepartment;
