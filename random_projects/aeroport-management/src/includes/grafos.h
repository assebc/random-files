#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct aresta *LAdj;
typedef struct aresta *GrafoL[];
typedef struct tup *TUPLE;

int aeroportos();
char ** list_aeroport(int N);
int get_indice_aeroport(char * aeroporto, char * aeroportos[]);
char * get_aeroport_indice(int ind, char * aeroportos[]);
void voos_matriz(int N, int matriz[N][N]);
int directly_connected(char * partida, char * chegada);
float tempo_total_direto(char * partida, char * chegada);
void swap_tup(int i, int j, TUPLE * res);
TUPLE * preco_direto(char * partida, char * chegada);
int directly_connected_num(char * partida, char * chegada);
int count_direct_flights(TUPLE * t);
int cheap_direct(TUPLE * t, int N);
char ** cheaps(int ** escalas);
LAdj append(int dest, LAdj cauda);
void initGrafoL(GrafoL g);
void fromMatriz(int N, int matriz[N][N], GrafoL out);

int ** BF (GrafoL g, int or, int des, int opt, int v[], int p[], int l[]);

char ** get_choices(char * aero_p, char *  aero_c, int opt, int N, int matriz[N][N]);

#endif