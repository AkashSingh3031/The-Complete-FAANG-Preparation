<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: GET");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require 'db-connection.php';
$data=json_decode(file_get_contents("php://input"));
$allUsers = mysqli_query($db_conn, "SELECT * FROM `admin` where user_id=$data-
>userId");
if (mysqli_num_rows($allUsers) > 0) {
$all_users = mysqli_fetch_all($allUsers, MYSQLI_ASSOC);
echo json_encode(["success" => 1, "admin" => $all_users]);
} else {
echo json_encode(["success" => 0]);
}