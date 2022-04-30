import { Link } from "react-router-dom";
import { Nav, Navbar, NavbarText, NavItem } from "reactstrap";

export default function LoginNav({ msg }) {
	return (
		<Navbar style={{ backgroundColor: "#242526" }} expand="md">
			<Nav className="mr-auto" navbar>
				<NavItem
					style={{
						color: "white",
						padding: "20px",
						fontSize: "20px",
					}}
				>
					<Link
						style={{ textDecoration: "none", color: "white" }}
						to="/"
					>
						Home
					</Link>
				</NavItem>
			</Nav>

			{msg ? (
				<></>
			) : (
				<NavbarText>
					<Link to="/signUp" style={{ color: "white" }}>
						New User? SignUp!!
					</Link>
				</NavbarText>
			)}
		</Navbar>
	);
}
