#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "define.h"

typedef struct btree{
    int value[2];
    char * profit;
    struct btree * left;
    struct btree * right;
} btree;


btree * create_node(int value){

    btree * result = malloc(sizeof(btree));
    if (result == NULL){
        result->value[0] = value;
        result->value[1] = 0;
        result->profit = NULL;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

void insertID(btree ** rootptr, int val){

    btree * root = *rootptr;

    if (root == NULL) (*rootptr) = create_node(val);
    else if (root->value[0] == val) root->value[0] = val;
    else if (root->value[0] == 0) {
        root->value[0] = val;
        root->value[1] = 0;
        root->profit = NULL;
    } else if (root->value[0] > val) {
        insertID(&(root->left),val);
    } else if (root->value[0] < val){
        insertID(&(root->right),val);
    }
}

bool findID(btree * root, int value){

    if (root == NULL) return false;
    else if(root->value[0]==value) return true;
    else if (value<root->value[0]) return findID(root->left,value);
    else return findID(root->right,value);

}

btree * id_wanted(btree * root, int value){

    if(root == NULL) return NULL;
    else if(root->value[0]==value) return root;
    else if (value<root->value[0]) return id_wanted(root->left,value);
    else return id_wanted(root->right,value);
}

int id_wanted2(btree * root, int value){

    if(root == NULL) return 0;
    else if(root->value[0]==value) return root->value[1];
    else if (value<root->value[0]) return id_wanted2(root->left,value);
    else return id_wanted2(root->right,value);
}

void insert_person(btree * rootptr, int id_repo){

    btree * root = rootptr;

    if (id_wanted(root, id_repo) != NULL) root->value[1] += 1; 
}

int conta_nodos(btree * root){

    int accum = 0;
    if(root){
        accum++;
        conta_nodos(root->left);
        conta_nodos(root->right);
    }

    return accum;
}

int * create_list(int N){

    int list[N];

    for(int i=0;i<N;i++) list[i] = 0;

    int * result = list;

    return result;
}

int * addlist(int list[], int N, int x){

    for(int i=0;i<N;i++){
        if (list[i] == 0){
            list[i] = x; 
            break;
        }
    }

    return list;
}

// Recursive Preorder
int * preorder(btree *root, int list[]){
    
    if(root){
        addlist(list, conta_nodos(root), root->value[0]);
        preorder(root->left, list);
        preorder(root->right, list);
    }

    return list;
}

void profit_insert_btree(btree * root, char * list_profit[], int i){
    if(root){
        root->profit = list_profit[i]; i++;
        profit_insert_btree(root->left,list_profit,i);
        profit_insert_btree(root->right,list_profit,i);
    }

}

void profit_insert(btree * root, char * list_profit[]){

    int i = 0;
    profit_insert_btree(root,list_profit,i);

}

char * lookfor_profit(btree * root, int num_voo){

    char * result = NULL;
    btree * tmp = root;

    tmp = id_wanted(tmp,num_voo);
    result = tmp->profit;

    return result;
}

void destroy_btree(btree * root){
    root->left = NULL;
    root->right = NULL;
    root->value[0] = 0;
    root->value[1] = 0;
    root->profit = NULL;
    root = NULL;
    free(root);
}