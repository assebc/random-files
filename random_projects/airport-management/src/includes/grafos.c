#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "parser.h"

#include "modules/avioes.h"
#include "modules/aeroporto.h"
#include "modules/voo.h"
#include "modules/ticket.h"

struct tup{

	float preco;
	int num_voo;
	float tempo;

};

typedef struct tup *TUPLE;

int aeroportos(){

	int acum = 0;

	FILE * a = fopen(AERO, "r");
	char line[LINE_BUFFER];

	while(fgets(line,LINE_BUFFER,a)!=NULL){
		acum++;
	}

	fclose(a);

	return acum;
}

#define NV aeroportos()

typedef struct aresta{

	int dest;
	struct aresta * prox;

} *LAdj, *GrafoL[];

char ** list_aeroport(int N){

	char ** aeroportos = malloc(sizeof(char*)*N);
	FILE * a = fopen(AERO, "r");
	char line[LINE_BUFFER];
	int i = 0;

	while(fgets(line,LINE_BUFFER,a)!=NULL){

		AEROPORTO a = create_aeroporto();
		set_aeroporto(a,line);
		aeroportos[i] = get_nome(a);
		i++;
		delete_aeroporto(a);

	}

	fclose(a);

	return aeroportos;
}

int get_indice_aeroport(char * aeroporto, char * aeroportos[]){

	int indice = 0;

	while(!strcmp(aeroporto,aeroportos[indice])) indice++;

	return indice;
}

char * get_aeroport_indice(int ind, char * aeroportos[]){

	char * aeroporto = aeroportos[ind];
	return aeroporto;

}

void voos_matriz(int N, int matriz[N][N]){

	FILE * v = fopen(FLIGHT, "r");
	char line[LINE_BUFFER];
	char * partida = NULL; char * chegada = NULL;
	char ** aero = list_aeroport(N);
	int p, c;

	while(fgets(line,LINE_BUFFER,v)!=NULL){
		
		VOOS v = create_voo();
		set_voo(v,line);
		partida = get_aeroport_partida(v);
		p = get_indice_aeroport(partida,aero);
		chegada = get_aeroport_chegada(v);
		c = get_indice_aeroport(chegada,aero);
		matriz[p][c] = 1;
		delete_voo(v);

	}

	fclose(v);

}

int directly_connected(char * partida, char * chegada){

	int r = 0;
	int N = aeroportos();
	char ** aero = list_aeroport(N);
	int matriz[N][N];

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matriz[i][j] = 0;
		}
	}
	
	voos_matriz(N, matriz);

	int p = get_indice_aeroport(partida, aero);
	int c = get_indice_aeroport(chegada, aero);

	if(matriz[p][c] == 1) r = 1;

	return r;
}


float tempo_total_direto(char * partida, char * chegada){

	float tempo = 0;

	FILE * v = fopen(FLIGHT, "r");
	char line[LINE_BUFFER];

	while(fgets(line,LINE_BUFFER,v)!=NULL){
		VOOS v = create_voo();
		set_voo(v,line);
		if((strcmp(get_aeroport_partida(v),partida)==0) && (strcmp(get_aeroport_chegada(v),chegada)==0)) {
			tempo = date_compare(get_data_partida(v),get_data_chegada(v));
			delete_voo(v);
			break;
		 } else delete_voo(v);

	}
	fclose(v);
	tempo = tempo / 3600;

	return tempo;
}

void swap_tup(int i, int j, TUPLE * res){

	TUPLE a = malloc(sizeof(TUPLE));
	a = res[j];
	res[j] = res[i];
	res[i] = a; 

}


TUPLE * preco_direto(char * partida, char * chegada){

	TUPLE * res = malloc(sizeof(TUPLE));
	FILE * t = fopen(TICKET, "r");
	char line[LINE_BUFFER]; char * aux = NULL;
	int i = 0;
	

	while(fgets(line,LINE_BUFFER,t)!=NULL){
		BILHETES b = create_ticket();
		set_ticket(b,line);
		aux = get_voo_ticket(b);

		VOOS vs = create_voo();
		set_ticket(vs,aux);

		if( (get_aeroport_partida(vs) ==  partida) && (get_aeroport_chegada(vs) == chegada) ){
			res[i]->preco = get_preco(b);
			res[i]->num_voo = get_num_voo(vs);
			res[i]->tempo = date_compare(get_data_partida(vs),get_data_chegada(vs)) / 3600;
			i++;
			delete_voo(vs);
			delete_ticket(b);
			break;
		}
		delete_voo(vs);
		delete_ticket(b);
	}

	fclose(t);

	return res;
}

int directly_connected_num(char * partida, char * chegada){

	int r = 0;
	if (directly_connected(partida,chegada) == 1){
		TUPLE * out = preco_direto(partida, chegada);
		r = out[0]->num_voo;
	}


	return r;
}

int count_direct_flights(TUPLE * t){

	int num = 0;

	for(int i =0;t[i]!=NULL;i++) num++;

	return num;
}

