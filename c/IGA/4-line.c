#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h> 

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
    for (x = 0; x < 6; x++) {
        printf("    | %c | %c | %c | %c | %c | %c | %c |\n", tabuleiro[x][0], tabuleiro[x][1], tabuleiro[x][2], tabuleiro[x][3], tabuleiro[x][4], tabuleiro[x][5], tabuleiro[x][6]);
        if (x != 0)
            printf("    |---|---|---|---|---|---|---|\n");
    }
    printf("\n");
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

    if (z<1 || w<1 || a<1 || b<1 || c<1 || d<1 || e<1) {
        printf("Jogada invalida!\n");
        jogada_Player(jog);
    }

    if (y < 1 || y>7) {
        printf("Jogada Invalida, tente novamente.\n");
        jogada_Player(jog);
    }

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


}

void jogada_COM(int jog)
{
    int x, y;

    for (x = 0; x < 6; x++)
        for (y = 0; y < 7; y++)
            if (tabuleiro[x][y] == ' ') {
                if (jog == 1) tabuleiro[x][y] = 'X'; else tabuleiro[x][y] = 'O';
                return;
            }
    return ;
}

void jogada(int jog, int tipo)
{

    if (tipo == 1) { 
    	jogada_Player(jog);
    	jogada_Player(jog);
    } else if (tipo == 2) {
    	jogada_Player(jog); 
    	jogada_COM(jog);
	}	

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
			sleep(1);
			printf("O jogador 1 ganhou, parabéns!!\n");
			result = "win";
		} else if (venc == 'O'){
			sleep(1);
			printf("O jogador 2 ganhou, parabéns!!\n");
			result = "loose";
		} else if (venc == 'E'){
			sleep(1);
			printf("O jogo terminou empatado!!\n");
			result = "draw";
		}

	} else if (tipo == 2){

		if (venc == 'X'){
			sleep(1);
			printf("O jogador 1 ganhou, parabéns!!\n");
			result = "win";
		} else if (venc == 'O'){
			sleep(1);
			printf("O computador ganhou, mais sorte para a próxima!!\n");
			result = "loose";
		} else if (venc == 'E'){
			sleep(1);
			printf("O jogo terminou empatado!!\n");
			result = "draw";
		}
	}

	return result;

}

char * fourline2P(){ // main function for 2 players


	char fim;
    int n, jog;
    int tipo = 1;

    printf("                        4 em linha \n\n\n");
    fim = ' '; n = 0; jog = 1;
    inicia_tabuleiro();

    do {
        n++; 
        printf("Jogada %d \n \n", n);
        mostra_tabuleiro();
        jogada(jog, tipo);
        if (jog == 1) jog = 2; else jog = 1;
        fim = fim_jogo(n);
    } while (fim == ' ');

    finaliza(tipo, fim);

    return 0;
}


char * fourline(){ // main function

	char fim;
    int n, jog;
    int tipo = 2;

    printf("                        4 em linha \n\n\n");
    fim = ' '; n = 0; jog = 0;
    inicia_tabuleiro();

    do {
        n++; 
        printf("Jogada %d \n\n", n);
        mostra_tabuleiro();
        if (jog == 1) jog = 2; else jog = 1;
        jogada(jog, tipo);
        fim = fim_jogo(n);
    } while (fim == ' ');

    finaliza(tipo, fim);

    return 0;
}