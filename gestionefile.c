#include <stdio.h>
 Studente{
    char nome[20];
    char cognome[20];
    int voto;
} typedef struct;

void leggiFile(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "rb");                       // Apertura del file in modalità lettura binaria
    if (file == NULL) {                                      // Controllo se il file è stato aperto correttamente
        printf("Errore nell'apertura del file.\n");
        
    }

    Studente studente;
    while (fread(&studente, sizeof(Studente), 1, file)) {              // Lettura dei dati fino alla fine del file
        printf("Nome: %s\n", studente.nome);
        printf("Cognome: %s\n", studente.cognome);
        printf("Voto: %d\n", studente.voto);
        printf("\n");
    }

    fclose(file);             // Chiusura del file
}

int main() {
    leggiFile("studenti.dat");                              // Chiamata alla funzione per leggere e stampare i dati dal file
    return 0;   
}
