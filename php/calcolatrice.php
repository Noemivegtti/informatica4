<?php
// Recupero dati dal form
$nome = $_POST['nome'];
$n1 = $_POST['n1'];
$n2 = $_POST['n2'];
$operazione = $_POST['calcolo'];

$risultato = 0;

switch ($operazione) {
    case "+":
        $risultato = $n1 + $n2;
        break;

    case "-":
        $risultato = $n1 - $n2;
        break;

    case "x":
        $risultato = $n1 * $n2;
        break;

    case "/":
        if ($n2 == 0) {
            $risultato = "Errore: divisione per zero!";
        } else {
            $risultato = $n1 / $n2;
        }
        break;

    default:
        $risultato = "operazione non valida!";
        break;
}

echo "<h1>Risultato</h1>";
echo "<p>Ciao $nome, il risultato della $operazione è: <strong>$risultato</strong></p>";
?>