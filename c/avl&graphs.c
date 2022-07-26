#include <stdio.h>
#include <stdlib.h>

typedef enum balancefactor { LH , EH , RH } BalanceFactor;
typedef struct treenode {
 BalanceFactor bf; // indicador de equilíbrio AVL
 int entry; // inteiro guardado no nó
 int n_elems; // número de elementos desta árvore
 struct treeNode *left, *right;
} *Tree;

Tree rotateLeft(Tree t){
    Tree aux = t;
    t->right = aux->left;
    aux->left = t;
    t->n_elems--;
    aux->n_elems++;
    t = aux;
    return t;
}

int rank(Tree t, int x){
    int res = 0;
    if(!t) return res;
    else{
        if(t->entry==x) res = 1 + t->left->n_elems;
        else{
            if(t->entry>x) res = rank(t->left,x);
            else res = rank(t->right,x);
        }
    }
    return res;
}


typedef int GraphM[MAX][MAX];

struct edge {
 int dest;
 struct edge *next;
};
typedef struct edge *GraphL[MAX], *LAdj;

// só direto
int count_reachable(GraphM g, int s, int n){
    int res = 0;
    for(int j = 0;j<n;j++) if(g[s][j]==1) res++;
    return res;
}

// todas os acessíveis


void inTOout(GraphM in, GraphL out, int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(in[i][j]==1) g[i]->dest = j;
            g[i] = g[i]->prox;
        }
    }
}

int BF(GraphL g, int s, int v[], int p[], int l[], int n){
    int q[n], front, end, x,k;
    for(int i = 0;i<n;i++){
        v[i] = 0;
        p[i] = -1;
        l[i] = -1;
    }
    front = end = 0;
    q[end++] = s;
    v[s] = 1;
    p[s] = -1;
    l[s] = 0;
    k=1;
    while(front!=end){
        x = q[front++];
        for(LAdj a = g[s];a;a=a->prox){
            if(!v[a->dest]){
                k++;
                v[a->dest] = 1;
                p[a->dest] = x;
                l[a->dest] = 1+l[x];
                q[end++] = a->dest;
            }
        }
    }
    return 1;
}

int count_reachable2(GraphM g, int s, int n){
    int res = 0;
    int v[n], p[n], l[n];
    GraphL[n] out;
    inTOout(g,out,n);
    BF(out,s,v,p,l,n);
    int i = 0;
    while(v){
        if(v[i]==1) res++;
        i++;
    }
    return res;
}

int DFRec(GraphL g, int or, int v[],int p[],int l[]){
    int i = 1;
    v[or] = -1;
    for(LAdj a = g[or];a;a=a->prox){
        if(!v[a->dest]){
            p[a->dest] = or;
            l[a->dest] = 1+l[or];
            i+= DFRec(g,a->dest,v,p,l);
        }
    }
    v[or] = 1;
    return i;
}

int DF(GraphL g, int or, int v[],int p[],int l[],int n){
    for(int i =0;i<n;i++){
        v[i]=0;
        p[i]=-1;
        l[i]=-1;
    }
    p[or] = -1; l[or] = 0;
    return DFRec(g,or,v,p,l);
} 

int stronglyConnected(GraphL g, int n){
    int v[n],p[n],l[n];
    for(int i = 0;i<n;i++){
        if(DF(g,i,,v,p,l,n)!=n) return 0;
    }
    return 1;
}