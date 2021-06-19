<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require 'db-connection.php';
$data=json_decode(file_get_contents("php://input"));
f (
    isset($data->name)
    && isset($data->email)
    && !empty(trim($data->name))
    && !empty(trim($data->email))
    ){
$username = mysqli_real_escape_string($db_conn, trim($data->name));
$useremail = mysqli_real_escape_string($db_conn, trim($data->email));

if (!filter_var($useremail, FILTER_VALIDATE_EMAIL)) {
  echo "Invalid email format";
}
else{
    $uppercase = preg_match('@[A-Z]@', $data->password);
    $lowercase = preg_match('@[a-z]@', $data->password);
    $number    = preg_match('@[0-9]@', $data->password);
    $specialChars = preg_match('@[^\w]@', $data->password);

if(!$uppercase || !$lowercase || !$number || !$specialChars || strlen($password) < 8) {
    echo 'Invalid Password';
}
else{
    $result=mysqli_query($db_conn,"update patient set patient_name='$data->name',email='$data->email',address='$data->address',phone='$data->phone' where patient_id='$data->id'");
    if($result){
        echo "Success";
    }
    else{
        echo "Failed";
    }
}
}
    }
?>