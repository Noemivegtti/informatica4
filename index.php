<?php
//Verifica se primo accesso (se non esiste il campo $_POST)
if (isset($_POST['s']))
{
    echo "Nome: " . $_POST['username'] . "<BR>";
    echo "Casella di posta: " . $_POST['email'] . "<BR>";
}
else
{
    //POSTBACK: variabile d'ambiente che reindirizza ACTION a se stessa
    echo "<FORM ACTION=" . $_SERVER['PHP_SELF'] . " METHOD=POST>";
    echo "<TABLE><TR><TD>Nome utente:
          <TD><INPUT TYPE=text NAME=username><BR>
          <TR><TD>Email:
          <TD><INPUT TYPE=text NAME=email><BR>
          </TABLE><INPUT TYPE=submit NAME=s VALUE='invia->'></FORM>";
}
?>