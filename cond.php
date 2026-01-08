<?php
$conn = new mysqli("localhost", "root", "", "progetto_scuola");

if ($conn->connect_error) {
    die("Connessione fallita: " . $conn->connect_error);
}

$co = $_POST['condizione'];

switch ($co) {
    case 'studenti con voto sufficente':
        $sql = "SELECT s.nome, s.cognome, v.voto
                FROM studenti AS s
                JOIN valutazioni AS v ON s.id_studente = v.id_studente
                WHERE v.voto >= 6";
        break;

    case 'studenti con voto pari a 10':
        $sql = "SELECT s.nome, s.cognome, v.voto
                FROM studenti AS s
                JOIN valutazioni AS v ON s.id_studente = v.id_studente
                WHERE v.voto = 10";
        break;
    case 'Cognome simili':
        $sql = "SELECT * FROM studenti WHERE cognome LIKE '%dsfasfa%'";
        break;
    default:
        die("Condizione non valida.");
}

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table border='1' cellpadding='8' cellspacing='0' style='margin:20px auto; border-collapse:collapse;'>";
    echo "<tr style='background-color:#2980b9; color:white;'>
            <th>Nome</th>
            <th>Cognome</th>
            <th>Voto</th>
          </tr>";

    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row["nome"] . "</td>
                <td>" . $row["cognome"] . "</td>
                <td>" . $row["voto"] . "</td>
              </tr>";
    }

    echo "</table>";
} else {
    echo "<p style='text-align:center; color:red;'>Nessun risultato trovato.</p>";
}



$conn->close();
?>
