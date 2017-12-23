<?php
$res = 0;
echo "Testing fileinfo: ";
if (isFunctionOK("finfo_buffer") && isFunctionOK("finfo_close") && isFunctionOK("finfo_file") && isFunctionOK("finfo_open"))
{
	$finfo = new finfo(FILEINFO_MIME);
	$res = 1;
}
showResult($res);
?>