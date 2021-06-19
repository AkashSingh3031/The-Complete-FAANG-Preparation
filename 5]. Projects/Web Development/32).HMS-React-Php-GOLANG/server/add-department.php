<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=latin");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require "db-connection.php";
$data=json_decode(file_get_contents("php://input"));
$name = mysqli_real_escape_string($db_conn, trim($data->name));
$description = mysqli_real_escape_string($db_conn, trim($data->description));
if (
isset($data->name)
&& isset($data->description)
&& !empty(trim($data->name))
&& !empty(trim($data->description))
){
    if (!preg_match("/^[a-zA-Z-' ]*$/",$data->name)) {
        echo "Invalid Department Name";

    }
      else{
        if (!preg_match("/^[a-zA-Z-' ]*$/",$data->description)) {
            echo "Invalid Description";
          }
        else{
            $checkDoc=mysqli_query($db_conn,"Select * from department where dept_name='$data->name'");
            $checkRow=mysqli_num_rows($checkDoc);
            if($checkRow>0){
                echo 'Department Already Registered';
            }
            else{
            $insertPatient = mysqli_query($db_conn, "INSERT INTO department (dept_name,dept_description) VALUES('$data->name','$data->description')");
            if($insertPatient){
                echo "Success";
            }
            else{
                echo '{"Failed":"0"}';
            }
          }
        }
      }
}
else{
    echo "Department Name or Description is Empty";
}
?>