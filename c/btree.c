#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{

	int val;
	struct node * esq;
	struct node * dir;
};

struct caixa{

	int val;
	struct caixa * prox;
};

typedef struct node * ABin;
typedef struct caixa * LInt;

ABin create_node(int value){
 
	ABin result = malloc(sizeof(struct node));
	if(result){
		result->esq = NULL;
		result->dir = NULL;
		result->val = value;
	}
	return result;

}

void printfTab(int num){
	for(int i = 0;i<num;i++){
		printf("\t");
		return;
	}
}

void printABin_rec(ABin a, int lvl){
	printf("\n");
	if(!a){
		printfTab(lvl);
		printf("---<empty>---\n\n");
		return;
	}
	printfTab(++lvl);
	printf("value = %d\n\n", a->val);
	printfTab(lvl+2);

	printf("left\n");
	printABin_rec(a->esq,lvl+2);
	printfTab(lvl+2);

	printf("right\n");
	printABin_rec(a->dir,lvl+2);
	printfTab(++lvl);
	printf("\n");

}

void printABin(ABin a){
	printABin_rec(a, 0);
}

int searchFor(int value, ABin a){
	ABin aux = a;

	if(aux->val==value) return 1;
	else{
		int r1 = 0, r2 = 0;
		if(aux->esq!=NULL) r1 = searchFor(value, aux->esq);
		if(aux->dir!=NULL) r2 = searchFor(value, aux->dir);
		if(r1==1 || r2 == 1) return 1;
	}
	return 0;
}

int altura(ABin a){

	int alt = 0;
	if(!a) return 0;
	alt = 1+altura(a->esq);
	if(alt>1+altura(a->dir)) return alt;

	return (1+altura(a->dir));

}

ABin cloneAB(ABin a){
	if(!a) return NULL;
	ABin result = malloc(sizeof(struct node));
	result->val = a->val;
	result->esq = cloneAB(a->esq);
	result->dir = cloneAB(a->dir);
	return result;
}

void mirror(ABin * a){
	if(*a){
		ABin tmp = (*a)->esq;
		(*a)->esq = (*a)->dir;
		(*a)->dir = tmp;
		mirror(&((*a)->esq));
		mirror(&((*a)->dir));
	}
}

/*
inorder -> E R D
preorder -> R E D
posorder -> E D R
*/

void inorder_aux(ABin a, LInt * l){
	LInt aux = malloc(sizeof(struct caixa));
	if(a){
		inorder_aux(a->dir,l);
		aux->val = a->val;
		aux->prox = *l;
		*l = aux;
		inorder_aux(a->esq,l);
	}
}

void inorder(ABin a, LInt * l){ 
	*l = NULL;
	inorder_aux(a,l);
}

void preorder_aux(ABin a, LInt * l){
	LInt aux = malloc(sizeof(struct caixa));
	if(a){
		inorder_aux(a->dir,l);
		inorder_aux(a->esq,l);
		aux->val = a->val;
		aux->prox = (*l);
		(*l) = aux;
	}
}

void preorder(ABin a, LInt * l){ 
	*l = NULL;
	preorder_aux(a,l);
}

void posorder_aux(ABin a, LInt * l){
	LInt aux = malloc(sizeof(struct caixa));
	if(a){
		aux->val = a->val;
		aux->prox = (*l);
		(*l) = aux;
		inorder_aux(a->dir,l);
		inorder_aux(a->esq,l);	
	}
}

void posorder(ABin a, LInt * l){ 
	*l = NULL;
	posorder_aux(a,l);
}

int depth(ABin a, int x){
	if(!a) return -1;
	if(a->val == x) return 1;
	if(searchFor(x,a)){
		int esq = depth(a->esq,x);
		int dir = depth(a->dir,x);
		if(esq>dir) return esq+1;
		else return dir+1;
	}

	return -1;
}

int freeAB(ABin a){
	if(!a) return 0;
	int a1 = freeAB(a->esq);
	int b = freeAB(a->dir);
	free(a);
	return a1+b+1;
}

int pruneAB(ABin *a, int l){
	if(!(*a)) return 0;
	int n = 0;
	if(l==0){
		n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->esq),0);
		free(*a);
		*a = NULL;
	} else {
		n = 1 + pruneAB(&((*a)->esq),l-1) + pruneAB(&((*a)->esq),l-1);
	}
	return n; 
}

int iguaisAB(ABin a, ABin b){
	if((!a && b) || (a && !b)) return 0;
	if((!a && !b) || (a && b)) return 1;
	return a->val==b->val && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

LInt concat(LInt a, LInt b){
	if(!a) return b;
	LInt tmp = a;
	while(tmp->prox) tmp = tmp->prox;
	tmp->prox = b;
	return a;
}

LInt nivelL(ABin a, int n){
	LInt list = malloc(sizeof(struct caixa));
	if(n<1||!a) return NULL;
	if(n==1){
		list->val = a->val;
		list->prox = NULL;
		return list;
	} else return concat((nivelL((a->esq),n-1)),(nivelL((a->dir),n-1)));
}

int main(){

	ABin a1 = create_node(10);
	ABin a2 = create_node(12);
	ABin a3 = create_node(13);
	ABin a4 = create_node(15);
	ABin a5 = create_node(16);

	a1->esq = a2;
	a1->dir = a3;
	a3->esq = a4;
	a3->dir = a5;

	printABin(a1);
	int d = searchFor(15, a1);
	if(d == 1) printf("O valor %d está na árvore!\n", 15);
	else printf("O valor %d não está na árvore!\n", 15);

	d = searchFor(17, a1);
	if(d == 1) printf("O valor %d está na árvore!\n", 17);
	else printf("O valor %d não está na árvore!\n", 17);

	printf("A árvora tem %d de altura!\n", altura(a1));

	return 0;
}

