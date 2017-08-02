<style>* {font-family:monospace;}</style>
<?php 

$analyseFile = fopen("kun.mol2","r") or die("Unable to open file");
$line = 1;
$linecontent = "";
$filecontent = array();
$resultarray = array();
$statistic = array();

while(!feof($analyseFile)||($linecontent)) {
$linecontent = fgets($analyseFile);
//remove multiple spaces
$linecontent = trim($linecontent);
$linecontent = preg_replace('!\s+!', ' ', $linecontent);
$linearray = explode(" ",$linecontent);
//remove empty strings
$linecontent = array_filter($linearray);
//wrzuć do tablicy

if(count($linearray)==9) 
	{
	//echo $linearray[7].'<br />';
	array_push($filecontent,$linearray[7]);
	}
}
//usun duplikaty
$filecontent = array_unique($filecontent);
//usun cyfry z aminokwasów
foreach($filecontent as $fc) { array_push($resultarray,preg_replace('/[0-9]+/', '', $fc));}
//print_r($lastarray);
//print_r(array_count_values($resultarray));
//print_r(count($resultarray));
$statistic = array_count_values($resultarray);
echo 'ALA:   '.$resultarray["ALA"];
echo 'TOTAL: '.$statistic;
//ala,cys,asp,glu,phe,gly,his,ile,lys,leu,met,asn,pro,gln,arg,ser,thr,val,trp,tyr



fclose($analyseFile);
?>