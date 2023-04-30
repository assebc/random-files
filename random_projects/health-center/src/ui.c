#include "../include/ui.h"

int id_medic = 1;
int id_user = 1001;
LLIST *medics, *users;

void menu(){
    int opt = -1;
    id_medic = getID(medico);
    id_user = getID(utente);
    medics = readFile(medico);
    users = readFile(utente);
    printf("===== CENTRO DE SAUDE =====\n");
    printf("UTENTE -> 1\n");
    printf("MEDICO -> 2\n");
    printf("OUTROS -> 3\n");
    printf("SAIR -> 0\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt){
        case 0:
            return;
            break;

        case 1:
            menuUser();
            break;
        
        case 2:
            menuMedic();
            break;

        case 3:
            queries();
            break;
        
    }
    
}

void menuUser(){
    int opt = -1;
    int ids;
    int id_medics;
    LLIST tmp, tmp2;
    USER u; MEDIC m;
    char * name = malloc(sizeof(char)*1024);
    printf("===== MENU UTENTE =====\n");
    printf("ENTRAR NO CENTRO DE SAUDE -> 1\n");
    printf("INSERIR NOVO UTENTE -> 2\n");
    printf("EDITAR UTENTE -> 3\n");
    printf("CONSULTAR UTENTE -> 4\n");
    printf("REMOVER UTENTE -> 5\n");
    printf("LISTAR UTENTES -> 6\n\n");
    printf("VOLTAR -> 0\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opt);
    printf("\n");

    switch(opt){
        case 0:
            menu();
            break;

        case 1:
            printf("INSIRA SEU NUMERO DE UTENTE: ");
            scanf("%d", &ids);
            if(ids<id_user){
                tmp = *users;
                tmp2 = *medics;
                while(tmp != NULL){
                    u = tmp->data;
                    if (u->id == ids) {
                        id_medics = u->id_medic;
                        while(tmp2 != NULL){
                            m = tmp2->data;
                            if(m->id == id_medics){
                                enqueue(m->q, u);
                                break;
                            }
                            tmp2 = tmp2->next;
                        }
                        break;
                    }
                    tmp = tmp->next;
                }
            } else perror("Invalid user id!");

            break;
        
        case 2:
            printf("\nINSIRA SEU NOME\n");
            scanf("%s", name);
            printf("\nINSIRA ID DO SEU MEDICO\n");
            scanf("%d", &id_medics);
            printf("\n");
            u = createUser(id_user++,name,id_medics);
            addToFile(utente,u);
            users = readFile(utente);
            break;

        case 3:
            printf("\nINSIRA SEU NUMERO DE UTENTE\n");
            scanf("%d", &ids);
            printf("\nALTERE SEU NOME\n");
            scanf("%s", name);
            printf("\nALTERE ID DO SEU MEDICO\n");
            scanf("%d", &id_medics);
            printf("\n");
            u = createUser(ids, name, id_medics);
            editFile(utente, u);
            users = readFile(utente);
            break;

        case 4:
            printf("\nINSIRA SEU ID\n");
            scanf("%d", &ids);
            printf("\n");
            tmp = *users;
            while(tmp != NULL){
                u = tmp->data;
                if (u->id == ids) {
                    listUser(u);
                    break;
                }
                tmp = tmp->next;
            }
            break;

        case 5:
            printf("\nINSIRA SEU NUMERO DE UTENTE\n");
            scanf("%d", &ids);
            printf("\n");
            removeFromFile(utente, ids);
            users = readFile(utente);
            break;
        
        case 6:
            tmp = *users;
            while(tmp != NULL){
                u = tmp->data;
                listUser(u);
            }
            break;
    }
    free(name);
    free(u);
    free(tmp);
    menuUser();
}

void menuMedic(){
    int opt = -1, ids;
    char * name = malloc(sizeof(char)*1024);
    LLIST tmp;
    MEDIC m;
    printf("===== MENU MEDICO =====\n");
    printf("ATENDER UTENTE -> 1\n");
    printf("INSERIR NOVO MEDICO -> 2\n");
    printf("EDITAR MEDICO -> 3\n");
    printf("CONSULTAR MEDICO -> 4\n");
    printf("REMOVER MEDICO -> 5\n");
    printf("LISTAR MEDICOS -> 6\n\n");
    printf("VOLTAR -> 0\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opt);
    printf("\n");

    switch(opt){
        case 0:
            menu();
            break;

        case 1:
            printf("INSIRA SEU NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            printf("\n");
            tmp = *medics;
            while(tmp != NULL){
                m = (MEDIC)tmp->data;
                if(m->id == ids){
                    removeFromQueue(m);
                    editFile(medico,m);
                    medics = readFile(medico);
                    break;
                }
                tmp = tmp->next;
            }
            break;
        
        case 2:
            printf("\nINSIRA SEU NOME\n");
            scanf("%s", name);
            m = createMedic(id_medic++, name, malloc(sizeof(struct queue) * MAX_QUEUE_SIZE));
            addToFile(medico, m);
            medics = readFile(medico);
            break;

        case 3:
            printf("\nINSIRA SEU NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            printf("\nALTERE SEU NOME\n");
            scanf("%s", name);
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                if (m->id == ids) {
                    break;
                }
                tmp = tmp->next;
            }
            m->name = name;
            editFile(medico, m);
            medics = readFile(medico);
            break;

        case 4:
            printf("\nINSIRA SEU NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                if (m->id == ids) {
                    listMedic(m);
                    break;
                }
                tmp = tmp->next;
            }
            break;
            
        case 5:
            printf("\nINSIRA SEU NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            printf("\n");
            removeFromFile(medico, ids);
            medics = readFile(medico);
            break;

        case 6:
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                listMedic(m);
            }
            break;

    }
    free(name);
    free(tmp);
    free(m);
    menuMedic();
}

void queries(){
    int opt = -1, ids, len = 0, id_meds = 1;
    MEDIC m;
    LLIST tmp;
    printf("===== OUTROS =====\n");
    printf("LISTAR UTENTES EM ESPERA -> 1\n");
    printf("NUMERO DE UTENTES EM ESPERA -> 2\n");
    printf("MAIOR LISTA DE ESPERA -> 3\n");
    printf("LISTAR TODOS OS UTENTES -> 4\n");
    printf("VOLTAR -> 0\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opt);
    printf("\n");

    switch(opt){
        case 0:
            menu();
            break;

        case 1:
            printf("\nINSIRA NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            printf("\n");
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                if(m->id == ids){
                    printQueue(m->q);
                    break;
                }
                tmp = tmp->next;
            }
            break;
        
        case 2:
            printf("\nINSIRA NUMERO DE MEDICO\n");
            scanf("%d", &ids);
            printf("\n");
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                if(m->id == ids){
                    size(m->q);
                    break;
                }
                tmp = tmp->next;
            }
            break;

        case 3:
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                int len_tmp = size(m->q);
                if(len < len_tmp){
                    len = len_tmp;
                    id_meds = m->id;
                }
                tmp = tmp->next;
            }
            printf("MEDICO COM MAIOR FILA DE ESPERA: %d\n", id_meds);
            break;

        case 4:
            tmp = *medics;
            while(tmp != NULL){
                m = tmp->data;
                printQueue(m->q);
                tmp = tmp->next;
            }
            break;

    }
    free(tmp);
    free(m);
    queries();
}
