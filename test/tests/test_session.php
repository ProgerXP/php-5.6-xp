<?php
$res = 0;
echo "Testing session: ";
if (isFunctionOK("session_abort") && isFunctionOK("session_id") && isFunctionOK("session_unset"))
{
	session_name("WebsiteID");
	$res = 1;
}
showResult($res);
?>