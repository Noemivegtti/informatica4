<?php
$host = "localhost";
$user = "root";
$password = "";
$db = "gestione_scuola";

$conn = mysqli_connect($host, $user, $password, $gestione_scuola);

if (!$conn) {
    die("Connessione fallita");
    }
    ?>