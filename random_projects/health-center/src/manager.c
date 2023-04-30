#include "../include/manager.h"

int addToFile(char * filename, void * p){
    char * buffer = malloc(sizeof(char)*LINE_BUFFER);
    char * q;
    FILE * fp = fopen(filename, "a+");
    if (!fp) { 
        perror("Error while opening file!\n");
        return 1;
    }
    USER u; MEDIC m;
    int opt = 2;
    if(strcmp(filename, utente)==0){
        u = (USER) p;
        opt = 1;
    } else{
        m = (MEDIC) p;
    }

    // dont read first line
    fgets(buffer,LINE_BUFFER,fp);

    while(fgets(buffer, LINE_BUFFER, fp) != NULL){
        while((q = strsep(&buffer, ",")) != NULL){
            switch(opt){
                case 1:
                    if(atoi(q) == u->id){
                        free(q);
                        return 1;
                    }
                    break;
                case 2:
                    if(atoi(q) == m->id){
                        free(q);
                        return 1;
                    }
                    break;
            }
            break;
        }
        free(q);
    }
    switch(opt){
        case 1:
            fprintf(fp, "%d,%s,%d\n", u->id, u->name, u->id_medic);
            break;
        case 2:
            fprintf(fp, "%d,%s,%p", m->id, m->name, &m->q);
            break;
    }

    switch(opt){
        case 1:
            free(u);
            break;
        case 2:
            free(m);
            break;
    }

    fclose(fp);
    return 0;
}


int editFile(char * filename, void * p){
    char * buffer = malloc(sizeof(char)*LINE_BUFFER);
    char * q;
    FILE * fp = fopen(filename, "r+");
    if (!fp) { 
        perror("Error while opening file!\n");
        return 1;
    }

    USER u; MEDIC m;
    int opt = 2;
    if(strcmp(filename, utente)==0){
        u = (USER) p;
        opt = 1;
    } else{
        m = (MEDIC) p;
    }

    // dont read first line
    fgets(buffer,LINE_BUFFER,fp);

    while(fgets(buffer, LINE_BUFFER, fp) != NULL){
        while((q = strsep(&buffer, ",")) != NULL){
            switch(opt){
                case 1:
                    if(atoi(q) == u->id){
                        fseek(fp, LINE_BUFFER, SEEK_CUR);
                        fprintf(fp, "%d,%s,%d\n", u->id, u->name, u->id_medic);
                        free(q);
                        fclose(fp);
                        return 0;
                    }
                    break;
                case 2:
                    if(atoi(q) == m->id){
                        fseek(fp, LINE_BUFFER, SEEK_CUR);
                        fprintf(fp, "%d,%s,%p", m->id, m->name, &m->q);
                    }
                    free(q);
                    fclose(fp);
                    return 0;
                    break;
            }
        }
        free(q);
    }

    switch(opt){
        case 1:
            free(u);
            break;
        case 2:
            free(m);
            break;
    }

    fclose(fp);
    perror("ID not found!\n");
    return 1;
}

LLIST * readFile(char * filename){
    LLIST * res = malloc(sizeof(struct node)*1000);
    FILE * fp = fopen(filename, "r");
    USER u; MEDIC m;
    if(!fp){
        perror("Error while opening file!\n");
        return NULL;
    }
    char * buffer = malloc(sizeof(char)*LINE_BUFFER);
    fgets(buffer,LINE_BUFFER,fp);
    int opt = 2;
    if(strcmp(filename,utente)==0){
        opt = 1;
    } 

    char * q; 
    long unsigned int q_pointer;
    int ids, id_medic;
    char * name = malloc(sizeof(char)*1024);
    int i;
    while(fgets(buffer, LINE_BUFFER, fp) != NULL){
        while((q = strsep(&buffer, ",")) != NULL){
                if(i == 0){
                    ids = atoi(q);
                } else if (i == 1){
                    strcpy(name, q);
                } else{
                    switch(opt){
                        case 1:
                            id_medic = atoi(q);
                            break;
                        case 2:
                            q_pointer = strtoul(q, NULL, 16);
                            break;
                    }
                }
            i++;
        }
        switch(opt){
            case 1:
                u = createUser(ids, name, id_medic);
                insert(res, u);
                break;
            
            case 2:
                m = createMedic(ids, name, (QUEUE)q_pointer);
                insert(res, m);
                break;
        }
        i = 0;
    }
    free(name);
    fclose(fp);
    return res;
}


int removeFromFile(char * filename, const int id){
    FILE * fp = fopen(filename, "r");
    FILE * tmp = fopen(temp, "w");

    if(!fp || !tmp){
        perror("Error while opening files!\n");
        return 1;
    }

    char * buffer = malloc(sizeof(char)*LINE_BUFFER);
    int found = 0;

    // dont read first line
    fgets(buffer,LINE_BUFFER,fp);

    while (fgets(buffer, LINE_BUFFER, fp)) {
        char * q = strsep(&buffer, ",");
        if (atoi(q) != id) {
            fputs(buffer, tmp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(tmp);

    if (found) {
        remove(filename);
        rename(temp, filename);
    } else {
        remove(temp);
        perror("ID not found!\n");
        return 1;
    }
    return 0;
}


int getID(char * filename){
    int last_id;
    if(strcmp(filename, utente)==0) last_id = 1001;
    else last_id = 1;
    char * buffer = malloc(sizeof(char)*LINE_BUFFER);
    char * q;
    FILE * fp = fopen(filename, "r");
    if (!fp) { 
        perror("Error while opening file!\n");
        return 1;
    }

    // dont read first line
    fgets(buffer,LINE_BUFFER,fp);

    while(fgets(buffer, LINE_BUFFER, fp) != NULL){
        while((q = strsep(&buffer, ",")) != NULL){
            last_id = atoi(q);
            break;
        }        
        free(q);
    }
    fclose(fp);
    return last_id;
}
