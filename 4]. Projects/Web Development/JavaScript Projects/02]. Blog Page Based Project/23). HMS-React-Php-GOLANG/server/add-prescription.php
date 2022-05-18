<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require "db-connection.php";
$data=json_decode(file_get_contents("php://input"));
if (
    isset($data->prescription)
    && !empty(trim($data->prescription))
  
    ){
        $insert= mysqli_query($db_conn, "update appointment set prescription='$data->prescription' where apid='$data->apid'");
        if($insert){
            echo "Added Succesfully";
        }
        else{
            echo "Failed";
        }
}
else{
  echo "Empty Prescription";
}
?>