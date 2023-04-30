#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "medic.h"
#include "user.h"

typedef struct node {
    void * data;
    struct node *next;
} * LLIST;

void insert(LLIST * head, void * data);
void printList(LLIST * head);
 
#endif
