// menu IGA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> 

#include "guessnumber.h"
#include "guesscard.h"
#include "21.h"
#include "rooster.h"
#include "forca.h"
#include "4-line.h"
#include "points.h"
#include "playerdata.h"


void playgames(int opcaojogo){ // execute game functions from all header files

	int tries = 0;
    int w_l_21;
    int forcagame;
    char * w_l = NULL;

	switch(opcaojogo){
		case 1:
            tries = guessnumber(); // num of tries
            break;

        case 2:
            tries = guesscard(); // num of tries
            break;

        case 3:
            w_l_21 = twentyone(); // w_l_21
            break;

        case 4:
            w_l = rooster2P(); // win or win or draw
            break;

        case 5:
            w_l = rooster(); // win or win or draw
            break;

        case 6:
            forcagame = 1; // forca 
            break;

        case 7:
            w_l = fourline2P(); // win or loose or draw
            break;

        case 8:
            w_l = fourline(); // win or loose or draw
            break;

        default:
            system("clear");
            printf("invalid input\n");
            break;

	}
    sleep(1);
    if (tries > 0){
	printf("Depois de %d tentativas conseguiu! Você teve um total de %d pontos neste jogo!!\n", tries, givepoints(opcaojogo, tries, w_l_21, w_l, forcagame));
    } else printf("Você pontoou um total de %d pontos neste jogo!!\n", givepoints(opcaojogo, tries, w_l_21, w_l, forcagame));
    sleep(1);

}

/*
printf("%*s, 40+strlen(name)/2, name, 40-strlen(name)/2, ""); // center text in shell (if wanted)
*/

void IGA(){


	int opcao, opcaojogo, opcaoscore, decisao;

	HUB:
	system("clear");
    printf("Selecione uma opcao: \n");

    putchar('\n');

    printf("Selecione um jogo: 1\n");
    printf("Ver pontuacoes : 2\n");
    printf("Introduzir dados de jogadores: 3\n");
    printf("Sair: 4\n");

    putchar('\n');

    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1: // games

        	GAME_HUB: 

            system("clear");
        
            puts("Selecione o jogo: \n");
            puts("*nota -> 2P significa que o jogo necessita de 2 jogadores\n");

           	putchar('\n');

            printf("Adivinha o numero: 1\n");
            printf("Adivinha a carta: 2\n");
            printf("Jogo do 21: 3\n");
            printf("Jogo do galo (2P): 4\n");
            printf("Jogo do galo: 5\n");
            printf("Jogo da forca: 6\n");
            printf("4 em linha (2P) : 7\n");
            printf("4 em linha: 8\n");
            putchar('\n');
            printf("Voltar ao menu princpal: 0\n");

            putchar('\n');

            scanf("%d", &opcaojogo);

            switch(opcaojogo){

                case 0:
                    goto HUB;

            	case 1:
            		GAME_1 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
                    system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);


            		if (decisao == 1) goto GAME_1;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 2:
            		GAME_2 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_2;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 3:
            		GAME_3 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_3;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}
            		
            		break;

            	case 4:
            		GAME_4 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_4;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 5:
            		GAME_5 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_5;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 6:
            		GAME_6 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_6;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 7:
            		GAME_7 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_7;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	case 8:
            		GAME_8 :

            		system("clear");

            		playgames(opcaojogo);
                    sleep(2);
            		system("clear");
            		puts("Selecione a opcao: \n");

            		printf("Jogar novamente: 1\n");
            		printf("Voltar ao menu de jogos: 2\n");
            		printf("Voltar ao menu principal: 3\n");
                    putchar('\n');

            		scanf("%d", &decisao);

            		if (decisao == 1) goto GAME_8;
            		else if (decisao == 2) goto GAME_HUB;
            		else if (decisao == 3) goto HUB;
            		else {
            			printf("invalid input, going to HUB...");
            			goto HUB;
            		}

            		break;

            	default:
            		system("clear");
            		printf("invalid input\n");

            		break;
            }

            break;

        case 2: // score

            system("clear");
            puts("Selecione que pontuacao deseja verificar: \n");

            putchar('\n');

            printf("Pontuacao por jogo: 1\n");
            printf("Pontuacao global: 2 \n");
            printf("Voltar ao menu principal: 3\n");

            putchar('\n');

            scanf("%d", &opcaoscore);

            switch(opcaojogo){
            	int opcaojogo;
            	case 1:
            		puts("Selecione o jogo: \n");

            		putchar('\n');

           			printf("Adivinha o numero: 1\n");
            		printf("Adivinha a carta: 2\n");
            		printf("Jogo do 21: 3\n");
            		printf("Jogo do galo (2P): 4\n");
            		printf("Jogo do galo: 5\n");
            		printf("Jogo da forca: 6\n");
            		printf("4 em linha (2P) : 7\n");
            		printf("4 em linha: 8\n");

            		scanf("%d", &opcaojogo);

            		pointsGame(opcaojogo);
            		break;


            	case 2:
            		pointsGlobal();
            		break;

                case 3:
                    goto HUB;
                    break;

            	default:
            		system("clear");
            		printf("invalid input\n");
            		break;

           		
            }

            break;

        case 3: // players data 

        	system("clear");
        	playerdata();
        	break;

        case 4:	// exit

        	system("clear");
        	exit(0);
            break;

        default:
        	system("clear");
            printf("invalid input\n");
            break;
    }

}