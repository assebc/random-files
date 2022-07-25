#include <stdio.h>

#define NV 11

typedef struct aresta {
	int dest; int custo;
	struct aresta *prox;
} *LAdj, *GrafoL [NV];

int BF (GrafoL g, int or, int v[], int p[], int l[]){
	int i, x; LAdj a;
	int q[NV], front, end;
	for (i=0; i<NV; i++) {
		v[i]=0;
		p[i] = -1;
		l[i] = -1;
	}
	front = end = 0;
	q[end++] = or; //enqueue
	v[or] = 1; p[or]=-1;l[or]=0;
	i=1;
	while (front != end){
		x = q[front++]; //dequeue
		for (a=g[x]; a!=NULL; a=a->prox)
			if (!v[a->dest]){
				i++;
				v[a->dest]=1;
				p[a->dest]=x;
				l[a->dest]=1+l[x];
				q[end++]=a->dest; //enqueue
	}
	
	return i;
}

int main(){
	return 0;
}