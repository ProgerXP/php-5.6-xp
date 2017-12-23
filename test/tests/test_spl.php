<?php
$res = 0;
echo "Testing spl: ";
if (isFunctionOK("class_implements") && isFunctionOK("iterator_count") && isFunctionOK("spl_classes"))
{
	interface foo { }
	class bar implements foo {}
	class_implements(new bar);
	// since PHP 5.1.0 you may also specify the parameter as a string
	class_implements('bar');

	$res = 1;
}
showResult($res);
?>