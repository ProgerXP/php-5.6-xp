<?php
$res = 0;
echo "Testing libxml: ";
if (isFunctionOK("libxml_clear_errors") && isFunctionOK("libxml_get_errors"))
{
	libxml_clear_errors();
	$res = 1;
}
showResult($res);
?>