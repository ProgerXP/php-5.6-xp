<?php
$res = 0;
echo "Testing xmlwriter: ";
if (isClassOK("XMLWriter"))
{
$writer = new XMLWriter();  
$writer->openURI('php://temp');  
$writer->startDocument('1.0','UTF-8');  
$writer->setIndent(4);   
$writer->startElement('chart');  
   $writer->writeAttribute('lowerLimit', '0');  
   $writer->writeAttribute('upperLimit', '100');  
   $writer->writeAttribute('caption', 'Revenue');  
   $writer->writeAttribute('subcaption', 'US $ (1,000s)');  
   $writer->writeAttribute('numberPrefix', '$');  
   $writer->writeAttribute('numberSuffix', 'K');  
   $writer->writeAttribute('showValue', '1');  
   $writer->startElement('colorRange');  
      $writer->startElement('color');  
         $writer->writeAttribute('minValue', '0');  
         $writer->writeAttribute('maxValue', '50'); 
         $writer->writeAttribute('color', 'A6A6A6'); 
      $writer->endElement();    
      $writer->startElement('color');  
         $writer->writeAttribute('minValue', '50');  
         $writer->writeAttribute('maxValue', '75'); 
         $writer->writeAttribute('color', 'CCCCCC'); 
      $writer->endElement();  
      $writer->startElement('color');  
         $writer->writeAttribute('minValue', '75');  
         $writer->writeAttribute('maxValue', '100'); 
         $writer->writeAttribute('color', 'E1E1E1'); 
      $writer->endElement();  
   $writer->endElement();  
   $writer->writeElement('value','78.9');  
   $writer->writeElement('target','78.9');  
$writer->endElement();  
$writer->endDocument();   
$writer->flush();
	$res = 1;
}
showResult($res);
?>