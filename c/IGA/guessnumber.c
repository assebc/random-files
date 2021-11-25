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

int guessnumber(){ // main function

	int findX, guessX;
	int tries = 0;
	findX = generateRandomInt(0,100);

	scanf("%d", &guessX);

	while(guessX != findX){
		puts("Entre 0 a 100 que número sou?\n");
		putchar('\n');
		if (findX == guessX){
			puts("Parabéns acertaste!!\n");
			sleep(1);
			break;
		} else if (findX > guessX){
			++tries;
			puts("Tenta outra vez, esse número é menor!!\n");
			sleep(1);
			clear_console();
		} else {
			++tries;
			puts("Tenta outra vez, esse número é maior!!\n");
			sleep(1);
			clear_console();
		}
	}

	return tries;
}
