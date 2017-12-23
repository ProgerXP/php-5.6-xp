<?php
$res = 0;
echo "Testing zip: ";
if (isClassOK("ZipArchive") && isFunctionOK("zip_close") && isFunctionOK("zip_open"))
{
	$zip = new ZipArchive();
	$filename = "./test-qcwe.zip";
	if ($zip->open($filename, ZipArchive::CREATE) !== TRUE)
	{
    		exit("cannot open <$filename>\n");
	}
	$res = 1;
}
showResult($res);
?>