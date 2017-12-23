<?php
$res = 0;
echo "Testing sqlite3: ";
if (isClassOK("SQLite3") && isClassOK("SQLite3Stmt") && isClassOK("SQLite3Result"))
{
	$res = 1;
}
showResult($res);
?>