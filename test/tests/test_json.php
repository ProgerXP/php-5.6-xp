<?php
$res = 0;
echo "Testing json: ";
if (isFunctionOK("json_encode") && isFunctionOK("json_decode"))
{
	$arr = array('a' => 1, 'b' => 2, 'c' => 3, 'd' => 4, 'e' => 5);
        json_encode($arr);
	$res = 1;
}
showResult($res);
?>