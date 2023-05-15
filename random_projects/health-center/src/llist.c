#include "../include/llist.h"

void insert(LLIST* head, void* data) {
    LLIST new_node = (LLIST) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    LLIST last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void print_list(LLIST head, int opt) {
    LLIST current = head;
    while (current != NULL) {
        switch (opt) {
            case 1:
                listUser((USER) current->data);
                break;
            case 2:
                listMedic((MEDIC) current->data);
                break;
        }
        current = current->next;
    }
    printf("\n");
}