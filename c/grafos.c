#include <stdio.h>
#include <stdlib.h>

// strongly connected components

/*

*/
#define V 1;
#define N 6;

typedef struct node{

	int dest;
	int cost;
	struct node * next;
} *List;

typedef List Grafo[N*V];

int count_line(Grafo g){
	int c = 0;
	List j;

	for (int i = 0;i<N,i++){
		for(j = g[i];j->prox != NULL;j = j->prox){
			c++
		}	
	}
	return c;
}

int has_line(Grafo g, int start, int dest){

	List i;
	for(i = g[start];i!=NULL;i = i->prox){
		if(i->dest == dest) return 1;
	}
	return 0;
}

/* depth - first */
int has_path_aux(Grafo g, int start, int dest, int v[]){
	v[start] = 1;
	if (start == dest) return 1;
	for(i = g[start];i!=NULL;i=i->prox){
		if(v[i->dest] == 0 && has_path_aux(g,i->dest,dest,v)) return 1;
	}
	return 0;
}

int update_path(Grafo g, int start, int dest){
	int v[N*V];
	for(int i = 0;i<N*V;i++){
		v[i] = 0;
	}
	return (has_path_aux(g,start,dest,v));
}

int has_path(Grafo g, int start, int dest){
	if (start == dest) return 1;
	for(i = g[start];i!=NULL;i=i->prox){
		if(update_path(g,start,dest)) return 1;
	}
	return 0;
}

int contaReg(Grafo g, int ori, int v[]){
	Lista pt; int r = 1;
	v[ori] = 1;
	for(pt = g[ori];pt!=NULL;pt=pt->prox){
		if(!v[pt->dest]) r += contaRec(g, pt->dest, v);
	}
}

int contaAlcancavel(Grafo g, int ori){

	int vis[NV], i;
	for(i=0;i<NV;i++) vis[i] = 0;
	return (contaReg(g,ori,vis));
}

int contaReg(Grafo g, int ori, int v[], int p[]){
	Lista pt; int r = 1;
	v[ori] = 1;
	for(pt = g[ori];pt!=NULL;pt=pt->prox){
		if(!v[pt->dest]) r += contaRec(g, pt->dest, v);
	}
}

int alcancaveis(Grafo g, int ori, int vis[], int p[]){

	int i;
	p[ori] = -1;
	for(i=0;i<NV;i++) vis[i] = 0;
	return (contaRec(g,ori, vis, p));
}

int contaAlc(Grafo g, int ori, int v[], int p[]){

	Lista pt; int r = 1;
	v[ori] = 1;
	for(pt = g[ori];pt!=NULL;pt = pt->prox){
		if(!v[pt->dest]){
			p[pt->dest] = ori;
			r+= contaReg(g, pt->dest,v);
		}
	}
	return r;
}


/* breadth - first */

int contaBF(Grafo g, int ori){

	int r, int v[NV], int x; Lista a;
	int orla[NV], frente, fim;
	orla[0] = ori; frente = 0; fim = 1;
	for(int i = 0;i<NV;i++) v[i] = 0;
	v[ori] = -1; r = 0;
	while(frente!=fim){
		x = orla[frente++]; v[x] = 1; r++;
		for(a=g[x];a!=NULL;a=a->prox){
			if(!v[a->dest]){
				orla[fim++] = a->dest;
				v[a->dest] = -1;
			}
		}
	}
	return r;
}

int better_contaBF(Grafo g, int ori, int v[], int p[], int len[]){

	int r, int x; Lista a;
	int orla[NV], frente, fim;
	orla[0] = ori; frente = 0; fim = 1;
	for(int i = 0;i<NV;i++) v[i] = 0;
	v[ori] = -1; r = 0; p[ori] = -1; len[ori] = 0;
	while(frente!=fim){
		x = orla[frente++]; v[x] = 1; r++;
		for(a=g[x];a!=NULL;a=a->prox){
			if(!v[a->dest]){
				orla[fim++] = a->dest;
				v[a->dest] = -1;
				p[a->dest] = x;
				len[a->dest] = len[x++];
			}
		}
	}
	return r;
}