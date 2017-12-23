<?php
$res = 0;
echo "Testing hash: ";
if (isFunctionOK("hash") && isFunctionOK("hash_copy") && isFunctionOK("hash_file"))
{
	hash('ripemd160', 'The quick brown fox jumped over the lazy dog.');
	$res = 1;
}
showResult($res);
?>