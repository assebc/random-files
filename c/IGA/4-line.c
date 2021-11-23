#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h> 

#include "forca.h"


char tabuleiro[6][7];


void inicia_tabuleiro()
{
    int x, y;

    for (x = 0; x < 6; x++)
        for (y = 0; y < 7; y++)
            tabuleiro[x][y] = ' ';
}

void mostra_tabuleiro()
{
    int x;
    printf("    | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("    |---|---|---|---|---|---|---|\n");
    for (x = 1; x < 6; x++) {
        printf("    | %c | %c | %c | %c | %c | %c | %c |\n", tabuleiro[x][0], tabuleiro[x][1], tabuleiro[x][2], tabuleiro[x][3], tabuleiro[x][4], tabuleiro[x][5], tabuleiro[x][6]);
        if (x != 0)
            printf("    |---|---|---|---|---|---|---|\n");
    }
    printf("\n");
}

void print_jogada(int n){
	printf("Jogada %d\n", n);
}

void jogada_Player(int jog)
{
    int x, y, z, w, a, b, c, d, e;

    z = 6;
    w = 6;
    a = 6;
    b = 6;
    c = 6;
    d = 6;
    e = 6;


    for (x = 1; x <= 6; x++) {
        if (tabuleiro[x][0] != ' ') z--;
        if (tabuleiro[x][1] != ' ') w--;
        if (tabuleiro[x][2] != ' ') a--;
        if (tabuleiro[x][3] != ' ') b--;
        if (tabuleiro[x][4] != ' ') c--;
        if (tabuleiro[x][5] != ' ') d--;
        if (tabuleiro[x][6] != ' ') e--;
    }
    
    printf("Selecione a coluna pretendida: ");
    scanf("%d", &y);
    putchar('\n');


    if (y == 1) {
        if (jog == 1) tabuleiro[z][0] = 'X'; else tabuleiro[z][0] = 'O';
    }
    else if (y == 2) {
        if (jog == 1) tabuleiro[w][1] = 'X'; else tabuleiro[w][1] = 'O';
    }
    else if (y == 3) {
        if (jog == 1) tabuleiro[a][2] = 'X'; else tabuleiro[a][2] = 'O';
    }
    else if (y == 4) {
        if (jog == 1) tabuleiro[b][3] = 'X'; else tabuleiro[b][3] = 'O';
    }
    else if (y == 5) {
        if (jog == 1) tabuleiro[c][4] = 'X'; else tabuleiro[c][4] = 'O';
    }
    else if (y == 6) {
        if (jog == 1) tabuleiro[d][5] = 'X'; else tabuleiro[d][5] = 'O';
    }
    else if (y == 7) {
        if (jog == 1) tabuleiro[e][6] = 'X'; else tabuleiro[e][6] = 'O';
    }

    // check if play is valid
    if (z<1 && y == 1) {
        printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (w<1 && y == 2){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (a<1 && y == 3){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (b<1 && y == 4){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (c<1 && y == 5){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (d<1 && y == 6){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (e<1 && y == 7){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    }

    if (y < 1 || y>7) {
        printf("Jogada Invalida, tente novamente.\n");
        putchar('\n');
        jogada_Player(jog);
    }

}

void jogada_COM(int jog)
{	
	int z, w, a, b, c, d, e;

    z = 6;
    w = 6;
    a = 6;
    b = 6;
    c = 6;
    d = 6;
    e = 6;

    int play = generateRandomInt(1,7);

    for (int x = 1; x <= 6; x++) {
        if (tabuleiro[x][0] != ' ') z--;
        if (tabuleiro[x][1] != ' ') w--;
        if (tabuleiro[x][2] != ' ') a--;
        if (tabuleiro[x][3] != ' ') b--;
        if (tabuleiro[x][4] != ' ') c--;
        if (tabuleiro[x][5] != ' ') d--;
        if (tabuleiro[x][6] != ' ') e--;
    }

    if (play == 1) tabuleiro[z][play-1] = 'O';
    else if (play == 2) tabuleiro[w][play-1] = 'O';
    else if (play == 3) tabuleiro[a][play-1] = 'O';
    else if (play == 4) tabuleiro[b][play-1] = 'O';
    else if (play == 5) tabuleiro[c][play-1] = 'O';
    else if (play == 6) tabuleiro[d][play-1] = 'O';
    else if (play == 7) tabuleiro[e][play-1] = 'O';
    
    if (z<1 && play == 1) jogada_COM(jog);
    else if (w<1 && play == 2) jogada_COM(jog);
    else if (a<1 && play == 3) jogada_COM(jog);
    else if (b<1 && play == 4) jogada_COM(jog);
    else if (c<1 && play == 5) jogada_COM(jog);
    else if (d<1 && play == 6) jogada_COM(jog);
    else if (e<1 && play == 7) jogada_COM(jog);

    if (play < 1 || play > 7) jogada_COM(jog);

}


char fim_jogo(int n)                                //objectivo: avaliar se o jogo acabou (4emlinha empate) ou nao
{
    int i;
    int j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {                                   //testar 4 em linha linhas
            if (tabuleiro[i][j] == tabuleiro[i][j + 1] && tabuleiro[i][j + 2] == tabuleiro[i][j + 3] && tabuleiro[i][j] == tabuleiro[i][j + 3] && tabuleiro[i][j] != ' ')
                return tabuleiro[i][j];
        }
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {                                   //testar 4 em linha nas colunas
            if (tabuleiro[j][i] == tabuleiro[j + 1][i] && tabuleiro[j + 2][i] == tabuleiro[j + 3][i] && tabuleiro[j][i] == tabuleiro[j + 2][i] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {                                   //testar 4 em linha diagonais1 começar em cima
            if (tabuleiro[j][i] == tabuleiro[j + 1][i + 1] && tabuleiro[j + 2][i + 2] == tabuleiro[j + 3][i + 3] && tabuleiro[j][i] == tabuleiro[j + 2][i + 2] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 5; j > 2; j--) {                                   //testar 4 em linha diagonais2 começar em baixo
            if (tabuleiro[j][i] == tabuleiro[j - 1][i + 1] && tabuleiro[j - 2][i + 2] == tabuleiro[j - 3][i + 3] && tabuleiro[j][i] == tabuleiro[j - 2][i + 2] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }


    if (n == 42) return 'E';

    return ' ';

}


char * finaliza(int tipo, char venc)
{
    char * result = NULL;
	if (tipo == 1){
		if (venc == 'X'){
			printf("O jogador 1 ganhou, parabéns!!\n");
			putchar('\n');
			result = "win";
		} else if (venc == 'O'){
			sleep(1);
			printf("O jogador 2 ganhou, parabéns!!\n");
			putchar('\n');
			result = "loose";
		} else if (venc == 'E'){
			sleep(1);
			printf("O jogo terminou empatado!!\n");
			putchar('\n');
			result = "draw";
		}

	} else if (tipo == 2){

		if (venc == 'X'){
			printf("O jogador 1 ganhou, parabéns!!\n");
			putchar('\n');
			result = "win";
		} else if (venc == 'O'){
			printf("O computador ganhou, mais sorte para a próxima!!\n");
			putchar('\n');
			result = "loose";
		} else if (venc == 'E'){
			printf("O jogo terminou empatado!!\n");
			putchar('\n');
			result = "draw";
		}
	}

	return result;

}

char * fourline2P(){ // main function for 2 players


	char fim;
	char * result = NULL;
    int n = 0, jog;
    int tipo = 1;

    fim = ' '; jog = 1;
    inicia_tabuleiro();

     if (tipo == 1) {
    	
    	}

    do {
    	clear_console();
    	++n;
    	putchar('\n');
    	print_jogada(n);
    	putchar('\n');
        mostra_tabuleiro();
        if (jog == 1){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 2;
    		clear_console();
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 1;

    	} else if (jog == 2){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 1;
    		clear_console();
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 2;
    	}

        fim = fim_jogo(n);
    } while (fim == ' ');

    result = finaliza(tipo, fim);

    return result;
}


char * fourline(){ // main function

		char fim;
	char * result = NULL;
    int n = 0, jog;
    int tipo = 1;

    fim = ' '; jog = 1;
    inicia_tabuleiro();

     if (tipo == 1) {
    	
    	}

    do {
    	clear_console();
    	++n;
    	putchar('\n');
    	print_jogada(n);
    	putchar('\n');
        mostra_tabuleiro();
        if (jog == 1){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 2;
    		clear_console();
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_COM(jog);
    		jog = 1;

    	} else if (jog == 2){
    		jogada_COM(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 1;
    		clear_console();
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 2;
    	}

        fim = fim_jogo(n);
    } while (fim == ' ');

    result = finaliza(tipo, fim);

    return result;
}