#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/user.h"

void createUser(const int id, char * name, const int id_medic){
    USER u = malloc(sizeof(struct user));
    u->id = id;
    u->name = name;
    u->id_medic = id_medic;
}

void editUser(USER u, char * name, const int id_medic){
    changeName(u,name);
    changeMedic(u,id_medic);
}

void changeName(USER u, char * name){
    u->name = name;
}

void changeMedic(USER u, const int id_medic){
    u->id_medic = id_medic;
}

void listUser(USER u){
    printf("USER: %d, %s, %d", u->id, u->name, u->id_medic);
}