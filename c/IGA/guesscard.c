#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h> 

#include "guessnumber.h"

/*

naipes
---------
paus - 1
espadas - 2 
copas - 3
ouros - 4

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
J - 11
Q - 12
K - 13

*/
char * toLower(char * s){
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}

int guesscard(){ // main function

	int naipeN, carta, guessCarta;
	int tries = 0;
	char * guessNaipe = NULL;
	char * naipe = NULL;

	carta = generateRandomInt(1,13);
	naipeN = generateRandomInt(1,4);

	switch(naipeN){
		case 1:
			naipe = "paus";
			break;

		case 2:
			naipe = "espadas";
			break;

		case 3:
			naipe = "copas";
			break;

		case 4:
			naipe = "ouros";
			break;

	}

	START:
		puts("Tenta adivinhar qual a carta e o seu respetivo naipe\n");
		puts("*nota_1 -> o seu input deverá ser o número da carta, ou 1 para ÀS, 11 para VALETE(J), 12 para DAMA(Q) e por fim, 13 para REI(K) e sem espaços o naipe*\n");
		puts("*nota_2 *naipe -> o naipe pode ser paus, espadas, copas ou ouros\n");

		scanf("%d%s", &guessCarta, guessNaipe);
		putchar('\n');

		if (carta == guessCarta){
			if (strcmp(toLower(guessNaipe), naipe) == 0){
				puts("Parabéns acertaste a carta e o respetivo naipe!!\n");
				sleep(5);
				system("clear");
			} else {
				++tries;
				puts("Parabéns acertaste a carta porém erraste o naipe, tenta novamente!!\n");
				sleep(3);
				system("clear");
				goto START;
			}
		} else if (strcmp(toLower(guessNaipe), naipe) == 0){
			if (carta != guessCarta){
				++tries;
				puts("Parabéns acertaste a naipe porém erraste a carta, tenta novamente!!\n");
				sleep(3);
				system("clear");
				goto START;
			}
		} else{
			++tries;
			puts("Erraste a carta e o naipe, tenta novamente!!\n");
			sleep(3);
			system("clear");
			goto START;
		}

	
	return tries;
}


