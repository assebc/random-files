#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/medic.h"


void createMEDIC(const int id, char * name){
    MEDIC m = malloc(sizeof(struct medic));
    m->id = id;
    m->name = name;
}

void editMEDIC(MEDIC m, char * name, const int id_medic){
    changeName(m,name);
}

void changeName(MEDIC m, char * name){
    m->name = name;
}

void listMedic(MEDIC m){
    printf("MEDIC: %d, %s", m->id, m->name);
}