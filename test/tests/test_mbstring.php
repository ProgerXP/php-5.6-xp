<?php
$res = 0;
echo "Testing mbstring: ";
if (isFunctionOK("mb_check_encoding") && isFunctionOK("mb_detect_order") && isFunctionOK("mb_strcut"))
{
	mb_strcut('I_ROHA', 1, 2);
	$res = 1;
}
showResult($res);
?>