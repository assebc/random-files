#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h> 

#include "rooster.h"

void visualizacao(char viz[]) {
    int i;
    for (i = 0; i < strlen(viz); i++) {
        printf("%c ", viz[i]);
    }
    printf("\n\n");
}
int forca(){ // main function

    int acertos = 0, erros = 0;
    char secreta[20] = { "" }, resposta[20] = { "" }, pista[20], letra;
    int i, flag, max = 1;
    printf("************ Jogo da Forca ************\n");
    printf("************** Jogador 1 **************\n\n");
    printf("Máximo de 20 letras\n\n");
    printf("Digite a palavra secreta: ");
    scanf(" %s", secreta);
    printf("Uma Pista: ");
    scanf("%s", pista);
    max = strlen(secreta);
    for (i = 0; i < max; i++) resposta[i] = '_';
    clear_console();
    printf("************ Jogo da Forca ************\n");
    printf("************** Jogador 2 **************\n\n");
    printf("Limite de 6 erros. Palavra de até 20 letras\n\n");
    printf("\n\t  Pista -> ( %s )   \n", pista);
    sleep(3);
    clear_console();
    while (erros < 6) {
        clear_console();
        printf("Acertos = %3d\n", acertos);
        printf("Erros   = %3d\n", erros);
        visualizacao(resposta);
        printf("Digite uma letra: ");
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
            printf("\n\n  Acertou todas as letras em %d Tentativas . . . !  \n\n", erros + acertos);
            break;  // sai do opp
        }
        else {
            if (erros == 6) {
                clear_console();
                printf("\n\nAcertos: %d - Erros: %d\n\n\n", acertos, erros);
                sleep(2);
                break;  // sai do opp
            }
        }

        printf("Acertos = %3d\n", acertos);
        printf("Erros   = %3d\n", erros);

    } 

    return (acertos+erros);
}
