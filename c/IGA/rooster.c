#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h> 

#include "21.h"

char matriz[3][3];

char verifica()
{
    int i;

    for (i = 0; i < 3; i++){ // verifica as linhas
        if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) return matriz[i][0];
        else if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) return matriz[0][i]; 
       	else if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) return matriz[0][0];
        else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) return matriz[0][2];
    	else if (matriz[0][0] != ' ' && matriz[0][1] != ' ' && matriz[0][2] != ' ' && 
    			 matriz[1][0] != ' ' && matriz[1][1] != ' ' && matriz[1][2] != ' ' && 
    			 matriz[2][0] != ' ' && matriz[2][1] != ' ' && matriz[2][2] != ' ')
    			 return 'v';
   	}
   	return ' ';
}

void inicio()
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) matriz[i][j] = ' ';
}

void mostra_matriz()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("                                     %c | %c | %c ", matriz[i][0], matriz[i][1], matriz[i][2]);
        if (i != 2)
            printf("\n                                    ---|---|---\n");
    }
    printf("\n\n\n");
}

void jogador1()
{
    int x, y;
    printf("\nVez do jogador 1 (input : x y) -> X: \n");
    putchar('\n');
    scanf("%d %d", &x, &y);
    x--;
    y--;

    if (matriz[x][y] != ' ')
    {
        printf("\n\nPosicao invalida, tenta novamente!! \n\n");
        sleep(2);
        clear_console();
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
    }
    else matriz[x][y] = 'X';
}

void jogador2()
{

    mostra_matriz();
    int x, y;

    printf("\nVez do jogador 2 (input : x y) -> O: \n");
    putchar('\n');
    scanf("%d %d", &x, &y);
    x--;
    y--;

    if (matriz[x][y] != ' ')
    {
        printf("\n\nPosicao invalida, tenta novamente!! \n\n");
        sleep(2);
        clear_console();
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        jogador2();
    }
    else matriz[x][y] = 'O';
}

void jogadorCOM()
{
    int x, y;
    x = generateRandomInt(1,3);
    y = generateRandomInt(1,3);
    mostra_matriz();
   

    putchar('\n');

    if (matriz[x][y] != ' ')
    {
        sleep(2);
        clear_console();
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        jogadorCOM();
    }
    else matriz[x][y] = 'O';
}

char * rooster2P(){ // main funtion for 2 players

	
    char fim;
    char * result = malloc(sizeof(char)*5);

    fim = ' ';
    inicio();
    do
    {

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
        fim = verifica();
        clear_console();
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");

        if (fim != ' ')  break;
        jogador2();
        fim = verifica();
        clear_console();

    } while (fim == ' ');

    if (fim == 'X')
    {
    	mostra_matriz();
        printf("\n                         ###   JOGADOR 1 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win1");
    }
    else if (fim == 'O')
    {
    	printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        printf("\n                         ###   JOGADOR 2 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win2");
    }
    else
    {
       	mostra_matriz();
        printf("\n                         ###   EMPATE!!!   ###\n");
        putchar('\n');
        strcpy(result,"draw");
            
    }
    
    // "win1" == player 1 wins "win2" == player 2 wins 
    return result;
}

char * rooster(){ // main function

	char fim;
    char * result = malloc(sizeof(char)*5);

    fim = ' ';
    inicio();
    do
    {

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
        fim = verifica();
        clear_console();

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");

        if (fim != ' ') break;
        jogadorCOM();
        fim = verifica();
        clear_console();

    } while (fim == ' ');

    if (fim == 'X')
    {
        mostra_matriz();
        printf("\n                         ###   JOGADOR 1 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win1");
    }
    else if (fim == 'O')
    {
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        printf("\n                         ###   COMPUTADOR GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win2");
    }
    else
    {
        mostra_matriz();
        printf("\n                         ###   EMPATE!!!   ###\n");
        putchar('\n');
        strcpy(result,"draw");
            
    }

    return result;
}