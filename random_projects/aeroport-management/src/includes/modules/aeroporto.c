#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../define.h"

struct aeroport {

	char * cod_IATA;
	char * nome;
	char * cidade;
	int altitude;

};

typedef struct aeroport *AEROPORTO;

void * create_aeroporto(){

	AEROPORTO a = malloc(sizeof *a);
	if(a == NULL) printf("Erro\n");
	return a;

}

void delete_aeroporto(void * a){

	AEROPORTO as = (AEROPORTO) a;
	free(as);

} 

void set_cod_IATA(AEROPORTO a, char * s){
	a->cod_IATA = s;
}

void set_nome(AEROPORTO a, char * s){
	a->nome = s;
}

void set_cidade(AEROPORTO a, char * s){
	a->cidade = s;
}

void set_altitude(AEROPORTO a, int x){
	a->altitude = x;
}

void set_aeroporto(void * a, char * line){

	char * p = NULL, *temp_line = strdup(line), *os;
	AEROPORTO as = (AEROPORTO) a;
	os = temp_line;
	int i = 0;

	while((p = strsep(&temp_line, ";")) != NULL){
		switch(i){
			case 0:
				set_cod_IATA(as,p);
				break;

			case 1:
				set_nome(as,p);
				break;

			case 2:
				set_cidade(as,p);
				break;

			case 3:
				set_altitude(as, atoi(p));
				break;
		}
		i++;
	}
	free(os);
}


char * get_cod_IATA(void * a){
	AEROPORTO as = (AEROPORTO) a;
	return as->cod_IATA;
}

char * get_nome(void * a){
	AEROPORTO as = (AEROPORTO) a;
	return as->nome;
}

char * get_cidade(void * a){
	AEROPORTO as = (AEROPORTO) a;
	return as->cidade;
}

int get_altitude(void * a){
	AEROPORTO as = (AEROPORTO) a;
	return as->altitude;
}	


void print_aeropoto(void * a){
	AEROPORTO as = (AEROPORTO) a;
	printf("cod_IATA:%s nome:%s cidade:%s altitude:%d \n", as->cod_IATA, as->nome, as->cidade, as->altitude);
}

void copy_aeroporto(void* dst, void* src){
	AEROPORTO dstc = (AEROPORTO) dst;
	AEROPORTO srcc = (AEROPORTO) src;

	dstc->cod_IATA = srcc->cod_IATA;
	dstc->nome = srcc->nome;
	dstc->cidade = srcc->cidade;
	dstc->altitude = srcc->altitude;
}