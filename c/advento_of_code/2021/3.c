#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 2 4 8 16 32 64 128 256 512 1024 2048 5096 -> 9191

int pot(int x, int y){

	int ans = 1;
	while(y>0){
		ans *= 2;
		y--;
	}

	return ans;
}

int bin_to_dec(char * x){
	
	int ans = 0;
	int j = strlen(x)-1;
	for(int i = 0;i<strlen(x);i++){

		if (x[i] == '1') ans += pot(2,j);
		j--;
	}

	return ans;
}

char * invert_bin(char * x){

	for(int i = 0;i<strlen(x);i++){
		if(x[i] == '1') x[i] = '0';
		else x[i] = '1';
	}

	return x;

}

char * help(){

	int ans;
	char line[1024];
	int accum1 = 0, accum0 = 0;
	int j = 0, i = 0;
	char * final = malloc(sizeof(char)*14);
	char * array = malloc(sizeof(char)*1024); 
	char * array2 = malloc(sizeof(char)*1024); 
	char * array3 = malloc(sizeof(char)*1024); 
	char * array4 = malloc(sizeof(char)*1024); 
	char * array5 = malloc(sizeof(char)*1024); ; 
	char * array6 = malloc(sizeof(char)*1024);  
	char * array7 = malloc(sizeof(char)*1024); 
	char * array8 = malloc(sizeof(char)*1024); 
	char * array9 = malloc(sizeof(char)*1024); 
	char * array10 = malloc(sizeof(char)*1024); 
	char * array11 = malloc(sizeof(char)*1024); 
	char * array12 = malloc(sizeof(char)*1024); 
	FILE * f = fopen("inputs/3.txt", "r");

	while(fgets(line,1024,f)!=NULL){
		for(i = 0;i<13;i++) {
			if (i == 0) array[j] = line[i];
			else if (i == 1) array2[j] = line[i];
			else if (i == 2) array3[j] = line[i];
			else if (i == 3) array4[j] = line[i];
			else if (i == 4) array5[j] = line[i];
			else if (i == 5) array6[j] = line[i];
			else if (i == 6) array7[j] = line[i];
			else if (i == 7) array8[j] = line[i];
			else if (i == 8) array9[j] = line[i];
			else if (i == 9) array10[j] = line[i];
			else if (i == 10) array11[j] = line[i];
			else if (i == 11) array12[j] = line[i];
			else j++;
		}
	}
	
	for(i = 0;i<14;i++){
		if (array[i] == '1') accum1++;
		else if (array[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[0] = '0';
	else if (accum0 < accum1) final[0] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array2[i] == '1') accum1++;
		else if (array2[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[1] = '0';
	else if (accum0 < accum1) final[1] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array3[i] == '1') accum1++;
		else if (array3[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[2] = '0';
	else if (accum0 < accum1) final[2] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array4[i] == '1') accum1++;
		else if (array4[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[3] = '0';
	else if (accum0 < accum1) final[3] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array5[i] == '1') accum1++;
		else if (array5[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[4] = '0';
	else if (accum0 < accum1) final[4] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array6[i] == '1') accum1++;
		else if (array6[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[5] = '0';
	else if (accum0 < accum1) final[5] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array7[i] == '1') accum1++;
		else if (array7[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[6] = '0';
	else if (accum0 < accum1) final[6] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array8[i] == '1') accum1++;
		else if (array8[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[7] = '0';
	else if (accum0 < accum1) final[7] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array9[i] == '1') accum1++;
		else if (array9[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[8] = '0';
	else if (accum0 < accum1) final[8] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array10[i] == '1') accum1++;
		else if (array10[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[9] = '0';
	else if (accum0 < accum1) final[9] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array11[i] == '1') accum1++;
		else if (array11[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[10] = '0';
	else if (accum0 < accum1) final[10] = '1';

	accum0 = 0; accum1 = 0;

	for(i = 0;i<14;i++){
		if (array12[i] == '1') accum1++;
		else if (array12[i] == '0') accum0++;
	}

	if (accum0 > accum1) final[11] = '0';
	else if (accum0 < accum1) final[11] = '1';

	return final;
}


int main(){

	int ans = bin_to_dec(help()) * bin_to_dec(invert_bin(help()) ); // gamma * epsilon
	int ans2 = 0;
	printf("exercise 1 : %d exercise 2 : %d\n", ans, ans2);
	return 0;
}