int cheap_direct(TUPLE * t, int N){

	int min = 100000; // preço absurdo
	for(int i=0;i<N;i++){
		if(min>t[i]->preco) min = t[i]->preco;
	}

	return min;
}

char ** cheaps(int ** escalas){

	int opt = 0, low_price = 1000000;
	TUPLE * t = malloc(sizeof(TUPLE));
	TUPLE * t2 = malloc(sizeof(TUPLE));
	TUPLE * t3 = malloc(sizeof(TUPLE));
	TUPLE * t4 = malloc(sizeof(TUPLE));

	while(*escalas){
		opt++;
	}

	char ** ans = malloc(sizeof(char*)*opt);

	switch(opt){

		case 3: // 2 escalas

			while(escalas){
				t = preco_direto(get_aeroport_indice(*escalas[0],list_aeroport(NV)), get_aeroport_indice(*escalas[1],list_aeroport(NV)));
				t2 = preco_direto(get_aeroport_indice(*escalas[1],list_aeroport(NV)), get_aeroport_indice(*escalas[2],list_aeroport(NV)));
				if (low_price > t[0]->preco + t2[0]->preco) {
					low_price = t[0]->preco + t2[0]->preco;
					ans[0] = get_aeroport_indice(*escalas[0],list_aeroport(NV));
					ans[1] = get_aeroport_indice(*escalas[1],list_aeroport(NV));
					ans[2] = get_aeroport_indice(*escalas[2],list_aeroport(NV));
				}
			}
			break;

		case 4: // 3 escalas
			while(escalas){
				t = preco_direto(get_aeroport_indice(*escalas[0],list_aeroport(NV)), get_aeroport_indice(*escalas[1],list_aeroport(NV)));
				t2 = preco_direto(get_aeroport_indice(*escalas[1],list_aeroport(NV)), get_aeroport_indice(*escalas[2],list_aeroport(NV)));
				t3 = preco_direto(get_aeroport_indice(*escalas[2],list_aeroport(NV)), get_aeroport_indice(*escalas[3],list_aeroport(NV)));
				if (low_price > t[0]->preco + t2[0]->preco + t3[0]->preco) {
					low_price = t[0]->preco + t2[0]->preco + t3[0]->preco;
					ans[0] = get_aeroport_indice(*escalas[0],list_aeroport(NV));
					ans[1] = get_aeroport_indice(*escalas[1],list_aeroport(NV));
					ans[2] = get_aeroport_indice(*escalas[2],list_aeroport(NV));
					ans[3] = get_aeroport_indice(*escalas[3],list_aeroport(NV));
				}
			}
			break;

		case 5: // 4 escalas
			while(escalas){
				t = preco_direto(get_aeroport_indice(*escalas[0],list_aeroport(NV)), get_aeroport_indice(*escalas[1],list_aeroport(NV)));
				t2 = preco_direto(get_aeroport_indice(*escalas[1],list_aeroport(NV)), get_aeroport_indice(*escalas[2],list_aeroport(NV)));
				t3 = preco_direto(get_aeroport_indice(*escalas[2],list_aeroport(NV)), get_aeroport_indice(*escalas[3],list_aeroport(NV)));
				t4 = preco_direto(get_aeroport_indice(*escalas[3],list_aeroport(NV)), get_aeroport_indice(*escalas[4],list_aeroport(NV)));
				if (low_price > t[0]->preco + t2[0]->preco + t3[0]->preco + t4[0]->preco) {
					low_price = t[0]->preco + t2[0]->preco + t3[0]->preco + t4[0]->preco;
					ans[0] = get_aeroport_indice(*escalas[0],list_aeroport(NV));
					ans[1] = get_aeroport_indice(*escalas[1],list_aeroport(NV));
					ans[2] = get_aeroport_indice(*escalas[2],list_aeroport(NV));
					ans[3] = get_aeroport_indice(*escalas[3],list_aeroport(NV));
					ans[4] = get_aeroport_indice(*escalas[4],list_aeroport(NV));
				}
			}
			break;

	}

	return ans;
}


LAdj append(int dest, LAdj cauda){
    LAdj novo = malloc(sizeof(struct aresta));
    novo->dest = dest;
    novo->prox = cauda;
    return novo;
}

void initGrafoL(GrafoL g, int N) {

    for (int i=0; i<N; i++)
        g[i] = NULL;
}

void fromMatriz(int N, int matriz[N][N], GrafoL out){
	initGrafoL(out, N);
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			if (matriz[i][j] == 1){
				out[i] = append(j, out[i]);
			}
		}
	}
}

