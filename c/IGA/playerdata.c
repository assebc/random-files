// players data
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef struct LPlayers{
    char * player;
    int points;
    struct LPlayers * prox;
} LPlayers;

void clear_console(){
    system("clear||cls"); // linux ou windows

}

LPlayers * default_start(){
	LPlayers * p = malloc(sizeof(LPlayers*));
	char * default_p1 = "player1";
	char * default_p2 = "player2";
	p->player = default_p1;
	p->points = 0;
	p->prox->player = default_p2;
	p->prox->points = 0;
	p->prox->prox = NULL;

	return p;
}

void append(LPlayers ** head_ref, char * new_data){

	LPlayers * new_node = malloc(sizeof(struct LPlayers*));
	*head_ref = default_start();
    LPlayers * last = *head_ref;
    new_node->player  = new_data;
    new_node->points  = 0;
    new_node->prox = NULL;
    while (last->prox != NULL) last = last->prox;
    last->prox = new_node;
}

int size(LPlayers * p){
    int contador = 1;
    while(p->prox!=NULL){
        ++contador;
        p = p->prox;
    }
    return contador;
}

int lookfor(LPlayers * p, char * data){
	int indice = 0;
	int sizes = size(p);

	while(indice<sizes){

		if(strcmp(p->player,data) == 0){
			break;
		} else {
			p = p->prox;
			indice++;
		}
	}
	if (indice == sizes) return sizes;

	return indice;
}

void playerdata(){

	int i1, i2;
	int iextra=0;
	char * player1 = NULL;
	char * player2 = NULL;
	LPlayers * p = malloc(sizeof(struct LPlayers*));
	// LPlayers * tmp = p;
	puts("Escolha o seu nome de jogador (até 2 jogadores)!!\n");
	puts("*nota -> jogos que só permitem 1 (um) jogador utilizaram o jogador 1 por default\n");
	
	printf("Jogador 1: "); scanf("%s", player1); putchar('\n');
	i1 = lookfor(p, player1);
	if (i1 == size(p)){ 
		append(&p, player1); 
	} else {
		iextra = i1;
		while(iextra>0){
			if(strcmp(p->player,player1)==0){
				break;	
			} else{
				iextra--;
			}
		}
	}

	printf("Jogador 2: "); scanf("%s", player2); putchar('\n');
	i2 = lookfor(p, player2);
	if (i2 == size(p)) append(&p, player2);


}