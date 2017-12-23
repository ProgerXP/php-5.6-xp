<?php
$res = 0;
echo "Testing openssl: ";
if (isFunctionOK("openssl_open") && isFunctionOK("openssl_digest") && isFunctionOK("openssl_error_string"))
{
	openssl_error_string();
	$res = 1;
}
showResult($res);
?>