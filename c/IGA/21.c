#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h> 

#include "guesscard.h"

/*

naipes
---------
paus - n1
espadas - n2 
copas - n3
ouros - n4

valores das cartas
----------------------
às - 1
2
3
4
5
6
7
8
9
10
J - 10
Q - 10
K - 10

organização meramente numérica
-------------------------------
A 2 3 4 5 6 7 8 9 10 J Q K

0-12 -> paus
13-25 -> espadas
26-38 -> copas
39-52 -> ouros

*/

char * card(int cardN){

	char * given_card = NULL;

	switch(cardN){
		// paus
			case 0:
				given_card = "A paus";
				break;

			case 1:
				given_card = "2 paus";
				break;

			case 2:
				given_card = "3 paus";
				break;

			case 3:
				given_card = "4 paus";
				break;

			case 4:
				given_card = "5 paus";
				break;

			case 5:
				given_card = "6 paus";
				break;

			case 6:
				given_card = "7 paus";
				break;

			case 7:
				given_card = "8 paus";
				break;

			case 8:
				given_card = "9 paus";
				break;

			case 9:
				given_card = "10 paus";
				break;

			case 10:
				given_card = "J paus";
				break;

			case 11:
				given_card = "Q paus";
				break;

			case 12:
				given_card = "K paus";
				break;
		// espadas
			case 13:
				given_card = "A espadas";
				break;

			case 14:
				given_card = "2 espadas";
				break;

			case 15:
				given_card = "3 espadas";
				break;

			case 16:
				given_card = "4 espadas";
				break;

			case 17:
				given_card = "5 espadas";
				break;

			case 18:
				given_card = "6 espadas";
				break;

			case 19:
				given_card = "7 espadas";
				break;

			case 20:
				given_card = "8 espadas";
				break;

			case 21:
				given_card = "9 espadas";
				break;

			case 22:
				given_card = "10 espadas";
				break;

			case 23:
				given_card = "J espadas";
				break;

			case 24:
				given_card = "Q espadas";
				break;

			case 25:
				given_card = "K espadas";
				break;
		// copas
			case 26:
				given_card = "A copas";
				break;

			case 27:
				given_card = "2 copas";
				break;

			case 28:
				given_card = "3 copas";
				break;

			case 29:
				given_card = "4 copas";
				break;

			case 30:
				given_card = "5 copas";
				break;

			case 31:
				given_card = "6 copas";
				break;

			case 32:
				given_card = "7 copas";
				break;

			case 33:
				given_card = "8 copas";
				break;

			case 34:
				given_card = "9 copas";
				break;

			case 35:
				given_card = "10 copas";
				break;

			case 36:
				given_card = "J copas";
				break;

			case 37:
				given_card = "Q copas";
				break;

			case 38:
				given_card = "K copas";
				break;
		// ouros
			case 39:
				given_card = "A ouros";
				break;

			case 40:
				given_card = "2 ouros";
				break;

			case 41:
				given_card = "3 ouros";
				break;

			case 42:
				given_card = "4 ouros";
				break;

			case 43:
				given_card = "5 ouros";
				break;

			case 44:
				given_card = "6 ouros";
				break;

			case 45:
				given_card = "7 ouros";
				break;

			case 46:
				given_card = "8 ouros";
				break;

			case 47:
				given_card = "9 ouros";
				break;

			case 48:
				given_card = "10 ouros";
				break;

			case 49:
				given_card = "J ouros";
				break;

			case 50:
				given_card = "Q ouros";
				break;

			case 51:
				given_card = "k ouros";
				break;

	}

	return given_card;
}


char * replicate(char x, int N){

	char * result = malloc(sizeof(char)*N);

	for(int i=0;i<N;i++){
		result[i] = x;
	}

	return result;
}

char * spaces(char * s1, char * s2){

	int num_spaces;
	char * result = NULL;

	num_spaces = 56 - strlen(s1);

	result = replicate(' ',num_spaces);


	return result;
}


