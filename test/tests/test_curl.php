<?php 
function cURLcheckBasicFunctions() 
{ 
  if( !function_exists("curl_init") && 
      !function_exists("curl_setopt") && 
      !function_exists("curl_exec") && 
      !function_exists("curl_close") ) return false; 
  else return true; 
} 
/* 
* Returns string status information. 
* Can be changed to int or bool return types. 
*/ 
function cURLdownload($url, $file) 
{ 
  if( !cURLcheckBasicFunctions() ) return "UNAVAILABLE: cURL Basic Functions"; 
  $ch = curl_init(); 
  if($ch) 
  { 
    $fp = fopen($file, "w"); 
    if($fp) 
    { 
      if( !curl_setopt($ch, CURLOPT_URL, $url) ) 
      { 
        fclose($fp); // to match fopen() 
        curl_close($ch); // to match curl_init() 
        return "FAIL: curl_setopt(CURLOPT_URL)"; 
      } 
      if( !curl_setopt($ch, CURLOPT_FILE, $fp) ) return "FAIL: curl_setopt(CURLOPT_FILE)"; 
      if( !curl_setopt($ch, CURLOPT_HEADER, 0) ) return "FAIL: curl_setopt(CURLOPT_HEADER)"; 
      if( !curl_exec($ch) ) return "FAIL: curl_exec()"; 
      curl_close($ch); 
      fclose($fp); 
      return "SUCCESS: $file [$url]"; 
    } 
    else return "FAIL: fopen()"; 
  } 
  else return "FAIL: curl_init()"; 
} 
//
// Download from 'example.com' to 'example.txt' 
//echo cURLdownload("http://www.example.com", "example.txt"); 
// Get curl version array
//$version = curl_version();
//
// These are the bitfields that can be used 
// to check for features in the curl build
//$bitfields = Array(
//            'CURL_VERSION_IPV6', 
//            'CURL_VERSION_KERBEROS4', 
//            'CURL_VERSION_SSL', 
//            'CURL_VERSION_LIBZ'
//            );
//foreach($bitfields as $feature)
//{
//   echo $feature . ($version['features'] & constant($feature) ? ' matches' : ' does not match');
//   echo PHP_EOL . "<br/>";
//}
?>
<?php
$res = 0;
echo "Testing curl: ";
if (isFunctionOK("curl_init") 
	&& isFunctionOK("curl_setopt")
	&& isFunctionOK("curl_exec")
	&& isFunctionOK("curl_close"))
{
	$res = 1;
}
showResult($res);
?>