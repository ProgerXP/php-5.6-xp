<?php
$res = 0;
echo "Testing mysql: ";
if (isFunctionOK("mysql_connect") && isFunctionOK("mysql_close"))
{
	mysql_errno();
	$res = 1;
}
showResult($res);
?>