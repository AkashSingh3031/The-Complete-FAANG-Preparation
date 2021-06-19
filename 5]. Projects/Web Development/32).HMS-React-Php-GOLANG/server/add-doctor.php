<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require "db-connection.php";
$data=json_decode(file_get_contents("php://input"));
if (
    isset($data->name)
    && isset($data->email)
    && !empty(trim($data->name))
    && !empty(trim($data->email))
    ){
$username = mysqli_real_escape_string($db_conn, trim($data->name));
$useremail = mysqli_real_escape_string($db_conn, trim($data->email));
if (!preg_match("/^[a-zA-Z-' ]*$/",$data->name)) {
    echo "Invalid Name";

}
else{
if (!filter_var($useremail, FILTER_VALIDATE_EMAIL)) {
  echo "Invalid email format";
}
else{
    $uppercase = preg_match('@[A-Z]@', $data->password);
    $lowercase = preg_match('@[a-z]@', $data->password);
    $number    = preg_match('@[0-9]@', $data->password);
    $specialChars = preg_match('@[^\w]@', $data->password);

if(!$uppercase || !$lowercase || !$number || !$specialChars || strlen($data->password) < 8) {
    echo 'Invalid Password';
}
else{
    $checkDoc=mysqli_query($db_conn,"Select * from doctor where email='$useremail'");
    $checkRow=mysqli_num_rows($checkDoc);
    if($checkRow>0){
        echo 'Doctor Already Registered';
    }
    else{
    $insertPatient = mysqli_query($db_conn, "INSERT INTO `doctor`(`doc_name`, `email`, `password`, `address`, `phone`, `department`) VALUES('$username','$useremail','$data->password','$data->address','$data->phone','$data->department')");
    if($insertPatient){
        echo "Success";
    }
    else{
        echo "Failed";
    }
}
}
}
    }
}
    else{
        echo "Mandatory Fields are Empty";
    }
?>