<?php
$res = 0;
echo "Testing gd: ";
if (isFunctionOK("gd_info") && isFunctionOK("getimagesize") && isFunctionOK("getimagesizefromstring"))
{
	gd_info();
	$res = 1;
}
showResult($res);
?>