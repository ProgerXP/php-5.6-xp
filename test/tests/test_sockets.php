<?php
$res = 0;
echo "Testing sockets: ";
if (isFunctionOK("socket_accept") && isFunctionOK("socket_close"))
{
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	socket_set_nonblock($socket);
	$res = 1;
}
showResult($res);
?>