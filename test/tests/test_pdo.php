<?php
$res = 0;
echo "Testing pdo: ";
if (isClassOK("PDO"))
{
	try
	{
		$dbh = new PDO('mysql:host=localhost;dbname=test', "user", "pass");
	   	$dbh = null;
	}
	catch (PDOException $e)
	{
	   	$e->getMessage();
	}
	$res = 1;
}
showResult($res);
?>