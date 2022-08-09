#ifndef AVIOES_H
#define AVIOES_H

typedef struct avioes *AVIOES;

void * create_aviao();
void delete_aviao(void * a);

void set_cod_registo(AVIOES a, char * s);
void set_marca(AVIOES a, char * s);
void set_modelo(AVIOES a, char * s);
void set_num_lugares(AVIOES a, int x);
void set_velocidade_cruzeiro(AVIOES a, int x);
void set_consumo_medio(AVIOES a, float x);
void set_aviao(void * a, char * line);

char * get_cod_registo(void * a);
char * get_marca(void * a);
char * get_modelo(void * a);
int get_num_lugares(void * a);
int get_velocidade_cruzeiro(void * a);
float get_consumo_medio(void * a);

void print_aviao(void * a);
void copy_aviao(void* dst, void* src);

#endif