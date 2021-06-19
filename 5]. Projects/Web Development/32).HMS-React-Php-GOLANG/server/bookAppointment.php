<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require "db-connection.php";
$data=json_decode(file_get_contents("php://input"));
$name = mysqli_real_escape_string($db_conn, trim($data->name));
$email=mysqli_real_escape_string($db_conn,trim($data->email));
$contact=mysqli_real_escape_string($db_conn,trim($data->contact));
$age=mysqli_real_escape_string($db_conn,trim($data->age));
$day=mysqli_real_escape_string($db_conn,trim($data->day));
$speciality=mysqli_real_escape_string($db_conn,trim($data->speciality));
$description=mysqli_real_escape_string($db_conn,trim($data->description));
$id=mysqli_real_escape_string($db_conn,trim($data->id));
// echo "INSERT INTO appointment VALUES('DEFAULT','$name','$email','$contact','$age','$day','$speciality','$description','$id')";
$insertPatient = mysqli_query($db_conn, "INSERT INTO appointment VALUES(DEFAULT,'$name','$email','$contact','$age','$day','$speciality','$description','$id','')");
if($insertPatient){
echo 'Added Succesfully';
}
else{
echo 'Failed';
}
?>