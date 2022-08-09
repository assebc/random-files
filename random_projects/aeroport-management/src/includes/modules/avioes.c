#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../define.h"

struct avioes {

	char * cod_registo;
	char * marca;
	char * modelo;
	int num_lugares;
	float velocidade_cruzeiro;
	float consumo_medio;

};

typedef struct avioes *AVIOES;

void * create_aviao(){

	AVIOES a = malloc(sizeof *a);
	if(a == NULL) printf("Erro\n");
	return a;

}

void delete_aviao(void * a){

	AVIOES as = (AVIOES) a;
	free(as->cod_registo);
	free(as->marca);
	free(as->modelo);
	as->num_lugares = 0;
	as->velocidade_cruzeiro = 0;
	as->consumo_medio = 0;
	free(as);

}

void set_cod_registo(AVIOES a, char * s){
	strcpy(a->cod_registo,s);
}

void set_marca(AVIOES a, char * s){
	strcpy(a->marca,s);
}

void set_modelo(AVIOES a, char * s){
	strcpy(a->modelo,s);
}

void set_num_lugares(AVIOES a, int x){
	a->num_lugares = x;
}

void set_velocidade_cruzeiro(AVIOES a, float x){
	a->velocidade_cruzeiro = x;
}

void set_consumo_medio(AVIOES a, float x){
	a->consumo_medio = x;
}

void set_aviao(void * a, char * line){

	char * p = NULL, *temp_line = strdup(line), *os;
	AVIOES as = (AVIOES) a;
	os = temp_line;
	int i = 0;

	while((p = strsep(&temp_line, ";")) != NULL){
		switch(i){
			case 0:
				set_cod_registo(as,p);
				break;

			case 1:
				set_marca(as,p);
				break;

			case 2:
				set_modelo(as,p);
				break;

			case 3:
				set_num_lugares(as, atoi(p));
				break;

			case 4:
				set_velocidade_cruzeiro(as, atof(p));
				break;

			case 5:
				set_consumo_medio(as, atof(p));
				break;
		}
		i++;
	}
	free(os);
}

char * get_cod_registo(void * a){
	AVIOES as = (AVIOES) a;
	return as->cod_registo;
}

char * get_marca(void * a){
	AVIOES as = (AVIOES) a;
	return as->marca;
}

char * get_modelo(void * a){
	AVIOES as = (AVIOES) a;
	return as->modelo;
}

int get_num_lugares(void * a){
	AVIOES as = (AVIOES) a;
	return as->num_lugares;
}	

float get_velocidade_cruzeiro(void * a){
	AVIOES as = (AVIOES) a;
	return as->velocidade_cruzeiro;
}

float get_consumo_medio(void * a){
	AVIOES as = (AVIOES) a;
	return as->consumo_medio;
}

void print_aviao(void * a){
	AVIOES as = (AVIOES) a;
	printf("cod_registo:%s marca:%s modelo:%s num_lugares:%d velocidade_cruzeiro:%.2f consumo_medio:%.2f\n", as->cod_registo, as->marca, as->modelo, as->num_lugares, as->velocidade_cruzeiro, as->consumo_medio);
}

void copy_aviao(void* dst, void* src){
	AVIOES dstc = (AVIOES) dst;
	AVIOES srcc = (AVIOES) src;

	dstc->cod_registo = srcc->cod_registo;
	dstc->marca = srcc->marca;
	dstc->modelo = srcc->modelo;
	dstc->num_lugares = srcc->num_lugares;
	dstc->velocidade_cruzeiro = srcc->velocidade_cruzeiro;
	dstc->consumo_medio = srcc->consumo_medio;
}