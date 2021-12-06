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
