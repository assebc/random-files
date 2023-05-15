#include "../include/medic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MEDIC createMedic(const int id, char* name, QUEUE q) {
    MEDIC m = malloc(sizeof(struct medic));
    m->id = id;
    m->name = malloc(strlen(name) + 1);
    strcpy(m->name, name);
    m->q = q;
    return m;
}

MEDIC createMedic2(char* buffer) {
    int id;
    char* name = malloc(sizeof(char) * 1024);
    char* q;
    unsigned long q_pointer;
    int i = 0;
    while ((q = strsep(&buffer, ",")) != NULL) {
        if (i == 0)
            id = atoi(q);
        else if (i == 2)
            strcpy(name, q);
        else
            q_pointer = strtoul(q, NULL, 16);
        i++;
    }
    QUEUE que = (QUEUE)q_pointer;
    return createMedic(id, name, que);
}

MEDIC editMedic(MEDIC m, char* name, QUEUE q) {
    changeNameMedic(m, name);
    changeQueue(m, q);
    return m;
}

void changeNameMedic(MEDIC m, char* name) {
    free(m->name);
    m->name = malloc(strlen(name) + 1);
    strcpy(m->name, name);
}

void changeQueue(MEDIC m, QUEUE q) {
    m->q = q;
}

MEDIC removeFromQueue(MEDIC m) {
    dequeue(m->q);
    return m;
}

MEDIC addToQueue(MEDIC m, USER u) {
    enqueue(m->q, u);
    return m;
}

void listMedic(MEDIC m) {
    printf("MEDIC: %d, %s\n", m->id, m->name);
    printQueue(m->q);
}