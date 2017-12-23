<?php
$res = 0;
echo "Testing xml: ";
if (isFunctionOK("utf8_decode") && isFunctionOK("xml_error_string") && isFunctionOK("xml_parse"))
{
	$xml_parser = xml_parser_create();
	xml_set_element_handler($xml_parser, "startElement", "endElement");
	xml_parser_free($xml_parser);
	$res = 1;
}
showResult($res);
?>