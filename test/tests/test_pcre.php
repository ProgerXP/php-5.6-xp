<?php
$res = 0;
echo "Testing pcre: ";
if (isFunctionOK("preg_filter") && isFunctionOK("preg_grep") && isFunctionOK("preg_match"))
{
	$subject = "abcdef";
	$pattern = '/^def/';
	preg_match($pattern, $subject, $matches, PREG_OFFSET_CAPTURE, 3);
	$res = 1;
}
showResult($res);
?>