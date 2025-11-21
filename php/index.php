<?php
$somma=0;
while ($somma<90)
{
   //simulazione lancio dado con numero intero tra 1 e 6
   $NumeroCasuale=rand(1,6); 
   echo "<TABLE><TR><TD>";
   echo "$NumeroCasuale</TD>";
   $somma+= $NumeroCasuale;  
}
echo "</TABLE>";
echo "<BR>La somma risultante �: $somma"; 
?>