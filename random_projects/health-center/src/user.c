#include "../include/user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

USER createUser(const int id, char* name, const int id_medic) {
    USER u = malloc(sizeof(struct user));
    u->id = id;
    u->name = malloc(strlen(name) + 1);
    strcpy(u->name, name);
    u->id_medic = id_medic;
    return u;
}

USER createUser2(char* buffer) {
    int id, id_medic;
    char* name = malloc(sizeof(char) * 1024);
    char* q;
    int i = 0;
    while ((q = strsep(&buffer, ",")) != NULL) {
        if (i == 0)
            id = atoi(q);
        else if (i == 2)
            strcpy(name, q);
        else
            id_medic = atoi(q);
        i++;
    }
    return createUser(id, name, id_medic);
}

USER editUser(USER u, char* name, const int id_medic) {
    changeNameUser(u, name);
    changeMedic(u, id_medic);
    return u;
}

USER changeNameUser(USER u, char* name) {
    free(u->name);
    u->name = malloc(strlen(name) + 1);
    strcpy(u->name, name);
    return u;
}

USER changeMedic(USER u, const int id_medic) {
    u->id_medic = id_medic;
    return u;
}

void listUser(USER u) {
    printf("USER: %d, %s, %d\n", u->id, u->name, u->id_medic);
}