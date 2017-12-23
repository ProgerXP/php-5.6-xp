<?php
$res = 0;
echo "Testing mysqli: ";
if (isFunctionOK("mysqli_get_client_info") && isFunctionOK("mysqli_error") && isFunctionOK("mysqli_init"))
{
	mysqli_get_client_version() . mysqli_get_client_info();
	$res = 1;
}
showResult($res);
?>