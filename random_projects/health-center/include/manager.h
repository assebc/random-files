#ifndef MANAGER_H
#define MANAGER_H

#include "medic.h"
#include "user.h"

int addToFile(char * filename, void * p);
int editFile(char * filename, void * p);
int removeFromFile(char * filename, const int id);

#endif
