<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: GET");
header("Content-Type: application/json; charset=UTF-8");

header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

require 'db-connection.php';
$allFeedbacks = mysqli_query($db_conn, "SELECT * FROM `feedback`");
if (mysqli_num_rows($allFeedbacks) > 0) {
$all_feedbacks = mysqli_fetch_all($allFeedbacks, MYSQLI_ASSOC);
echo json_encode(["success" => 1, "feedbacks" => $all_feedbacks]);
} else {

echo json_encode(["success" => 0]);
}