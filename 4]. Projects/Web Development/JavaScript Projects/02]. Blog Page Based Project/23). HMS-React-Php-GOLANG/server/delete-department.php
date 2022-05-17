<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require "db-connection.php";
$data=json_decode(file_get_contents("php://input"));

$insertPatient = mysqli_query($db_conn, "DELETE FROM `department` where dept_id='$data->dept_id'");
if($insertPatient){
echo "Success";
}
else{

echo "Failed";
}
?>