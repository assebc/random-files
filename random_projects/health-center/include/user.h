#ifndef USER_H
#define USER_H

typedef struct user{
    int id;
    char * name;
    int id_medic;
} * USER;

void createUser(const int id, char * name, const int id_medic);
void editUser(USER u, char * name, const int id_medic);
void changeName(USER u, char * name);
void changeMedic(USER u, const int id_medic);
void listUser(USER u);


#endif