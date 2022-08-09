#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "4-line.h"

int givepoints(int opcaojogo, int Ntries, int w_l_21, char * w_l, int forca){ // points given in each game

	int score = 0;
	int maxScore;

	switch(opcaojogo){

		case 1: // guess number
			maxScore = 10;
			score = maxScore - Ntries;

			break;

		case 2: // guess card
			maxScore = 6;
			score = maxScore - Ntries;

			break;

		case 3: // 21
			score += w_l_21;
			
			break;

		case 4: // rooster 2P
			if (strcmp(w_l, "win1") == 0) // 1st player win
				score += 1; // so 2nd player looses 1
			else if (strcmp(w_l, "win2") == 0) // 2nd player win
				score += 2; // so 1st player looses 2
			else if (strcmp(w_l, "draw") == 0)
				score = 0;
			break;

		case 5: // rooster
			if (strcmp(w_l, "win1") == 0) // 1st player win
				score += 1; // so 2nd player looses 1
			else if (strcmp(w_l, "win2") == 0) // 2nd player win
				score += 2; // so 1st player looses 2
			else if (strcmp(w_l, "draw") == 0)
				score = 0;

			break;

		case 6: // forca

			score += forca; // if he wins add the score equivalent to letters he found otherwise sums 0

			break;

		case 7: // 4 in line 2P
			if (strcmp(w_l, "win") == 0) // player 1 win
				score += 4; 
			else if (strcmp(w_l, "loose") == 0) // player 1 loose
				score -= 4; 

			break;

		case 8: // 4 in line
			if (strcmp(w_l, "win") == 0) // player win
				score += 4; 
			else if (strcmp(w_l, "loose") == 0) // player loose
				score -= 4; 

			break;

		default:
			score = 0;
			break;
	}

	if (score < 0) score = 0;

	return score;

}

void pointsGame(int opcaojogo){ // point per game function

	// ...

}


void pointsGlobal(){ // global points function

	// ... 

}