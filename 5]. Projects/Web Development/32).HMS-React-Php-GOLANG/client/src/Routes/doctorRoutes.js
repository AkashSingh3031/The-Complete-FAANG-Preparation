import { Route, Switch } from "react-router";
import GetAppointments from "../Components/Doctor/getAppointments";
import GetDocProfile from "../Components/Doctor/getDocProfile";
import Cookies from "js-cookie";
export default function DoctorRoutes() {
	return (
		<Switch>
			<Route exact path="/doctorLogin">
				<GetAppointments />
			</Route>
			<Route exact path="/doctorLogin/editDocProfile">
				<GetDocProfile id={Cookies.get("doc_id")} />
			</Route>
		</Switch>
	);
}
