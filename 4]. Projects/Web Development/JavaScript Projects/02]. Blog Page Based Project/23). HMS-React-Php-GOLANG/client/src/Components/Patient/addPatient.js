import { Row, Col, Nav, NavItem, NavLink } from "reactstrap";
import { Link } from "react-router-dom";
import React from "react";
import SignUp from "./signUp";
class AddPatientForm extends React.Component {
	render() {
		return (
			<div>
				<Nav tabs>
					<NavItem>
						<NavLink active>
							<Link to="/adminLogin/addPatient">Add Patient</Link>
						</NavLink>
					</NavItem>
					<NavItem>
						<NavLink>
							<Link to="/adminLogin/patientList">
								Patient List
							</Link>
						</NavLink>
					</NavItem>
				</Nav>
				<Row>
					<Col sm="2"></Col>
					<Col>
						<SignUp />
					</Col>
					<Col sm="4"></Col>
				</Row>
			</div>
		);
	}
}
export default AddPatientForm;
