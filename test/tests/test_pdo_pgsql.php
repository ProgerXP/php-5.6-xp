<?php
$res = 0;
echo "Testing test_pdo_pgsql: ";
if (isFunctionOK("pg_connect") && isFunctionOK("pg_close"))
{
	$restore = error_reporting(0);
	$conn = pg_pconnect("dbname=foo");
	pg_end_copy($conn);
	error_reporting($restore);
	$res = 1;
}
showResult($res);
?>