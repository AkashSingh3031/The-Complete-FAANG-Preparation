import { Card, CardBody, CardImg, CardTitle, Col } from "reactstrap";

export default function LoginCard({ src, msg }) {
	return (
		<Col sm="12" md="4">
			<Card style={{ "box-shadow": "4px 4px 4px 4px #CCCCCC" }}>
				<CardImg top width="10%" src={src} alt="Card image cap" />
				<CardBody>
					<CardTitle style={{ fontFamily: "cursive" }} tag="h1">
						Hello!! {msg}{" "}
					</CardTitle>
				</CardBody>
			</Card>
		</Col>
	);
}
