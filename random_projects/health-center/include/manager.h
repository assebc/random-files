#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "llist.h"
#include "medic.h"
#include "user.h"

int addToFile(char * filename, void * p);
int editFile(char * filename, void * p);
LLIST * readFile(char * filename);
int removeFromFile(char * filename, const int id);
int getID(char * filename);

#endif
