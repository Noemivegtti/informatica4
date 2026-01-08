<?php
// Connessione al database
$conn = new mysqli("localhost", "root", "", "gestione_studenti");

// Controllo connessione
if ($conn->connect_error) {
    die("Connessione fallita: " . $conn->connect_error);
}

// Dati dello studente da inserire
$nome = "Mari";
$cognome = "Rossi";
$data_nascita = "2005-04-10";
$email = "mari.rossi@example.com";

// Query SQL con placeholder
$sql = "INSERT INTO studenti (nome, cognome, data_nascita, email) VALUES (?, ?, ?, ?)";

// Preparazione della query
$stmt = $conn->prepare($sql);

// Associazione dei parametri
// "ssss" significa che stiamo passando 4 stringhe
$stmt->bind_param("ssss", $nome, $cognome, $data_nascita, $email);

// Esecuzione
if ($stmt->execute()) {
    echo "Studente inserito con successo! ID generato: " . $stmt->insert_id;
} else {
    echo "Errore durante l'inserimento: " . $stmt->error;
}

// Chiusura statement e connessione
$stmt->close();
$conn->close();
?>