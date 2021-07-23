import axios from "axios";
import Cookies from "js-cookie";
import React from "react";
import { Input, FormGroup, Label, Button, Form, Row, Col } from "reactstrap";
class GetProfile extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			Name: "",
			Email: "",
			Address: "",
			Phone: "",
			Id: "",
			Role: "admin",
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
					Id: this.props.id,
					Role: this.state.Role,
				},
				{ headers: headers }
			)
			.then((res) => {
				console.log(res.data);
				this.setState({
					Id: this.props.id,
					Name: res.data.Name,
					Email: res.data.Email,
					Address: res.data.Address,
					Phone: res.data.Phone,
				});
			});
	}
	handleSubmit(e) {
		e.preventDefault();
		alert("Submitted");
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
				<Row>
					<Col md="3"></Col>
					<Col>
						<h1 style={{ fontFamily: "cursive" }}>Edit Profile</h1>
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
					<Col sm="4"></Col>
				</Row>
			</div>
		);
	}
}
export default GetProfile;
