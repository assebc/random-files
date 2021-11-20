#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h> 


int generateRandomInt(int min, int max) { // given function

	srand((unsigned)time(NULL));
	return min + rand() % (max - min);

}

int guessnumber(){ // main function

	int findX, guessX;
	int tries = 0;
	findX = generateRandomInt(0,100);

	START: 
		puts("Entre 0 a 100 que número sou?\n");

		scanf("%d", &guessX);
		putchar('\n');

		if (findX == guessX){
			puts("Parabéns acertaste!!\n");
			sleep(5);
		} else if (findX > guessX){
			++tries;
			puts("Tenta outra vez, esse número é menor!!\n");
			sleep(3);
			system("clear");
			goto START;
		} else {
			++tries;
			puts("Tenta outra vez, esse número é maior!!\n");
			sleep(3);
			system("clear");
			goto START;
		}

	return tries;
}