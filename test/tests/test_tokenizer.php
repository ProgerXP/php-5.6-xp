<?php
$res = 0;
echo "Testing tokenizer: ";
if (isFunctionOK("token_get_all") && isFunctionOK("token_name"))
{
	$code = '<?php echo "Hello World!"; ?>';
	$tokens = token_get_all($code);
	$res = 1;
}
showResult($res);
?>