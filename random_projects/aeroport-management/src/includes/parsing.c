#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "define.h"

#include "modules/avioes.h"
#include "modules/aeroporto.h"
#include "modules/voo.h"
#include "modules/ticket.h"

#include "btree.h"
#include "parser.h"
#include "grafos.h"

btree * btree_organizer(){

	btree ** a = malloc(sizeof(btree*));
	FILE * v = fopen(FLIGHT, "r");
	char line[LINE_BUFFER];

	while(fgets(line,LINE_BUFFER,v)!=NULL){
		VOOS v = create_voo();
		set_voo(v,line);
		insertID(a,get_num_voo(v));
		delete_voo(v);
	}

	return *a;
}

int pessoas_abordo(int num_voo, btree * tree){

	struct btree * tmp = tree;

	int value = id_wanted2(tmp, num_voo);

	return value;
}

float horas(int num_voo){

	FILE * v = fopen(FLIGHT, "r");
	char line[LINE_BUFFER];
	float sec, horas;

	while(fgets(line,LINE_BUFFER,v)!=NULL){
		VOOS v = create_voo();
		set_voo(v,line);
		if(get_num_voo(v) == num_voo){
			sec = date_compare(get_data_partida(v),get_data_chegada(v));
			delete_voo(v);
			break;
		}
		else delete_voo(v);
	}
	fclose(v);

	horas = sec / 3600;

	return horas;
}

float distancia(int num_voo){

	FILE * t = fopen(TICKET, "r");
	char line[LINE_BUFFER]; char * aux = NULL;
	float distancia;

	while(fgets(line,LINE_BUFFER,t)!=NULL){
		BILHETES b = create_ticket();
		set_ticket(b,line);
		aux = get_voo_ticket(b);
		VOOS v = create_voo();
		set_voo(v,aux);
		if(get_num_voo(v) == num_voo){
			distancia = get_distancia(b);
			delete_voo(v);
			delete_ticket(b);
			break;
		}

		delete_voo(v);
		delete_ticket(b);

	}
	fclose(t);

	return distancia;
}

float cost(int abordo, float horas, float milhas){

	float sum_costs, tripulacao, preco_galao = 2.0709;

	tripulacao = 400 * horas * abordo;
	tripulacao += 5000;

	milhas *= preco_galao;

	sum_costs = tripulacao + milhas;

	return sum_costs;
}

float all_tickets_return(int num_voo){

	FILE * t = fopen(TICKET, "r");
	float tickets = 0;
	char line[LINE_BUFFER]; char * aux = NULL;

	while(fgets(line,LINE_BUFFER,t)!=NULL){
		BILHETES b = create_ticket();
		set_ticket(b,line);
		aux = get_voo_ticket(b);
		VOOS v = create_voo();
		set_voo(v,aux);
		if(get_num_voo(v)==num_voo){
			tickets += get_preco(b);		
		}
		delete_voo(v);
		delete_ticket(b);
	}

	fclose(t);
	
	return tickets;
}

int another_num_voo(int num_voo, btree * vs){
	
	FILE * f = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char * aux = NULL;
	int num_voo_option = 0, num_lugares, max_on_flight;
	char * aero_p = NULL; char * aero_c = NULL; char * data_p = NULL;
	btree * tmp = vs;

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS v = create_voo();
		set_voo(v,line);
		if (get_num_voo(v) == num_voo){

			// create capsule to search num_lugares
			aux = get_aviao_voo(v);
			AVIOES a = create_aviao();
			set_aviao(a, aux);
			num_lugares = get_num_lugares(a);
			delete_aviao(a);
			// close capsule

			if( num_lugares > id_wanted2(tmp,get_num_voo(v)) ) return num_voo; // verifica se voo está cheio

			aero_p = get_aeroport_partida(v);
			aero_c = get_aeroport_chegada(v);
			data_p = get_data_partida(v);
			
		} 
		delete_voo(v);
	}

	while(fgets(line,LINE_BUFFER,f)!=NULL){
		VOOS v = create_voo();
		set_voo(v,line);
		int atm_num_voo = get_num_voo(v);
		int flight_occupation = id_wanted2(tmp,atm_num_voo);
		if( (atm_num_voo != num_voo) && (strcmp(get_aeroport_partida(v),aero_p)==0) && (strcmp(get_aeroport_chegada(v),aero_c)==0) && date_compare_bool(get_data_partida(v),data_p)){
			AVIOES as = create_aviao();
			set_aviao(as,get_aviao_voo(v));
			max_on_flight = get_num_lugares(as);
			if(flight_occupation < max_on_flight){
				num_voo_option = atm_num_voo;
				return num_voo_option;
			}
			delete_aviao(as);
		}
		delete_voo(v);
	}
	fclose(f);

	return num_voo_option;
}

void verify_ticket(btree * p){

	FILE * t = fopen(TICKET, "r");
	FILE * vf = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char line_2[LINE_BUFFER];char * voo_updt = NULL; char * voo = NULL;

	while(fgets(line,LINE_BUFFER,t)!=NULL){
		BILHETES b = create_ticket();
		set_ticket(b,line);
		voo = get_voo_ticket(b);

		// create capsule to search num_lugares
		VOOS v = create_voo();
		set_voo(v,voo);
		int n_voo = get_num_voo(v);
		int num_voo = another_num_voo(n_voo,p);
		delete_voo(v);
		// close capsule

		while(fgets(line_2,LINE_BUFFER,vf)!=NULL){
			VOOS vs = create_voo();
			set_voo(vs,line_2);
			if (num_voo == get_num_voo(vs)){
				strcpy(voo_updt,line_2);
				break;
			}
			delete_voo(vs);
		}

		fclose(vf);
		set_voo_ticket(b,voo_updt);
		delete_ticket(b);
	}
	fclose(t);
}

btree * profit(){

	btree * tmp = btree_organizer();
	int N = conta_nodos(tmp);
	int * list = create_list(N);
	list = preorder(tmp, list);
	char * list_profit[N];

	for(int j = 0;j<N;j++){
		list_profit[j] = NULL;
	}

	char * lucro = "lucro";
	char * equilibrio = "equilibrio";
	char * prejuizo = "prejuizo";

	int num_voo;
	for(int i = 0;i<N;i++){
		num_voo = list[i];
		if(all_tickets_return(num_voo) > cost(pessoas_abordo(num_voo, tmp), horas(num_voo), distancia(num_voo) ) ) list_profit[i] = lucro;
		else if(all_tickets_return(num_voo) == cost(pessoas_abordo(num_voo, tmp), horas(num_voo), distancia(num_voo) ) ) list_profit[i] = equilibrio;
		else list_profit[i] = prejuizo;
	}

	profit_insert(tmp,list_profit);

	return tmp;
}


