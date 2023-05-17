#ifndef MEDICO_H
#define MEDICO_H

#include "../include/utente.h"

typedef struct Medico {
    int codigoMedico;
    char nome[100];
    struct Medico *prox; //ponteiro para a próxima estrutura utente
    Utente * fila_espera;
} Medico;

int inserirMedico(Medico** listaMedicos, int codigoMedico);
Medico* consultarMedico(Medico* listaMedicos, int codigoMedico);
void editarMedico(Medico* listaMedicos);
void removerMedico(Medico** listaMedicos, int codigoMedico);
void listarMedicos(Medico* listaMedicos);
void guardarMedicos(Medico* listaMedicos);
int importarMedicos(Medico** listaMedicos);
Medico * inserirFilaEspera(Medico* listaMedicos, int codigoMedico, Utente t);
void proximoFila(Medico * listaMedicos, int codigoMedico);
int tamanhoFila(Medico * listaMedicos, int codigoMedico);

#endif /* MEDICO_H */

