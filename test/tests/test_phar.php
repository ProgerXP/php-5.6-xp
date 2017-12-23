<?php
$res = 0;
echo "Testing phar: ";
if (isClassOK("Phar") && isClassOK("PharData") && isClassOK("PharFileInfo"))
{
	$res = 1;
}
showResult($res);
?>