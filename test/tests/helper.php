<?php
function isFunctionOK($function_name)
{
	return function_exists($function_name) && is_callable($function_name);
}
function isClassOK($class_name)
{
	return class_exists($class_name);
}
function showResult($res)
{
	echo ($res ? "OK" : "* FAILED *"). PHP_EOL;
}
?>