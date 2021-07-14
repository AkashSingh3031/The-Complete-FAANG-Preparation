<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require 'db-connection.php';
$data=json_decode(file_get_contents("php://input"));

$result=mysqli_query($db_conn,"select * from patient where patient.patient_id='$data->patient_id'");
$rowCount=$result->num_rows;
if($rowCount>0){
$all_users = mysqli_fetch_all($result, MYSQLI_ASSOC);
echo json_encode(["user_data"=>$all_users]);

}
else{
echo '{"error":"User Doesnot Exist"}';

}
// echo
?>