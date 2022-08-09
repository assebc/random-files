#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h> 

void clear_console(){
    system("clear||cls"); // linux ou windows

}

int generateRandomInt(int min, int max) { // given function

	//srand((unsigned)time(NULL));
	return (rand() % ((max)- min)) + min;

}

int generateRandomInt2(int min, int max) { // given function

	srand((unsigned)time(NULL));
	return (rand() % ((max)- min)) + min;

}

int guessnumber(){ // main function

	int findX, guessX;
	int tries = 0;
	findX = generateRandomInt2(0,100);

	puts("Entre 0 a 100 que número sou?\n");
	putchar('\n');
	scanf("%d", &guessX);
	putchar('\n');

	while(guessX != findX){
		if (tries != 0) { 
			puts("Entre 0 a 100 que número sou?\n");
			putchar('\n');
			scanf("%d", &guessX);
			putchar('\n');
		}
			
		if (guessX == findX){
			puts("Parabéns acertaste!!\n");
			sleep(1);
			break;
		} else if (guessX > findX){
			++tries;
			puts("Tenta outra vez, esse número é maior!!\n");
			sleep(1);
			clear_console();
		} else if (guessX < findX){
			++tries;
			puts("Tenta outra vez, esse número é menor!!\n");
			sleep(1);
			clear_console();
		}
	}

	return tries;
}
