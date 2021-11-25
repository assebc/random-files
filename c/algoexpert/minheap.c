#include <stdio.h>

#define esq(i) 2*i+1
#define dir(i) 2*i+2
#define pai(i) (i-1)/2
/*

			-----10-----
		   /           \
		  15           11
		/   \        /    \
	   16    22     35     20
	  /  \  /  \   /  \   /  \
	 21  23 34 37 80  43 22  25
	/  \
   24   28


*/

// normal swap function
void swap(int v[], int i, int j){
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;

}

// a value with indice i, go up in heap while is father is greater then h[i]
void bubbleUP(int i, int h[]){

	while(h[pai(i)] > h[i]){
		if(h[pai(i)] > h[i]){
			swap(h,pai(i),i);
			i = pai(i);
		}
	}
 
}

// a value with indice i, go up in heap while is father is less then h[i]
void bubbleDOWN(int i, int h[], int N){
	int tmp;

	while(esq(i)<N){
		tmp = esq(i);
		if(dir(i)<N && h[dir(i)] < h[esq(i)]) tmp = dir(i);
		if (h[i]<h[tmp]) break;
		swap(h,i,tmp);
		i = tmp; 
	}
}

 /*
 * using bubbleUP with strategy TOP-DOWN, that basicly is, turn a BTree into heap
 * bascily turning a BTree into heap from top to bottom
 */
void heapifyTD(int h[], int N){
	int i;

	for(i = 0;i<N;i++) bubbleUP(i,h);
}

 /* 
  * using bubbleDOWN with strategy BOTTOM-UP, that basicly is, turn a BTree into heap
  * basicly turning a BTree into heap from bottom to top
 */
void heapifyBU(int h[], int N){
	int i;

	for(i = 1;i<N;i++) bubbleDOWN(i,h,N);
}

int main(){

	return 0;
}