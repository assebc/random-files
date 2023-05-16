#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/medico.h"

Medico* listaMedicos = NULL; // pointer to the first element of the list of doctors

// Insert a new doctor at the end of the linked list of doctors
void inserirMedico(Medico** listaMedicos, int codigoMedico) {
    char nome[100];
    printf("Digite o nome do medico: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    
    Medico* novoMedico = malloc(sizeof(Medico)); // allocate memory dynamically
    novoMedico->codigoMedico = ++(codigoMedico); // increment a code for each new doctor added

    strcpy(novoMedico->nome, nome);
    novoMedico->prox = NULL;
    novoMedico->fila_espera = NULL;
    
    if (*listaMedicos == NULL) {
        *listaMedicos = novoMedico;
    } else {
        Medico* p = *listaMedicos;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novoMedico;
    }
    printf("\nMedico inserido com sucesso!\n");
    printf("Medico com ID %d\n", novoMedico->codigoMedico);
}

// Consult a doctor by code
Medico* consultarMedico(Medico* listaMedicos, int codigoMedico) {
    while (listaMedicos != NULL && listaMedicos->codigoMedico != codigoMedico) {
        listaMedicos = listaMedicos->prox;
    }
    
    if (listaMedicos == NULL) {
        printf("Medico com codigo %d nao encontrado!\n", codigoMedico);
        return NULL;
    }
    
    printf("Codigo: %d\n", listaMedicos->codigoMedico);
    printf("Nome: %s\n", listaMedicos->nome);
    return listaMedicos;
}

// Edit the information of a doctor
void editarMedico(Medico* listaMedicos) {
    int codigoMedico;
    printf("Insira o codigo do medico que deseja editar: ");
    scanf("%d", &codigoMedico);
    
    Medico* p = consultarMedico(listaMedicos, codigoMedico);
    
    if (p == NULL) {
        printf("Medico com o codigo %d nao encontrado.\n", codigoMedico);
        return;
    }
    
    printf("Insira o novo nome: ");
    scanf("%s", p->nome);
}

// Remove a doctor from the linked list
void removerMedico(Medico** listaMedicos, int codigoMedico) {
    if (*listaMedicos == NULL) {
        printf("Lista de medicos vazia!\n");
        return;
    }
    
    Medico* p = *listaMedicos;
    Medico* ant = NULL;
    
    while (p != NULL && p->codigoMedico != codigoMedico) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) {
        printf("Medico com codigo %d nao encontrado!\n", codigoMedico);
        return;
    }
    
    if (ant == NULL) {
        *listaMedicos = p->prox;
    } else {
        ant->prox = p->prox; // ant refers to the doctor prior to the one to be removed
    }
    
    printf("Medico removido com sucesso!\n");
    printf("Codigo: %d\n", p->codigoMedico);
    printf("Nome: %s\n", p->nome);
    free(p);
}

// List all doctors
void listarMedicos(Medico* listaMedicos) {
    if (listaMedicos == NULL) {
        printf("Lista de medicos vazia!\n");
        return;
    }
    
    Medico* p = listaMedicos;
    while (p != NULL) {
        printf("Codigo: %d\n", p->codigoMedico);
        printf("Nome: %s\n", p->nome);
        p = p->prox;
    }
}

// Save the doctors' information to a .txt file
void guardarMedicos(Medico* listaMedicos) {
    FILE* arquivo = fopen("medicos.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo medicos.txt!\n");
        return;
    }
    
    Medico* p = listaMedicos;
    while (p != NULL) {
        p->nome[strcspn(p->nome, "\n")] = '\0';
        fprintf(arquivo, "%d,%s,%p\n", p->codigoMedico, p->nome,&p->fila_espera);
        p = p->prox;
    }
    
    fclose(arquivo);
    printf("Dados dos medicos salvos com sucesso em medicos.txt!\n");
}

// Import the doctors' information from the txt file
int importarMedicos(Medico** listaMedicos) {
    FILE* arquivo = fopen("medicos.txt", "r");
    int maxCode = 0;
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo medicos.txt!\n");
        return 0;
    }

    while (!feof(arquivo)) {
        int codigoMedico;
        char nome[100];
        unsigned long int fila_espera_pointer;

        if (fscanf(arquivo, "%d,%[^,],%lu\n", &codigoMedico, nome, &fila_espera_pointer) != 3) {
            break;
        }

        Medico* novoMedico = malloc(sizeof(Medico)); // allocate memory dynamically
        novoMedico->codigoMedico = codigoMedico;
        strcpy(novoMedico->nome, nome);
        novoMedico->prox = NULL;
        novoMedico->fila_espera = (Utente*)fila_espera_pointer;
        if(maxCode<codigoMedico) maxCode = codigoMedico;
        if (*listaMedicos == NULL) {
            *listaMedicos = novoMedico;
        } else {
            Medico* p = *listaMedicos;
            while (p->prox != NULL) {
                p = p->prox;
            }
            p->prox = novoMedico;
        }
    }

    fclose(arquivo);
    printf("\nInformacoes dos medicos carregadas do arquivo com sucesso!\n");
    return maxCode;
}


void inserirFilaEspera(Medico* listaMedicos, int codigoMedico, Utente t) {
    while (listaMedicos != NULL) {
        if (listaMedicos->codigoMedico == codigoMedico) {
            Utente* fila = listaMedicos->fila_espera;
            if (fila == NULL) {
                listaMedicos->fila_espera = &t;
            } else {
                while (fila->prox != NULL) {
                    fila = fila->prox;
                }
                fila->prox = &t;
            }
            return;
        }
        listaMedicos = listaMedicos->prox;
    }
}

void proximoFila(Medico* listaMedicos, int codigoMedico) {
    while (listaMedicos != NULL) {
        if (listaMedicos->codigoMedico == codigoMedico) {
            if (listaMedicos->fila_espera != NULL) {
                Utente* proximo = listaMedicos->fila_espera;
                listaMedicos->fila_espera = listaMedicos->fila_espera->prox;
                free(proximo);
            } else {
                printf("Fila de espera vazia para o medico com codigo %d.\n", codigoMedico);
            }
            return;
        }
        listaMedicos = listaMedicos->prox;
    }
}

int tamanhoFila(Medico* listaMedicos, int codigoMedico) {
    int res = 0;
    while (listaMedicos != NULL) {
        if (listaMedicos->codigoMedico == codigoMedico) {
            Utente* fila = listaMedicos->fila_espera;
            while (fila) {
                res++;
                fila = fila->prox;
            }
            break;
        }
        listaMedicos = listaMedicos->prox;
    }
    return res;
}