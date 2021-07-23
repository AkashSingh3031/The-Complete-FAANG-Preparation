import {
	Row,
	Col,
	Nav,
	NavItem,
	NavLink,
	Form,
	FormGroup,
	Label,
	Input,
	Button,
} from "reactstrap";
import { Link } from "react-router-dom";
import React from "react";
import axios from "axios";
import Cookies from "js-cookie";
class AddDepartmentForm extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			id: "",
			name: "",
			description: "",
		};
		this.handleSubmit = this.handleSubmit.bind(this);
	}
	handleSubmit(e) {
		console.log(this.state);

		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.post(
				"http://localhost:12347/addDepartment",
				{
					DeptName: this.state.name,
					DeptDescription: this.state.description,
				},
				{
					headers: headers,
				}
			)
			.then((res) => {
				console.log(res);
				if (res.data.isError) {
					alert(res.data.message);
				} else {
					alert(res.data);
				}
			});
	}
	render() {
		return (
			<div>
				<Nav tabs>
					<NavItem>
						<NavLink active>
							<Link to="#">Add Department</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink>
							<Link to="/adminLogin/deplist">
								Department List
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Form>
					<FormGroup>
						<Row className="mt-4">
							<Col md="2">
								<Label for="depName">Department Name</Label>
							</Col>
							<Col md="6">
								<Input
									name="depName"
									id="depName"
									type="text"
									onChange={(e) =>
										this.setState({ name: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row className="mt-4">
							<Col md="2">
								<Label for="depDesc">
									Department Description
								</Label>
							</Col>
							<Col md="6">
								<Input
									name="depDesc"
									id="depDesc"
									type="text"
									onChange={(e) =>
										this.setState({
											description: e.target.value,
										})
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<Button
						color="primary"
						onClick={(e) => this.handleSubmit(e)}
					>
						Submit
					</Button>
				</Form>
			</div>
		);
	}
}
export default AddDepartmentForm;
