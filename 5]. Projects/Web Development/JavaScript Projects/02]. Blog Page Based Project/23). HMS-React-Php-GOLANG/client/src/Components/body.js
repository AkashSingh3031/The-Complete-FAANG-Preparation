import {
	Col,
	Card,
	CardImg,
	CardText,
	CardBody,
	CardTitle,
	Button,
} from "reactstrap";
import { Link } from "react-router-dom";
function Body({ role, src, link }) {
	return (
		<Col sm="12" md="4">
			<Card>
				<CardImg top width="10%" src={src} alt="Card image cap" />
				<CardBody>
					<CardTitle tag="h1">{role}</CardTitle>
					<CardText>Click below to Login</CardText>
					<Button style={{ backgroundColor: "#343a40" }}>
						<Link style={{ color: "white" }} to={link}>
							Login
						</Link>
					</Button>
				</CardBody>
			</Card>
		</Col>
	);
}
export default Body;
