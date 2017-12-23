<?php
$res = 0;
echo "Testing iconv: ";
if (isFunctionOK("iconv") && isFunctionOK("iconv_get_encoding") && isFunctionOK("iconv_substr"))
{
	$text = "Test text string.";
	iconv("UTF-8", "ISO-8859-1//TRANSLIT", $text);
	$res = 1;
}
showResult($res);
?>