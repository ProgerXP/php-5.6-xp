<?php
$res = 0;
echo "Testing xmlrpc: ";
if (isFunctionOK("xmlrpc_decode_request") && isFunctionOK("xmlrpc_decode"))
{
	$request = xmlrpc_encode_request("method", array(1,2,3));
	$context = stream_context_create(array('http' => array(
    		'method' => "POST",
    		'header' => "Content-Type: text/xml",
    		'content' => $request
	)));
	//$file = file_get_contents("http://www.example.com/xmlrpc", false, $context);
	//$response = xmlrpc_decode($file);
	//if ($response && xmlrpc_is_fault($response)) {
	//    trigger_error("xmlrpc: $response[faultString] ($response[faultCode])");
	//} else {
	//    print_r($response);
	//}
	$res = 1;
}
showResult($res);
?>