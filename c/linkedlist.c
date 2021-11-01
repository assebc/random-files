#include <stdio.h>
#include <stdlib.h>
 
typedef struct llist {
    int valor;
    struct llist *prox;
    struct llist *ant;
} *LInt;


LInt enqueue(LInt ori, int data){
    while(ori->prox !=  NULL){
        ori->prox;
    }
    ori->prox->valor = data;
    ori->prox->prox = NULL;

    return ori;
}

int dequeue(LInt ori, int data){
   while(ori->prox != NULL) {
        if(ori->valor == data){
            ori->prox;
            free(ori->ant);
        } else ori->prox;
   }
   while (ori->ant->ant != NULL){
    ori = ori->ant;
   }
   return ori->ant->valor;
}

int front(LInt ori){
    int r;
    if (ori == NULL){
        r = -1;
        return r;
    }else while(ori->ant != NULL){
        ori = ori->ant;
    }
    
    return ori->valor;
}

int size(LInt ori){
    while(ori->ant != NULL){
        ori = ori->ant;
    }
    int contador = 0;
    while(ori->prox!=NULL){
        ++contador;
        ori = ori->prox;
    }
    return contador;
}

int isEmpty(LInt ori){
    int r = 1; // 1 if not empty , 0 if empty
    if (ori == NULL) r = 0;
    else r;
    return r;
}

LInt clear(LInt ori){
    while(ori->prox !=NULL){
        ori = ori->prox;
    }
    ori->ant = ori->prox;
    ori = ori->prox;
    return ori;
}

int main(){
    printf("bueda cenas\n");
    return 0;
}