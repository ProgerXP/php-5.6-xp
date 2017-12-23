<?php
$res = 0;
echo "Testing date: ";
if (isFunctionOK("date") && isFunctionOK("idate") && isFunctionOK("gmdate") && isFunctionOK("strtotime") && isFunctionOK("mktime"))
{
	$dt = new DateTime("2015-11-01 00:00:00", new DateTimeZone("America/New_York"));
	$dt->format("Y-m-d H:i:s P");
	$dt->add(new DateInterval("PT3H"));
	$dt->format("Y-m-d H:i:s P");

	date_default_timezone_set('UTC');
	// Prints something like: Monday
	date("l");
	// Prints something like: Monday 8th of August 2005 03:12:46 PM
	date('l jS \of F Y h:i:s A');
	// Prints: July 1, 2000 is on a Saturday
	"July 1, 2000 is on a " . date("l", mktime(0, 0, 0, 7, 1, 2000));
	/* use the constants in the format parameter */
	// prints something like: Wed, 25 Sep 2013 15:28:57 -0700
	date(DATE_RFC2822);
	// prints something like: 2000-07-01T00:00:00+00:00
	date(DATE_ATOM, mktime(0, 0, 0, 7, 1, 2000));
	$res = 1;
}
showResult($res);
?>