#ifndef UTENTE_H
#define UTENTE_H

typedef struct Utente {
    int codigoUtente;
    char nome[100];
    int codigoMedico;
    struct Utente * prox;
} Utente;

int inserirUtente(Utente** listaUtentes, int codigoUtente, int codigoMedicos);
Utente* consultarUtente(Utente* listaUtentes, int codigoUtente);
void editarUtente(Utente* listaUtentes);
void removerUtente(Utente** listaUtentes, int codigoUtente);
void listarUtentes(Utente* listaUtentes);
void listarUtentes2(Utente** listaUtentes, int codMedico);
void guardarUtentes(Utente* listaUtentes);
int importarUtentes(Utente** listaUtentes);
int tamanho(Utente * listaUtentes);

#endif 

