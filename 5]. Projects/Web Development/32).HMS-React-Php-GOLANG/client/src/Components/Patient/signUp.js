import axios from "axios";
import Cookies from "js-cookie";
import React from "react";
import { Button, Col, Form, FormGroup, Input, Label, Row } from "reactstrap";
class SignUp extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			Name: "",
			Email: "",
			Password: "",
			Address: "",
			Phone: "",
			Sex: "",
			BirthDate: "",
			Age: "",
			BloodGroup: "",
		};
		this.handleSubmit = this.handleSubmit.bind(this);
	}
	handleSubmit(e) {
		console.log(this.state);
		const headers = {
			authorization: Cookies.get("token"),
		};
		axios
			.post("http://localhost:12347/addPatient", this.state, {
				headers: headers,
			})
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
				<Form style={{ marginTop: "25px" }}>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Name *</Label>
							</Col>
							<Col sm="10">
								<Input
									type="text"
									onChange={(e) =>
										this.setState({ Name: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Email *</Label>
							</Col>
							<Col sm="10">
								<Input
									type="email"
									onChange={(e) =>
										this.setState({ Email: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Password *</Label>
							</Col>
							<Col sm="10">
								<Input
									type="password"
									onChange={(e) =>
										this.setState({
											Password: e.target.value,
										})
									}
								/>
								<small>
									(Must be atleast of length 8 with one
									Uppercase,one Lowercase,a number and a
									special character)
								</small>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Address</Label>
							</Col>
							<Col sm="10">
								<Input
									type="text"
									onChange={(e) =>
										this.setState({
											Address: e.target.values,
										})
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Phone</Label>
							</Col>
							<Col sm="10">
								<Input
									type="phone"
									onChange={(e) =>
										this.setState({ Phone: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Sex</Label>
							</Col>
							<Col sm="10">
								<Input
									type="text"
									onChange={(e) =>
										this.setState({ Sex: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Birthdate</Label>
							</Col>
							<Col sm="10">
								<Input
									type="text"
									onChange={(e) =>
										this.setState({
											BirthDate: e.target.value,
										})
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Age *</Label>
							</Col>
							<Col sm="10">
								<Input
									type="number"
									onChange={(e) =>
										this.setState({ Age: e.target.value })
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2">
								<Label>Blood Group</Label>
							</Col>
							<Col sm="10">
								<Input
									type="text"
									onChange={(e) =>
										this.setState({
											BloodGroup: e.target.value,
										})
									}
								/>
							</Col>
						</Row>
					</FormGroup>
					<FormGroup>
						<Row>
							<Col sm="2"></Col>
							<Col sm="10">
								<Button onClick={(e) => this.handleSubmit()}>
									Submit
								</Button>
							</Col>
						</Row>
					</FormGroup>
				</Form>
			</div>
		);
	}
}
export default SignUp;
