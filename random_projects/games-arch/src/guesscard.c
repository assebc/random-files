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
	char guessNaipe, naipe;

	carta = generateRandomInt2(1,13);
	naipeN = generateRandomInt2(1,4);

	switch(naipeN){
		case 1:
			naipe = 'p';
			break;

		case 2:
			naipe = 'e';
			break;

		case 3:
			naipe = 'c';
			break;

		case 4:
			naipe = 'o';
			break;

	}
	puts("Tenta adivinhar qual a carta e o seu respetivo naipe\n");
	puts("*nota_1 -> o seu input deverá ser o número da carta, ou 1 para ÀS, 11 para VALETE(J), 12 para DAMA(Q) e por fim, 13 para REI(K) e com 1 (um) espaço a inicial do naipe*\n");
	puts("*nota_2 *naipe -> o naipe pode ser paus(input: P), espadas (input: E), copas(input: C) ou ouros(input: O)\n");
	scanf("%d%c", &guessCarta, &guessNaipe);

	while(guessCarta!=carta && guessNaipe!=naipe) {
		if (tries != 0){
			puts("Tenta adivinhar qual a carta e o seu respetivo naipe\n");
			puts("*nota_1 -> o seu input deverá ser o número da carta, ou 1 para ÀS, 11 para VALETE(J), 12 para DAMA(Q) e por fim, 13 para REI(K) e com 1 (um) espaço a inicial do naipe*\n");
			puts("*nota_2 *naipe -> o naipe pode ser paus(input: P), espadas (input: E), copas(input: C) ou ouros(input: O)\n");
			scanf("%d%c", &guessCarta, &guessNaipe);
		}
		
		putchar('\n');

		if (carta == guessCarta){
			if (tolower(guessNaipe) == naipe){
				puts("Parabéns acertaste a carta e o respetivo naipe!!\n");
				sleep(2);
				clear_console();
				break;
			} else {
				++tries;
				puts("Parabéns acertaste a carta porém erraste o naipe, tenta novamente!!\n");
				sleep(2);
				clear_console();
				
			}
		} else if (tolower(guessNaipe) == naipe){
			if (carta != guessCarta){
				++tries;
				puts("Parabéns acertaste a naipe porém erraste a carta, tenta novamente!!\n");
				sleep(2);
				clear_console();
			}
		} else{
			++tries;
			puts("Erraste a carta e o naipe, tenta novamente!!\n");
			sleep(2);
			clear_console();
			
		}
	}
	
	return tries;
}


