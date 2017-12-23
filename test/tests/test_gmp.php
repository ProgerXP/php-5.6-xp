<?php
$res = 0;
echo "Testing gmp: ";
if (isFunctionOK("gmp_abs") && isFunctionOK("gmp_add"))
{
	$abs1 = gmp_abs("274982683358");
	$res = 1;
}
showResult($res);
?>