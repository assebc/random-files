#ifndef BTREE_H
#define BTREE_H

#include <stdbool.h>

typedef struct btree btree;

btree * create_node(int value);
void insertID(btree ** rootptr, int val);
bool findID(btree * root, int value);
btree * id_wanted(btree * root, int value);
int id_wanted2(btree * root, int value);
void insert_person(btree * rootptr, int id_repo);
int conta_nodos(btree * root);
int * create_list(int N);
int * addlist(int list[], int N, int x);
int * preorder(btree *root, int list[]);
void profit_insert_btree(btree * root, char * list_profit[], int i);
void profit_insert(btree * root, char * list_profit[]);
char * lookfor_profit(btree * root, int num_voo);
void destroy_btree(btree * root);

#endif