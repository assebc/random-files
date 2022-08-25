#ifndef PARSING_H
#define PARSING_H

btree * btree_organizer();

int pessoas_abordo(int num_voo, btree * tree);
float horas(int num_voo);
float distancia(int num_voo);

float cost(int abordo, float horas, float milhas);
float all_tickets_return(int num_voo);
int another_num_voo(int num_voo, btree * vs);
void verify_ticket(btree * p);

btree * profit();

#endif