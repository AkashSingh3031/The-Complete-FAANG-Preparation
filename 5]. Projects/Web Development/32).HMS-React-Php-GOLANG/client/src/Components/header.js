import { Row, Col, Jumbotron } from "reactstrap";

function Header({ msg }) {
	// console.log((msg)[3]);
	return (
		<Jumbotron className="header">
			<Row>
				<Col md="12">
					<h1 style={{ fontFamily: "cursive" }}>Welcome!!! {msg}</h1>
				</Col>
			</Row>
		</Jumbotron>
	);
}
export default Header;
