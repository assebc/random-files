#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> 

#include "IGA.h"

// gcc -g guessnumber.c guesscard.c 21.c rooster.c forca.c 4-line.c points.c playerdata.c IGA.c main.c -o execute
// ./execute

int main(){

	system("clear");
	printf("Entering IPCA GAMES ARCH(IGA) ...\n");
	sleep(2);
	printf("Loading ...\n");
	sleep(2);
	system("clear");

    IGA();

    return 0;
}