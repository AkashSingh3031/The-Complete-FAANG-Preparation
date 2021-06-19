import React from "react";

import {
	Button,
	Collapse,
	Nav,
	Navbar,
	NavbarText,
	NavbarToggler,
	NavItem,
} from "reactstrap";
import { NavLink } from "react-router-dom";
class NavBar extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			active: "Department",
		};
	}
	handleClick(e) {
		this.setState({ active: e.target.innerHTML });
	}
	render() {
		return (
			<div>
				<Navbar style={{ backgroundColor: "#242526" }} dark expand="md">
					<NavbarToggler
						onClick={() =>
							this.setState((prevState) => ({
								isOpen: !prevState.isOpen,
							}))
						}
					/>
					<Collapse isOpen={this.state.isOpen} navbar>
						<Nav className="mr-auto" navbar>
							<div className="mynav">
								<NavLink
									active
									activeStyle={{ color: "#61dafb" }}
									exact
									to="/adminLogin"
								>
									Departments
								</NavLink>
							</div>
							<NavItem className="mynav">
								<NavLink
									activeStyle={{ color: "#61dafb" }}
									to="/adminLogin/addDoctor"
								>
									Doctors
								</NavLink>
							</NavItem>
							<NavItem className="mynav">
								<NavLink
									activeStyle={{ color: "#61dafb" }}
									to="/adminLogin/addPatient"
								>
									Patients
								</NavLink>
							</NavItem>
							<NavItem className="mynav">
								<NavLink
									activeStyle={{ color: "#61dafb" }}
									to="/adminLogin/getFeedback"
								>
									View Feedback
								</NavLink>
							</NavItem>
							<NavItem className="mynav">
								<NavLink
									activeStyle={{ color: "#61dafb" }}
									to="/adminLogin/getProfile"
								>
									Profile
								</NavLink>
							</NavItem>
						</Nav>

						<NavbarText>
							<Button
								color="danger"
								onClick={() => this.props.fun()}
							>
								Logout
							</Button>
						</NavbarText>
					</Collapse>
				</Navbar>
			</div>
		);
	}
}
export default NavBar;
