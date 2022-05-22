#include <stdio.h>
#include <stdlib.h>

int isValidSubsequence(int array[],int N1,int sequence[], int N2){

	int arridx = 0, seqidx = 0;

	while((arridx < N1) && seqidx < N2 ){
		if(array[arridx] == sequence[seqidx]) seqidx++;

		arridx;
	}

	if (seqidx == N2) {
		printf("%d\n", 1) ;
		return 1;
	} else {
		printf("%d\n", 0);
		return 0;
	}

}

int main(){

	int array[] = {5, 1, 22, 25, 6, -1, 8, 10};
	int sequence[] = {1, 6 , -1, 10};

	isValidSubsequence(array, 8, sequence, 4);
	return 0;
}

