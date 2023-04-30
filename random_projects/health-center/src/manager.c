#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/define.h"
#include "../include/manager.h"

int addToFile(char * filename, void * p){
    char buffer[LINE_BUFFER];
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
        free(m);
        opt = 1;
    } else{
        m = (MEDIC) p;
        free(u);
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
            fputs("%d,%s,%d\n", u->id, u->name, u->id_medic, fp);
            break;
        case 2:
            fputs("%d,%s\n", m->id, m->name, fp);
            break;
    }
    fclose(fp);
    return 0;
}


int editFile(char * filename, void * p){
    char buffer[LINE_BUFFER];
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
        free(m);
        opt = 1;
    } else{
        m = (MEDIC) p;
        free(u);
    }

    // dont read first line
    fgets(buffer,LINE_BUFFER,fp);

    while(fgets(buffer, LINE_BUFFER, fp) != NULL){
        while((q = strsep(&buffer, ",")) != NULL){
            switch(opt){
                case 1:
                    if(atoi(q) == u->id){
                        fseek(fp, LINE_BUFFER, SEEK_CUR);
                        fputs("%d,%s,%d\n", u->id, u->name, u->id_medic, fp);
                        free(q);
                        fclose(fp);
                        return 0;
                    }
                    break;
                case 2:
                    if(atoi(q) == m->id){
                        fseek(fp, LINE_BUFFER, SEEK_CUR);
                        fputs("%d,%s\n", m->id, m->name, fp);
                    }
                    free(q);
                    fclose(fp);
                    return 0;
                    break;
            }
        }
        free(q);
    }
    fclose(fp);
    perror("ID not found!\n");
    return 1;
}


int removeFromFile(char * filename, const int id){
    FILE * fp = fopen(filename, "r");
    FILE * tmp = fopen(temp, "w");

    if(!fp || !tmp){
        perror("Error while opening files!\n");
        return 1;
    }

    char buffer[LINE_BUFFER];
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
