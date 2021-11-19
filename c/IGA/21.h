#include "guessnumber.h"

char * card(int cardN);
char * replicate(char * x, int N);
char * spaces(char * s1, char * s2);
int card_points(int card);
int check_deck(int card, int deck[53]);
int draw_card(int deck[53]);
int twentyone();
