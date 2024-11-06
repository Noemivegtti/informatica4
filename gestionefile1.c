#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[20];
    char cognome[20];
    int voto;
} Studente;

int contaCognome(const char *nomeFile, const char *cognomeCercato)
 {
    FILE *file = fopen(nomeFile, "rb");                                       // Apertura del file in modalità lettura binaria
    if (file == NULL) {                                                      // Controllo se il file è stato aperto correttamente
        printf("Errore nell'apertura del file.\n");
       
    }

    Studente studente;
    int count = 0;

    while (fread(&studente, sizeof(Studente), 1, file)                         // Lettura dei dati fino alla fine del file
     {                                                                    
        if (studente.cognome, cognomeCercato  == 0 ) 
        {
            count++;                                                          // Incrementa il contatore se il cognome corrisponde
        }
    }

    fclose(file);                                               // Chiusura del file
    return count; 
}

int main() 
{
    char cognomeCercato[20];
    printf("Inserisci il cognome da cercare: ");
    scanf("%s", cognomeCercato);

    int a = contaCognome("studenti.dat", cognomeCercato);
    printf("Il cognome '%s' è presente %d volte nel file.\n", cognomeCercato, a);

    return 0;
}
