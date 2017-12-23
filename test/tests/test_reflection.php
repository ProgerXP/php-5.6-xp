<?php
$res = 0;
echo "Testing reflection: ";
if (isClassOK("ReflectionClass"))
{
	$r = new ReflectionClass('Exception');
	$res = 1;
}
showResult($res);
?>