int card_points(int card){

	int points = 0;

	if (card == 0 || card == 13 || card == 26 || card == 39) points = 1;
	else if (card == 1 || card == 14 || card == 27 || card == 40) points = 2;
	else if (card == 2 || card == 15 || card == 28 || card == 41) points = 3;
	else if (card == 3 || card == 16 || card == 29 || card == 42) points = 4;
	else if (card == 4 || card == 17 || card == 30 || card == 43) points = 5;
	else if (card == 5 || card == 18 || card == 31 || card == 44) points = 6;
	else if (card == 6 || card == 19 || card == 32 || card == 45) points = 7;
	else if (card == 7 || card == 20 || card == 33 || card == 46) points = 8;
	else if (card == 8 || card == 21 || card == 34 || card == 47) points = 9;	
	else points = 10;

	return points;
}


int draw_card(int deck[52]){

	int card;


	card = generateRandomInt(0, 51);
	if (deck[card] == 1){
		deck[card] = 0;
		return card;
	} else if (deck[card] == 0){
		draw_card(deck);
	} else draw_card(deck);

	return card;
}

int twentyone(){ // main function 
	int table_cardN, player_cardN, choice;
	int total_player_points = 0, total_table_points = 0;;
	char * table_card = (char*)malloc(sizeof(char) * 100);
	char * player_card = (char*)malloc(sizeof(char) * 100);
	int w_l_21 = 0;
	int wins = 0, looses = 0;
	int deck[52];

	// attribute all cards a deck should have
	for(int i=0;i<52;i++){
		deck[i] = 1;
	}

	// start rounds
	int rounds = 0;
	puts("O jogo vai começar, prepare-se!!\n");
	sleep(2);
	while(total_table_points < 21 && total_player_points < 21){

		// draw cards
		if ( rounds == 0 || choice == 1){
			
			player_cardN = draw_card(deck);
			table_cardN = draw_card(deck);

		} else if (choice == 2){

			table_cardN = draw_card(deck);

		}
		
		player_card = card(player_cardN);
		table_card = card(table_cardN);
		
		if(rounds == 0){
			puts("CARTAS JOGADOR:                                        CARTAS MESA: \n");
			sleep(1);
			printf("%s%s%s\n", player_card, spaces(player_card, table_card), table_card);
			putchar('\n');
			puts("Deseja pedir mais uma carta?\n");
			puts("Sim: 1");
			puts("Não: 2\n");

			scanf("%d", &choice);
			putchar('\n');
			
		} else {
			if(choice == 1){
				printf("%s%s%s\n", player_card, spaces(player_card, table_card), table_card);
				putchar('\n');
				puts("Deseja pedir mais uma carta?\n");
				puts("Sim: 1");
				puts("Não: 2\n");

				scanf("%d", &choice);
				putchar('\n');
			} else if(choice == 2){
				printf("                                                        %s\n", table_card); 

			}

		}

		if (rounds == 0){
			total_player_points += card_points(player_cardN);
			total_table_points += card_points(table_cardN);
		} else {
			if (choice == 1){
				total_player_points += card_points(player_cardN);
				total_table_points += card_points(table_cardN);
			} else if (choice == 2){
				total_table_points += card_points(table_cardN);
			}
		}

		sleep(2);
		
		// wins and looses status
		if(total_player_points < 21){
			if (total_table_points < 21){
				++wins;
			} else if (total_table_points == 21){
				++looses;
				putchar('\n');
				puts("Você perdeu a mesa chegou a 21 pontos!!\n");
				break;
			} else if (total_table_points > 21){
				++wins;
				putchar('\n');
				printf("Parabéns você ganhou, a mesa ultrapassou os 21 pontos!!\n");
				break;
			}
		} else if (total_player_points == 21){
			++wins;
			putchar('\n');
			puts("Parabéns você ganhou!!\n");
			break;
		} else if (total_player_points > 21){
			++looses;
			putchar('\n');
			printf("Você perdeu, ultrapassando os 21 pontos!!\n");
			break;
		}																
		rounds++;	
	} 

	putchar('\n');
	w_l_21 = wins + looses;
	wins = 0;
	looses = 0;

	return w_l_21;
}