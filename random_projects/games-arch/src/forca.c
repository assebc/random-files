#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h> 

#include "rooster.h"

void visualizacao(char viz[]) {
    int i;
    for (i = 0; i < strlen(viz); i++) {
        printf("%c ", viz[i]);

    }
    printf("\n\n");
}


char * randomword(){
    int index = generateRandomInt2(0,997955);
    int i = 0;
    char line[1024];
    char * result = NULL;
    FILE * f = fopen("words.txt", "r");
    while(fgets(line,1024,f) != NULL){
        if (i == index){
            result = fgets(line,1024,f);
            if (strlen(result)>20) randomword();
            else break;
        }
        i++; 
               
    }
    
    return result;
}


int forca(){ // main function

    int acertos = 0, erros = 0;
    char * secreta = NULL, resposta[39], letra;
    int i, flag, max = 1;
    
    secreta = randomword();
    max = strlen(secreta);
    for (i = 0; i < max; i++) resposta[i] = '_';

    while (erros < 6) {
        clear_console();
        printf("************ Jogo da Forca ************\n");
        printf("Limite de 6 erros. Palavra de até 20 letras\n\n");
        printf("Acertos = %3d\n", acertos);
        printf("Erros   = %3d\n", erros);
        putchar('\n');
        visualizacao(resposta);
        printf("Digite uma letra ou tente adivinhar a palavra: ");
        scanf(" %c", &letra);
        flag = 0;
        for (i = 0; i < max; i++) {
            if (toupper(secreta[i]) == toupper(letra)) {
                flag = 1;
                secreta[i] = '_';
                resposta[i] = letra;
                acertos++;
            }
        }
        if (!flag) erros++;
        if (acertos == max) {
            clear_console();
            printf("\n\n\n");
            visualizacao(resposta);
            printf("Acertou todas as letras em %d Tentativas!!  \n\n", erros + acertos);
            sleep(2);
            break;  // sai do opp
        }
        else {
            if (erros == 6) {
                clear_console();
                printf("Você perdeu!!\n\n");
                sleep(2);
                break;  // sai do opp
            }
        }


    } 

    return (acertos+erros);
}
