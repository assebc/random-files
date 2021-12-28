#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help(){

	char line[1024];

	FILE *f = fopen("inputs/2.txt","r");
	int forward = 0; int depth = 0;
	while(fgets(line,1024,f)!=NULL){
		
		if (strlen(line) == 11){
			forward += line[strlen(line)-3] - 48;

		} else if (strlen(line) == 8){
			depth += line[strlen(line)-3] - 48;

		} else if (strlen(line) == 6){
			depth -= line[strlen(line)-3] - 48;

		}
	}
	int ans = depth * forward;

	return ans;
}

int help_2(){

	char line[1024];

	FILE *f = fopen("inputs/2.txt","r");
	int horizontal = 0, horizontal_tmp,  depth = 0, aim = 0;
	while(fgets(line,1024,f)!=NULL){
		
		if (strlen(line) == 11){
			horizontal_tmp = line[strlen(line)-3] - 48;
			horizontal += horizontal_tmp;
			depth += horizontal_tmp * aim;

		} else if (strlen(line) == 8){
			aim += line[strlen(line)-3] - 48;

		} else if (strlen(line) == 6){
			aim -= line[strlen(line)-3] - 48;

		}
	}
	int ans_2 = depth * horizontal;

	return ans_2;
}

int main(){

	int ans = help();
	int ans_2 = help_2();
	printf("exercise 1 : %d exercise 2 : %d\n", ans, ans_2);
	return 0;

}