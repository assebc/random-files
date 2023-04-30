#ifndef MEDIC_H
#define MEDIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "user.h"

typedef struct medic{
    int id;
    char * name;
    QUEUE q;
} * MEDIC;

MEDIC createMedic(const int id, char * name, QUEUE q);
MEDIC createMedic2(char * buffer);
MEDIC editMedic(MEDIC m, char * name, QUEUE q);
void changeNameMedic(MEDIC m, char * name);
void changeQueue(MEDIC m, QUEUE q);
MEDIC removeFromQueue(MEDIC m);
MEDIC addToQueue(MEDIC m, USER u);
void listMedic(MEDIC m);

#endif

