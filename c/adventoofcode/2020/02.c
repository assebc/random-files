#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define F02 "inputs/02.txt"

static const unsigned int input_lines = 1000;


int size_ints(char * str){
	
	char *s = strdup(str);
	
	int size_num = 0;
	for(int i = 0;s[i]!=' ';i++){
		size_num++;
	}
	

	return size_num;
}

char * getLAine(char * str){
	char * string = NULL;

	char *s = strdup(str);
	char *q = malloc(sizeof(str));
	int size = size_ints(s);
	int j = 0;
	for(int i = size+4;s[i]!='\r';i++){
		q[j] = s[i];
		j++;
		
	}

	string = q;
	free(q);

	return string;
}


char get_char(char * str){
	char * string = NULL;

	char *s = strdup(str);
	int size = size_ints(s);

	char caracter = s[size+1];

	return caracter;
}

int checkstring(char * str, char x){
	int r = 0;

	for (int i = 0;i<strlen(str);i++){
		if(str[i]==x) r++;
	}

	return r;
}


void getValid(){

	FILE * f = fopen(F02, "r");
	char str[1024];
	int validlines = 0;
	int end = 0;

	while (fgets(str, 1024, f) != NULL){
		char *s = strdup(str);
		int size = 0;
		char * h = malloc(sizeof(str));
		char * o = malloc(sizeof(str));
		int i = 0;

		size = size_ints(s);
		int a = checkstring(getLAine(s), get_char(s));
		if(size == 3){
			h[0] = s[0]; o[0] = s[2];
			if(a >= atoi(h) && a <= atoi(o) )
				validlines++;

		} else if(size == 4){
			o[0] = s[0]; h[0] = s[2]; h[1] = s[3];
			if(a >= atoi(o) && a <= atoi(h) )
				validlines++;

		} else if(size == 5){
			h[0] = s[0]; h[1] = s[1]; o[0] = s[3]; o[1] = s[4];
			if(a >= atoi(h) && a <= atoi(o) )
				validlines++;

		}
		a = 0;
		free(h);
		free(o);
	}
	end++;
	if (end == 1000)
		printf("%d\n", validlines);
	
	fclose(f);
}

int main(){
	getValid();
	return 0;
}