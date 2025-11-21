#include <stdio.h>
#define N 10

Studente {                                                                   // Definizione della struttura Studente
    char nome[20];
    char cognome[20];
    int voto;
} typedef struct;

void scriviFile(const char *nomeFile, Studente studenti[], int n) {       // Funzione per scrivere i dati degli studenti in un file
    FILE *file = fopen(nomeFile, "wb");                                  // Apertura del file in modalità scrittura binaria
    if (file == NULL) {                                                 //Controllo se il file è stato aperto correttamente
        printf("Errore nell'apertura del file.\n");                    
        
    }
    fwrite(studenti, sizeof(Studente), n, file);                       // Scrittura dei dati nel file
    fclose(file);                                                     // Chiusura del file
}

int main() {
    Studente studenti[N];                                              
    for (int i = 0; i < N; i++) {
        printf("Inserisci il nome dello studente %d: ", i + 1);
        scanf("%s", studenti[i].nome);
        printf("Inserisci il cognome dello studente %d: ", i + 1);
        scanf("%s", studenti[i].cognome);
        printf("Inserisci il voto dello studente %d: ", i + 1);
        scanf("%d", &studenti[i].voto);
    }

    scriviFile("studenti.dat", studenti, N);
    printf("Dati scritti con successo nel file.\n");

    return 0;
}