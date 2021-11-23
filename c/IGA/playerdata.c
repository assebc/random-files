// players data
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef struct LPlayers{
    char * player;
    struct LPlayers * prox;
} *LPlayers;

void clear_console(){
    system("clear||cls"); // linux ou windows

}

LPlayers default_start(){
	LPlayers p = malloc(sizeof(LPlayers));
	char * default_p1 = "player1";
	char * default_p2 = "player2";
	p->player = default_p1;
	p->prox->player = default_p2;
	p->prox->prox = NULL;

	return p;
}

void append(LPlayers ** head_ref, int new_data){

	LPlayers * new_node = malloc(sizeof(struct LPlayers*));
    LPlayers * last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

int size(LPlayers p){
    int contador = 0;
    while(p->prox!=NULL){
        ++contador;
        p = p->prox;
    }
    return contador;
}

void playerdata(){

	char * player1 = "player1";
	char * player2 = "player2";
	puts("Escolha o seu nome de jogador (até 2 jogadores)!!\n");
	puts("*nota -> jogos que só permitem 1 (um) jogador iram usar o jogador 1 por default\n");
	puts("Jogador 1: "); scanf("%s", player1); putchar('\n');
	puts("Jogador 2: "); scanf("%s", player2); putchar('\n');
	
}