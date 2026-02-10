<?php
include "database.php";
?>

<!DOCTYPE html>
<html>
<head>
    <title>Visualizza Studenti</title>
    
</head>
<body>
    <div class="container">
        <h2>Elenco Studenti</h2>

        <form method="GET">
            Cerca per cognome:
            <input type="text" name="cognome" value="<?php echo isset($_GET['cognome']) ? htmlspecialchars($_GET['cognome']) : ''; ?>">
            <input type="submit" value="Cerca">
        </form>

        <table>
            <tr>
                <th>Nome</th>
                <th>Cognome</th>
                <th>data_nascita</th>
            </tr>

            <?php
            if (isset($_GET["cognome"]) && $_GET["cognome"] != "") {
                $cognome = mysqli_real_escape_string($conn, $_GET["cognome"]);
                $sql = "SELECT * FROM studenti WHERE cognome='$cognome'";
            } else {
                $sql = "SELECT * FROM studenti";
            }

            $risultato = mysqli_query($conn, $sql);

            while ($row = mysqli_fetch_assoc($risultato)) {
                echo "<tr>";
                echo "<td>".htmlspecialchars($row["nome"])."</td>";
                echo "<td>".htmlspecialchars($row["cognome"])."</td>";
                echo "<td>".htmlspecialchars($row["email"])."</td>";
                echo "</tr>";
            }
            ?>
        </table>

        <a href="inserisci_stud.html">Torna alla home</a>
    </div>
</body>
</html>