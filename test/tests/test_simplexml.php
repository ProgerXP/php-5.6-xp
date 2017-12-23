<?php
$res = 0;
echo "Testing simplexml: ";
if (isClassOK("SimpleXMLElement") && isClassOK("SimpleXMLIterator") && isFunctionOK("simplexml_load_file"))
{
	$res = 1;
}
showResult($res);
?>