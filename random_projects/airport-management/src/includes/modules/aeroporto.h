#ifndef AEROPORTO_H
#define AEROPORTO_H

typedef struct aeroport *AEROPORTO;

void * create_aeroporto();
void delete_aeroporto(void * a);

void set_cod_IATA(AEROPORTO a, char * s);
void set_nome(AEROPORTO a, char * s);
void set_cidade(AEROPORTO a, char * s);
void set_altitude(AEROPORTO a, int x);
void set_aeroporto(void * a, char * line);

char * get_cod_IATA(void * a);
char * get_nome(void * a);
char * get_cidade(void * a);
int get_altitude(void * a);

void print_aeropoto(void * a);
void copy_aeroporto(void* dst, void* src);

#endif