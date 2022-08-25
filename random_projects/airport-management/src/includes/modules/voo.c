#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../define.h"
#include "aeroporto.h"
#include "avioes.h"

struct voo {

	int num_voo;
	char * data_partida;
	char * data_chegada;
	char * aeroport_partida;
	char * aeroport_chegada;
	char * aviao_voo;

};

typedef struct voo *VOOS;

void * create_voo(){

	VOOS v = malloc(sizeof *v);
	if(v == NULL) printf("Erro\n");
	return v;

}

void delete_voo(void * v){

	VOOS vs = (VOOS) v;
	vs->num_voo = 0;
	free(vs);

} 

void set_num_voo(VOOS v, int x){
	v->num_voo = x;
}

void set_data_partida(VOOS v, char * s){
	v->data_partida = s;
}

void set_data_chegada(VOOS v, char * s){
	v->data_chegada = s;
}

void set_aeroport_partida(VOOS v, char * s){
	v->aeroport_partida = s;
}

void set_aeroport_chegada(VOOS v, char * s){
	v->aeroport_chegada = s;
}

void set_aviao_voo(VOOS v, char * s){
	v->aviao_voo = s;
}

void set_voo(void * v, char * line){

	char * p = NULL, *temp_line = strdup(line), *os;
	VOOS vs = (VOOS) v;
	os = temp_line;
	int i = 0;

	while((p = strsep(&temp_line, ";")) != NULL){
		switch(i){
			case 0:
				set_num_voo(vs,atoi(p));
				break;

			case 1:
				set_data_partida(vs,p);
				break;

			case 2:
				set_data_chegada(vs,p);
				break;

			case 3:
				set_aeroport_partida(vs, p);
				break;

			case 4:
				set_aeroport_chegada(vs,p);
				break;

			case 5:
				set_aviao_voo(vs, p);
				break;
		}
		i++;
	}
	free(os);
}

int get_num_voo(void * v){
	VOOS vs = (VOOS) v;
	return vs->num_voo;
}

char * get_data_partida(void * v){
	VOOS vs = (VOOS) v;
	return vs->data_partida;
}

char * get_data_chegada(void * v){
	VOOS vs = (VOOS) v;
	return vs->data_chegada;
}

char * get_aeroport_partida(void * v){
	VOOS vs = (VOOS) v;
	return vs->aeroport_partida;
}

char * get_aeroport_chegada(void * v){
	VOOS vs = (VOOS) v;
	return vs->aeroport_chegada;
}

char * get_aviao_voo(void * v){
	VOOS vs = (VOOS) v;
	return vs->aviao_voo;
}

char * get_voo_num_voo(int num_voo){

	FILE * f = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char * voo = NULL;

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS vs = create_voo();
		set_voo(vs,line);
		if(get_num_voo(vs)==num_voo){
			strcpy(voo,line);
			delete_voo(vs);
			break;
		}
		delete_voo(vs);	
	}
	fclose(f);

	return voo;	
}

char * get_data_partida_num(int num_voo){

	FILE * f = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char * data = NULL;

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS vs = create_voo();
		set_voo(vs,line);
		if(get_num_voo(vs)==num_voo){
			data = get_data_partida(vs);
			delete_voo(vs);
			break;
		}
		delete_voo(vs);	
	}
	fclose(f);

	return data;	

}

char * get_data_chegada_num(int num_voo){

	FILE * f = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char * data = NULL;

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS vs = create_voo();
		set_voo(vs,line);
		if(get_num_voo(vs)==num_voo){
			data = get_data_partida(vs);
			delete_voo(vs);
			break;
		}
		delete_voo(vs);	
	}
	fclose(f);

	return data;

}

char * get_aviao_nvoo(int num_voo){

	FILE * f = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char * aviao = NULL;

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS vs = create_voo();
		set_voo(vs,line);
		if(get_num_voo(vs)==num_voo){
			aviao = get_aviao_voo(vs);
			delete_voo(vs);
			break;
		}
		delete_voo(vs);	
	}
	fclose(f);

	return aviao;


}

void print_voo(void * v){
	VOOS vs = (VOOS) v;
	printf("num_voo:%d data_partida:%s data_chegada:%s aeroport_partida:%s aeroport_chegada:%s aviao_voo:%s\n", vs->num_voo, vs->data_partida, vs->data_chegada, vs->aeroport_partida, vs->aeroport_chegada, vs->aviao_voo);
}

void copy_voo(void* dst, void* src){
	VOOS dstc = (VOOS) dst;
	VOOS srcc = (VOOS) src;

	dstc->num_voo = srcc->num_voo;
	dstc->data_partida = srcc->data_partida;
	dstc->data_chegada = srcc->data_chegada;
	dstc->aeroport_partida = srcc->aeroport_partida;
	dstc->aeroport_chegada = srcc->aeroport_chegada;
	dstc->aviao_voo = srcc->aviao_voo;
}