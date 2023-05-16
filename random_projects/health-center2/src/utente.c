#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utente.h"

Utente *listaUtentes = NULL;

// Inserir um novo utente no final da lista ligada de utentes
void inserirUtente(Utente **listaUtentes, int codigoUtente, int codigoMedicos) {
    int codigoMedico = 0;
    char nome[100];
    printf("Digite o nome do utente: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    printf("Digite o codigo do medico: ");
    scanf("%d", &codigoMedico);
    while(codigoMedico>codigoMedicos){
        printf("\n Codigo do medico inválido, tente novamente: ");
        scanf("%d", &codigoMedico);
    }

    Utente *novoUtente = malloc(sizeof(Utente)); // aloca memoria dinamicamente
    novoUtente->codigoUtente = ++(codigoUtente); // incrementa um codigo para cada novo utente adicionado
    strcpy(novoUtente->nome, nome);
    novoUtente->codigoMedico = codigoMedico;
    novoUtente->prox = NULL;

    if (*listaUtentes == NULL) {
        *listaUtentes = novoUtente;
    } else {
        Utente *p = *listaUtentes;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novoUtente;
    }
    printf("\nUtente inserido com sucesso!\n");
    printf("Utente com ID %d\n", novoUtente->codigoUtente);

}

// Consultar um utente por codigo
Utente* consultarUtente(Utente *listaUtentes, int codigoUtente) {
    Utente *p = listaUtentes;
    while (p != NULL && p->codigoUtente != codigoUtente) {
        p = p->prox;
    }

    if (p == NULL) {
        printf("Utente com codigo %d nao encontrado!\n", codigoUtente);
        return NULL;
    }
    printf("Codigo: %d\n", p->codigoUtente);
    printf("Nome: %s\n", p->nome);
    printf("Codigo do medico: %d\n", p->codigoMedico);
    return p;
}

// Editar as informacoes de um utente
void editarUtente(Utente *listaUtentes) {
    int codigoUtente;
    printf("Insira o codigo do utente que deseja editar: ");
    scanf("%d", &codigoUtente);

    Utente *p = listaUtentes;
    while (p != NULL && p->codigoUtente != codigoUtente) {
        p = p->prox;
    }

    if (p == NULL) {
        printf("\nUtente com o codigo %d nao encontrado.\n", codigoUtente);
        return;
    }

    int opcao;
    do {
        printf("\n1 - Editar nome\n");
        printf("2 - Editar codigo do medico\n");
        printf("0 - Sair\n");
        printf("Insira a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nInsira o novo nome: ");
                scanf("%s", p->nome);
                break;
            case 2:
                printf("\nInsira o novo codigo do medico: ");
                scanf("%d", &p->codigoMedico);
                break;
            case 0:
                printf("\nSaindo do modo de edicao.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
        }
    } while (opcao != 0);
}

// Remover um utente da lista ligada
void removerUtente(Utente **listaUtentes, int codigoUtente) {
    if (*listaUtentes == NULL) {
        printf("Lista de utentes vazia!\n");
        return;
    }

    Utente *p = *listaUtentes;
    Utente *ant = NULL;

    while (p != NULL && p->codigoUtente != codigoUtente) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        printf("Utente com codigo %d nao encontrado!\n", codigoUtente);
        return;
    }

    if (ant == NULL) {
        *listaUtentes = p->prox;
    } else {
        ant->prox = p->prox; // ant refere-se ao utente anterior ao que sera removido
    }

    printf("Utente removido com sucesso!\n");
    printf("Codigo: %d\n", p->codigoUtente);
    printf("Nome: %s\n", p->nome);
    printf("Codigo do medico: %d\n", p->codigoMedico);
    free(p); // liberta a memoria alocada dinamicamente
}

// Listar todos os utentes
void listarUtentes(Utente *listaUtentes) {
    if (listaUtentes == NULL) {
        printf("\nLista de utentes vazia!\n");
        return;
    }

    Utente *p = listaUtentes;

    while (p != NULL) {
        printf("Codigo: %d\n", p->codigoUtente);
        printf("Nome: %s\n", p->nome);
        printf("Codigo do medico: %d\n\n", p->codigoMedico);
        p = p->prox;
    }
}

// Guardar as informacoes dos utentes num arquivo
void guardarUtentes(Utente *listaUtentes) {
    FILE *arquivo = fopen("utentes.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo utentes.txt!\n");
        return;
    }

    Utente *p = listaUtentes;
    while (p != NULL) {
        p->nome[strcspn(p->nome, "\n")] = '\0';
        fprintf(arquivo, "%d,%s,%d\n", p->codigoUtente, p->nome, p->codigoMedico);
        p = p->prox;
    }

    fclose(arquivo);
    printf("Dados dos utentes salvos com sucesso em utentes.txt!\n");
}

// Importar as informacoes dos utentes do arquivo txt
int importarUtentes(Utente** listaUtentes) {
    FILE* arquivo = fopen("utentes.txt", "r");
    int maxCode = 0;
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo utentes.txt!\n");
        return 0;
    }

    while (!feof(arquivo)) {
        int codigoUtente, codigoMedico;
        char nome[100];

        if (fscanf(arquivo, "%d,%[^,],%d\n", &codigoUtente, nome, &codigoMedico) != 3) {
            break;
        }

        Utente* novoUtente = malloc(sizeof(Utente)); // allocate memory dynamically
        novoUtente->codigoUtente = codigoUtente;
        strcpy(novoUtente->nome, nome);
        novoUtente->codigoMedico = codigoMedico;
        novoUtente->prox = NULL;
        if(maxCode<novoUtente->codigoUtente) maxCode = novoUtente->codigoUtente;
        if (*listaUtentes == NULL) {
            *listaUtentes = novoUtente;
        } else {
            Utente* p = *listaUtentes;
            while (p->prox != NULL) {
                p = p->prox;
            }
            p->prox = novoUtente;
        }
    }

    fclose(arquivo);
    printf("\nInformacoes dos utentes carregadas do arquivo com sucesso!\n");
    return maxCode;
}

int tamanho(Utente * listaUtentes){
    Utente * tmp = listaUtentes;
    int res = 0;
    while(tmp!=NULL){res++; tmp = tmp->prox; } 
    return res;
}

void listarUtentes2(Utente** listaUtentes, int codMedico){
    Utente * p = *listaUtentes;
    while (p != NULL) {
        if(p->codigoMedico == codMedico){
            printf("Codigo: %d\n", p->codigoUtente);
            printf("Nome: %s\n", p->nome);
            printf("Codigo do medico: %d\n\n", p->codigoMedico);
        }
        p = p->prox;
    }
}
