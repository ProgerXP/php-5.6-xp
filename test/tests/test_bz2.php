<?php
$res = 0;
echo "Testing bz2: ";
if (isFunctionOK("bzclose") && isFunctionOK("bzcompress") && isFunctionOK("bzdecompress"))
{
	$restore = error_reporting(0);
	$file = "/tmp/foo.bz2";
	$bz = bzopen($file, "r");
	bzclose($bz);
	error_reporting($restore);
	$res = 1;
}
showResult($res);
?>