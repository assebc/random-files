/*#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

void gotoYX(int x, int y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { x, y });
}
void cores(int l, int f) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), l + (f << 4));
}
void visualizacao(char viz[]) {
    int i;
    cores(15, 0);
    for (i = 0; i < strlen(viz); i++) {
        printf("%c ", viz[i]);
    }
    printf("\n\n");
}
*/
void forca(){ // main function
/*	    do {
        char secreta[20] = { "" },
            resposta[20] = { "" },
            pista[20], letra;
        int  erros = 0, acertos = 0,
            i, j, flag, max = 1;
        setlocale(LC_ALL, "Portuguese");
        cores(14, 0);
        printf("************ Jogo da Forca ************\n");
        printf("************** Jogador 1 **************\n\n");
        printf("Máximo de 20 letras\n\n");
        printf("Digite a palavra secreta: ");
        scanf(" %s", secreta);
        printf("Uma Pista ");
        scanf("%s", pista);
        max = strlen(secreta);
        for (i = 0; i < max; i++)
            resposta[i] = '_';
        system("clear");
        printf("************ Jogo da Forca ************\n");
        printf("************** Jogador 2 **************\n\n");
        printf("Limite de 6 erros. Palavra de até 20 letras\n\n");
        system("clear");
        cores(12, 14);
        printf("\n\t  Pista -> ( %s )   \n", pista);
        Sleep(3000);
        while (erros < 6) {
            cores(11, 0);
            system("clear");
            gotoYX(60, 6);
            printf("Acertos = %3d\n", acertos);
            gotoYX(60, 5);
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
            if (!flag) {
                erros++;
            }
            if (acertos == max) {
                system("clear");
                    printf("\n\n\n");
                visualizacao(resposta);
                cores(12, 15);// cor das letras e cor de fundo da tela
                Beep(1500, 250);// faz um sonzinho
                printf("\n\n  Acertou todas as letras em %d Tentativas . . . !  \n\n", erros + acertos);
                break;  // sai do opp
            }
            else {
                if (erros == 6) {
                    cores(15, 12);
                    printf("\n\nAcertos: %d - Erros: %d\n\n\n", acertos, erros);
                    Sleep(3000);
                    break;  // sai do opp
                }
            }
        }
        gotoYX(60, 6);
        cores(7, 0);
        printf("Acertos = %3d\n", acertos);
        gotoYX(60, 5);
        printf("Erros   = %3d\n", erros);
        gotoYX(20, 15);
    } 
    return (acertos+erros);*/
}
