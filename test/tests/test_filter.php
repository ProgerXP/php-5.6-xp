<?php
$res = 0;
echo "Testing filter: ";
if (isFunctionOK("filter_has_var") && isFunctionOK("filter_id") && isFunctionOK("filter_input_array") && isFunctionOK("filter_var"))
{
	$options = array(
    		'options' => array(
        	'default' => 3, // value to return if the filter fails
        	// other options here
        	'min_range' => 0
		),
	    	'flags' => FILTER_FLAG_ALLOW_OCTAL,
	);
	$var = filter_var('0755', FILTER_VALIDATE_INT, $options);
	$res = 1;
}
showResult($res);
?>