int ** BF (GrafoL g, int or, int des, int opt, int v[], int p[], int l[]){
	int i, x; LAdj a;
	int q[NV], front, end;
	int ** results = malloc(sizeof(int*)*NV);
	for (i=0; i<NV; i++) {
		v[i] = 0;
		p[i] = -1;
		l[i] = -1;
	}		
	front = end = 0;
	q[end++] = or; //enqueue
	v[or] = 1; p[or]=-1;l[or]=0;
	i=1;
	while (v[a->dest] != des){
		x = q[front++]; //dequeue
		for (a=g[x]; a!=NULL; a=a->prox)
			if (!v[a->dest]){
				i++;
				v[a->dest]=1;
				p[a->dest]=x;
				l[a->dest]=1+l[x];
				q[end++]=a->dest; //enqueue
			}
	}
	return results;
}



char ** get_choices(char * aero_p, char *  aero_c, int opt, int N, int matriz[N][N]){

	char ** flight = malloc(sizeof(char*)*4);

	FILE * v = fopen(FLIGHT, "r");
	char line[LINE_BUFFER]; char def_line[LINE_BUFFER]; 
	TUPLE * tup = malloc(sizeof(TUPLE));
	int * vis = malloc(sizeof(int)*NV); int * pai = malloc(sizeof(int)*NV); int * lists = malloc(sizeof(int)*NV);
	int direct_cheap, i = 0, min = 72, atm_voo;
	float preco_def = 0, preco_min;
	char ** aeroports = list_aeroport(NV);
	GrafoL * out = malloc(sizeof(struct aresta)*NV);
	voos_matriz(N, matriz);
	fromMatriz(NV,matriz,*out);

	tup = preco_direto(aero_p, aero_c);
	direct_cheap = cheap_direct(tup,count_direct_flights(tup));

	// menor voo
	while(tup[i]!=NULL){
		if(min>tup[i]->tempo){
			min = tup[i]->tempo;
			atm_voo = tup[i]->num_voo;
			i++;
		}
	}
	
	int ** escalas_2 = BF(*out,get_indice_aeroport(aero_p, aeroports), get_indice_aeroport(aero_c, aeroports), 3, vis, pai, lists); // devolve indice aeroportos
	char ** barato_2 = cheaps(escalas_2); // voos mais baratos entre aeroportos

	TUPLE * tup_2_1= preco_direto(barato_2[0],barato_2[1]);
	TUPLE * tup_2_2 = preco_direto(barato_2[1],barato_2[2]);

	float preco_2 =  tup_2_1[0]->preco + tup_2_2[0]->preco;// precos dos voos

	int ** escalas_3 = BF(*out,get_indice_aeroport(aero_p, aeroports), get_indice_aeroport(aero_c, aeroports), 4, vis, pai, lists);
	char ** barato_3 = cheaps(escalas_3);

	TUPLE * tup_3_1 = preco_direto(barato_3[0],barato_3[1]);
	TUPLE * tup_3_2 = preco_direto(barato_3[1],barato_3[2]);
	TUPLE * tup_3_3 = preco_direto(barato_3[2],barato_3[3]);

	float preco_3 = tup_3_1[0]->preco + tup_3_2[0]->preco + tup_3_3[0]->preco;

	int ** escalas_4 = BF(*out,get_indice_aeroport(aero_p, aeroports), get_indice_aeroport(aero_c, aeroports), 5, vis, pai, lists);
	char ** barato_4 = cheaps(escalas_4);

	TUPLE * tup_4_1 = preco_direto(barato_4[0],barato_4[1]);
	TUPLE * tup_4_2 = preco_direto(barato_4[1],barato_4[2]);
	TUPLE * tup_4_3 = preco_direto(barato_4[2],barato_4[3]);
	TUPLE * tup_4_4 = preco_direto(barato_4[3],barato_4[4]);

	float preco_4 = tup_4_1[0]->preco + tup_4_2[0]->preco + tup_4_3[0]->preco + tup_4_4[0]->preco;


	while(fgets(line,LINE_BUFFER,v)!=NULL){
		VOOS vs = create_voo();
		set_voo(vs,line);

		VOOS vtmp = create_voo();
		
		switch(opt){

			case 0: // mais barato
				if(get_num_voo(vs) == direct_cheap) {  // por default o voo mais barato é o mais barato direto
					set_voo(vtmp,line);
					strcpy(def_line,line);
					preco_def = get_preco(vtmp);
					delete_voo(vtmp);
				}

				if(preco_def != 0) preco_min = mais_barato(preco_def, preco_2, preco_3, preco_4);

				if (preco_min == preco_def) *flight = def_line;
				else if (preco_min == preco_2) flight = barato_2;
				else if (preco_min == preco_3) flight = barato_3;
				else if (preco_min == preco_4) flight = barato_4;
				break;

			case 1: // mais rápido
				if(get_num_voo(vs)==atm_voo) *flight = line;
				break;

			case 2: // melhor com 2 escalas (o mais barato)
				flight = barato_2;
				break;

			case 3: // melhor com 3 escalas (o mais barato)
				flight = barato_3;
				break;

			case 4: // melhor com 4 escalas (o mais barato)
				flight = barato_4;
				break;

		}
		delete_voo(vs);
	}
	fclose(v);

	return flight;

}

