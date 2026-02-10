<?php
include "database.php";

$nome = $_POST["nome"];
$cognome = $_POST["cognome"];
$email = $_POST["email"];
$data_nascita = $_POST["data_nascita"];

$sql = "INSERT INTO studenti (nome, cognome, email, data_nascita)
        VALUES ('$nome', '$cognome', '$classe', '$data_nascita')";

mysqli_query($conn, $sql);

echo "Studente inserito correttamente<br>";
echo "<a href=' inserimento.html'>Torna alla home</a>";
?>