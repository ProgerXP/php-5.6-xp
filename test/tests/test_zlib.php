<?php
$res = 0;
echo "Testing zlib: ";
if (isFunctionOK("zlib_get_coding_type") && isFunctionOK("gztell") && isFunctionOK("gzwrite"))
{
	zlib_get_coding_type();
	$res = 1;
}
showResult($res);
?>