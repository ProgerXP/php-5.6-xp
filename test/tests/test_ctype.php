<?php
$res = 0;
echo "Testing ctype: ";
if (isFunctionOK("ctype_alnum") && isFunctionOK("ctype_alpha") && isFunctionOK("ctype_cntrl"))
{
	$number = ctype_alnum('AbCd1zyZ9');
	$res = 1;
}
showResult($res);
?>