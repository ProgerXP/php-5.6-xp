<?php
echo "Testing calendar: ";
$res = 0;
if (isFunctionOK("cal_days_in_month"))
{
	$number = cal_days_in_month(CAL_GREGORIAN, 8, 2003); // 31
	//echo "There were {$number} days in August 2003";
	$res = 1;
}
showResult($res);
?>