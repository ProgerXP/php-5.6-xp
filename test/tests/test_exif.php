<?php
$res = 0;
echo "Testing exif: ";
if (isFunctionOK("exif_imagetype") && isFunctionOK("exif_tagname") && isFunctionOK("exif_read_data"))
{
	$res = 1;
}
showResult($res);
?>