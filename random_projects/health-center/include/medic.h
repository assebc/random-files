#ifndef MEDIC_H
#define MEDIC_H

typedef struct medic{
    int id;
    char * name;
} * MEDIC;

void createMedic(const int id, char * name);
void editUser(MEDIC u, char * name);
void changeName(MEDIC u, char * name);
void listMedic(MEDIC u);



#endif

