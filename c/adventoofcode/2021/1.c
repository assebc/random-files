#include <stdio.h>
#include <stdlib.h>

int *  order(){

	FILE * f = fopen("inputs/1.txt","r");
	char line[1024];
	int i = 0;
	int * array = malloc(sizeof(int)*2100);

	while(fgets(line,1024,f) != NULL){
		array[i] = atoi(line);
		i++;
	}
	fclose(f);
	return array;
}

int counter(int array[]){
	int ans = 0;
	for(int i = 0;array[i+1]!='\0';i++){
		if(array[i]<array[i+1]) ans++;	
	}
	return ans;
}

int *  order_2(){

	FILE * f = fopen("inputs/1.txt","r");
	char line[1024];
	int i = 0;
	int * array = malloc(sizeof(int)*2100);
	int * array2 = malloc(sizeof(int)*(2100));

	while(fgets(line,1024,f) != NULL){
		array[i] = atoi(line);
		i++;
	}
	fclose(f);
	int j = 0;
	for(i=0;array[i]!='\0'||array[i+1]!='\0'||array[i+2]!='\0';i++){
		array2[j++] = array[i] + array[i+1] + array[i+2];
	}
	return array2;
}

int counter_2(int array[]){
	int ans = 0;
	for(int i = 0;array[i+1]!='\0';i++){
		if(array[i]<array[i+1]) ans++;	
	}
	return ans;
}

int main(){

	int ans1 = counter(order());
	int ans2 = counter_2(order_2());
	printf("exercise 1 : %d exercise 2 : %d\n", ans1, ans2);
	return 0;
}