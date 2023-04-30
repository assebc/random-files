#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user{
    int id;
    char * name;
    int id_medic;
} * USER;

USER createUser(const int id, char * name, const int id_medic);
USER createUser2(char * buffer);
USER editUser(USER u, char * name, const int id_medic);
USER changeNameUser(USER u, char * name);
USER changeMedic(USER u, const int id_medic);
void listUser(USER u);


#endif