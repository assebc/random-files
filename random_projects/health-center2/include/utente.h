#ifndef UTENTE_H
#define UTENTE_H

typedef struct Utente {
    int codigoUtente;
    char nome[100];
    int codigoMedico;
    struct Utente * prox;
} Utente;

void inserirUtente(Utente** listaUtentes, int* codigoUtente);
Utente* consultarUtente(Utente* listaUtentes, int codigoUtente);
void editarUtente(Utente* listaUtentes);
void removerUtente(Utente** listaUtentes, int codigoUtente);
void listarUtentes(Utente* listaUtentes);
void guardarUtentes(Utente* listaUtentes);
void importarUtentes(Utente** listaUtentes, int* codigoUtente);

#endif 

