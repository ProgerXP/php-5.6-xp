<?php
$res = 0;
echo "Testing xmlreader: ";
if (isClassOK("XMLReader"))
{
	$xml = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>".
"<products>".
"    <last_updated>2009-11-30 13:52:40</last_updated>".
"    <product>".
"        <element_1>foo</element_1>".
"        <element_2>foo</element_2>".
"        <element_3>foo</element_3>".
"        <element_4>foo</element_4>".
"    </product>".
"    <product>".
"        <element_1>bar</element_1>".
"        <element_2>bar</element_2>".
"        <element_3>bar</element_3>".
"        <element_4>bar</element_4>".
"    </product>".
"</products>";
	$r = new XMLReader;
	$r->xml($xml);
	while ($r->read() && $r->name !== 'product');
	$res = 1;
}
showResult($res);
?>