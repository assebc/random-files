#ifndef TICKET_H
#define TICKET_H

#include "../define.h"

typedef struct ticket *BILHETES;

void * create_ticket();
void delete_ticket(void * b);

void set_nome_passageiro(BILHETES b, char * s);
void set_nif(BILHETES b, int x);
void set_voo_ticket(BILHETES b, char * s);
void set_lugar(BILHETES b, char * s);
void set_preco(BILHETES b, float x);
void set_distancia(BILHETES b, float x);
void set_ticket(void * b, char * line);

char * get_nome_passageiro(void * b);
int get_nif(void * b);
char * get_voo_ticket(void * b);
char * get_lugar(void * b);
float get_preco(void * b);
float get_distancia(void * b);
float get_preco_num_voo(int num_voo);

void print_ticket(void * b);
void copy_ticket(void* dst, void* src);

#endif