#include <stdio.h>

int Maximum_Sum_Subarray(int v[], int N){

	int tmp = 0;

	for(int i=0;i<N;i++){
		
		if(v[i] + tmp < v[i]) tmp = v[i];
		else tmp += v[i];

	}

	return tmp;

}

int main(){
	
	int a[] = {1, 2, 3, -7, 5, -10, 20, 0};

    int N = sizeof(a)/sizeof(a[0]);

    int max_sum = Maximum_Sum_Subarray(a, N);
    printf("Maximum contiguous sum is %d\n", max_sum);

	return 0;
}