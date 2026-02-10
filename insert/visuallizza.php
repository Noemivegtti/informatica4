<?php
include "database.php";

// Gestione ricerca per cognome
$cognome = "";
if (isset($_GET["cognome"]) && $_GET["cognome"] != "") {
    $cognome = mysqli_real_escape_string($conn, $_GET["cognome"]);
    $sql = "SELECT * FROM studenti WHERE cognome='$cognome'";
} else {
    $sql = "SELECT * FROM studenti";
}

$risultato = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Visualizza Studenti</title>
</head>
<body>
    <div class="container">
        <h2>Elenco Studenti</h2>

        <form method="GET" action="visualizza_studenti.php">
            Cerca per cognome:
            <input type="text" name="cognome" value="<?php echo htmlspecialchars($cognome); ?>">
            <input type="submit" value="Cerca">
        </form>

        <table border="1" cellpadding="5" cellspacing="0">
            <tr>
                <th>Nome</th>
                <th>Cognome</th>
                <th>Email</th>
            </tr>

            <?php
            while ($row = mysqli_fetch_assoc($risultato)) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars($row["nome"]) . "</td>";
                echo "<td>" . htmlspecialchars($row["cognome"]) . "</td>";
                echo "<td>" . htmlspecialchars($row["email"]) . "</td>";
                echo "</tr>";
            }
            ?>
        </table>

        <a href="inserisci_stud.html">Torna alla home</a>
    </div>
</body>
</html>
