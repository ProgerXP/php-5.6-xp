<?php
$res = 0;
echo "Testing mcrypt: ";
if (isFunctionOK("mcrypt_cbc") && isFunctionOK("mcrypt_cfb") && isFunctionOK("mcrypt_module_open"))
{
	$td = mcrypt_module_open('des', '', 'ecb', '');
	$res = 1;
}
showResult($res);
?>