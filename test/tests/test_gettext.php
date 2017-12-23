<?php
$res = 0;
echo "Testing gettext: ";
if (isFunctionOK("bindtextdomain") && isFunctionOK("gettext") && isFunctionOK("bindtextdomain"))
{
	putenv('LC_ALL=de_DE');
	setlocale(LC_ALL, 'de_DE');
	// Specify location of translation tables
	bindtextdomain("myPHPApp", "./locale");
	$res = 1;
}
showResult($res);
?>