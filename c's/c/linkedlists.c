#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{

	int valor;
	struct nodo * prox;

};

typedef struct nodo * LInt;

LInt new_nodo(int x){
	LInt l = malloc(sizeof(struct nodo));
	l->valor = x;
	l->prox = NULL;
	return l;
}

LInt addHead(int x, LInt l){

	if(!l) new_nodo(x);
	LInt aux = new_nodo(x);
	aux->prox = l;
	l = aux;
	return l;
}

void printL(LInt l){
	
	LInt temp = l;
	while(temp->prox != NULL){
		printf("%d -> ", temp->valor);
		temp = temp->prox;
	}
	printf("%d", temp->valor);
	printf("\n");
}

void insert_orded(LInt valor, LInt * l){
    LInt current;
    if ((*l) == NULL || (*l)->valor >= valor->valor) {
        valor->prox = (*l);
        (*l) = valor;
    } else {
        current = (*l);
        while (current->prox != NULL
               && current->prox->valor < valor->valor) {
            current = current->prox;
        }
        valor->prox = current->prox;
        current->prox = valor;
    }
}

void insert_invorded(LInt valor, LInt * l){
    LInt current;
    if ((*l) == NULL || (*l)->valor <= valor->valor) {
        valor->prox = (*l);
        (*l) = valor;
    } else {
        current = (*l);
        while (current->prox != NULL
               && current->prox->valor > valor->valor) {
            current = current->prox;
        }
        valor->prox = current->prox;
        current->prox = valor;
    }
}

int size(LInt l){
	LInt aux = l;
	int n = 0;
	while(aux!=NULL){
		n++;
		aux=aux->prox;
	}
	return n;
}

int tamanho(int arr[]){
	int n = 0;
	while(arr){
		n++;
	}
	return n;
}

void swap(int i, int j, int arr[]){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void orderArray(int arr[], int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 1;j<n;j++){
			if(arr[j]<arr[i]) swap(i,j,arr);
		}
	}
}

LInt toOrder(LInt l){
	int n = size(l);
	int arr[n];
	for(int i = 0;i<n;i++){
		arr[i] = l->valor;
		l = l->prox;
	}
	orderArray(arr,n);
	LInt aux = new_nodo(arr[0]);
	for(int j = 1;j<n;j++){
		insert_orded(new_nodo(arr[j]),&aux);
	}
	return aux;
} 

void removeElem(int key, LInt * l) {
  LInt temp = *l, prev;

  if (temp != NULL && temp->valor == key) {
  	*l = temp->prox;
  	free(temp);
  	return;
  }
  
  while (temp != NULL && temp->valor != key) {
  	prev = temp;
  	temp = temp->prox;
  }

  if (temp == NULL) return;

  prev->prox = temp->prox;
  free(temp);
}

int main(){

	printf("=========== TESTES 1 ===========\n");
	LInt l = new_nodo(0);
	for(int i = 1;i<6;i++){
		l = addHead(i,l);
	}
	for(int i = 7;i<11;i++){
		l = addHead(i,l);
	}
	printL(l);

	insert_invorded(new_nodo(6),&l);
	printL(l);
	printf("tamanho de LinkedList é de : %d\n", size(l));

	insert_invorded(new_nodo(11),&l);
	printL(l);

	insert_invorded(new_nodo(12),&l);
	printL(l);

	printf("=========== TESTES 2 ===========\n");
	LInt l2 = new_nodo(10);
	insert_orded(new_nodo(5),&l2);
	insert_orded(new_nodo(7),&l2);
	insert_orded(new_nodo(2),&l2);
	insert_orded(new_nodo(11),&l2);
	printf("10 -> 5 -> 7 -> 2 -> 11\n");
	printL(l2);
	
	printf("=========== TESTES 3 ===========\n");
	LInt l3 = new_nodo(10);
	l3 = addHead(5,l3);
	l3 = addHead(7,l3);
	l3 = addHead(2,l3);
	l3 = addHead(11,l3);
	printL(l3);
	l3 = toOrder(l3);
	printL(l3);
	printf("=========== TESTES 4 ===========\n");
	removeElem(5,&l3);
	printL(l3);

	return 0;
}