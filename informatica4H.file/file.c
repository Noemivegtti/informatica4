#include <stdio.h>

int main()
{

    FILE* fileMio; 

    char c;

    int contparole = 0;
    int contrighe = 1;
    int contCaratteri = 0;

    
    fileMio = fopen("CIAO.txt", "r"); 

    while(c= fgetc(fileMio)) 
    {  

        if(c == ' ' || c == '\n' || c == '\t') 
        {
            contparole++;

            if(c == '\n') 
            {
                contrighe++;
                  printf(" %d", contrighe);
            }

            if(c != ' ' && c != '\n' && c != '\t' )
            {
                contCaratteri++;
                 printf(" %d", contCaratteri);
            }
        }
    }
    
     printf("quante parole ci sono %d", contparole);
     
     fclose(fileMio);
    

}

