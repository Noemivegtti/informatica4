#include <stdio.h>

int main
 {
    
    if (argc != 3)  // Controllo del numero di argomenti
    {                       
        printf("Uso corretto: %s <file_src> <file_dst>\n", argv[0]);
        return 1;
    }

    
    FILE *file_src = fopen(argv[1], "r");             // Apertura del file sorgente in modalità lettura

    if (file_src == NULL) 
    {
        printf("Errore nell'apertura del file sorgente %s.\n", argv[1]);
        return 1;
    }

    FILE *file_dst = fopen(argv[2], "w");           // Apertura del file destinazione in modalità scrittura

    if (file_dst == NULL) 
    {
        printf("Errore nell'apertura del file destinazione %s.\n", argv[2]);
        fclose(file_src);
        return 1;
    }

    
    int ch;          // Lettura e scrittura carattere per carattere
    while ((ch = fgetc(file_src)) != EOF) {
        fputc(ch, file_dst);
    }

    
    fclose(file_src);               // Chiusura dei file
    fclose(file_dst);

    printf("Copia completata con successo da %s a %s.\n", argv[1], argv[2]);
    return 0;
}
