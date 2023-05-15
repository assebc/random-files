#include "../include/manager.h"

int addToFile(char* filename, void* p) {
    FILE* fp = fopen(filename, "a");
    if (!fp) {
        perror("Error while opening file!\n");
        return 1;
    }

    USER u;
    MEDIC m;
    int opt = 2;
    if (strcmp(filename, "utentes.txt") == 0) {
        u = (USER)p;
        opt = 1;
    } else {
        m = (MEDIC)p;
    }

    switch (opt) {
        case 1:
            fprintf(fp, "\n%d,%s,%d", u->id, u->name, u->id_medic);
            break;
        case 2:
            fprintf(fp, "\n%d,%s,%p", m->id, m->name, (void*)m->q);
            break;
    }

    fclose(fp);
    return 0;
}


int editFile(char* filename, void* p) {
    char* buffer = malloc(sizeof(char) * LINE_BUFFER);
    char* q;
    FILE* fp = fopen(filename, "r+");
    if (!fp) {
        perror("Error while opening file!\n");
        return 1;
    }

    USER u;
    MEDIC m;
    int opt = 2;
    if (strcmp(filename, "utentes.txt") == 0) {
        u = (USER)p;
        opt = 1;
    } else {
        m = (MEDIC)p;
    }

    // don't read the first line
    fgets(buffer, LINE_BUFFER, fp);

    long offset = ftell(fp);
    while (fgets(buffer, LINE_BUFFER, fp) != NULL) {
        q = strtok(buffer, ",");
        if (q == NULL)
            continue;

        int id = atoi(q);
        if (opt == 1 && id == u->id) {
            fseek(fp, offset, SEEK_SET);
            fprintf(fp, "%d,%s,%d\n", u->id, u->name, u->id_medic);
            fclose(fp);
            free(buffer);
            return 0;
        } else if (opt == 2 && id == m->id) {
            fseek(fp, offset, SEEK_SET);
            fprintf(fp, "%d,%s,%p\n", m->id, m->name, (void*)m->q);
            fclose(fp);
            free(buffer);
            return 0;
        }

        offset = ftell(fp);
    }

    fclose(fp);
    free(buffer);
    perror("ID not found!\n");
    return 1;
}

LLIST* readFile(char* filename) {
    LLIST* res = malloc(sizeof(LLIST));
    *res = NULL;

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error while opening file!\n");
        return NULL;
    }

    USER u;
    MEDIC m;
    int opt = 2;
    if (strcmp(filename, "utentes.txt") == 0) {
        opt = 1;
    }

    char* buffer = malloc(sizeof(char) * LINE_BUFFER);
    fgets(buffer, LINE_BUFFER, fp); // Skip the first line

    char* q;
    int ids, id_medic;
    unsigned long q_pointer;
    char* name = malloc(sizeof(char) * 1024);
    QUEUE qs = malloc(sizeof(QUEUE));
    while (fgets(buffer, LINE_BUFFER, fp) != NULL) {
        int i = 0;
        char* line = buffer;
        while ((q = strsep(&line, ",")) != NULL) {
            switch (i) {
                case 0:
                    ids = atoi(q);
                    break;
                case 1:
                    strcpy(name, q);
                    break;
                default:
                    switch (opt) {
                        case 1:
                            id_medic = atoi(q);
                            break;
                        case 2:
                            q_pointer = strtoul(q, NULL, 16);
                            break;
                    }
                    break;
            }
            i++;
        }

        switch (opt) {
            case 1:
                u = createUser(ids, name, id_medic);
                insert(res, u);
                break;
            case 2:
                initQueue(qs);
                qs = (QUEUE)q_pointer;
                m = createMedic(ids, name, qs);
                insert(res, m);
                break;
        }
    }

    free(name);
    fclose(fp);
    free(buffer);

    return res;
}

int removeFromFile(char* filename, const int id) {
    FILE* fp = fopen(filename, "r");
    FILE* tmp = fopen(temp_file, "w");

    if (!fp || !tmp) {
        perror("Error while opening files!\n");
        return 1;
    }

    char* buffer = malloc(sizeof(char) * LINE_BUFFER);
    int found = 0;

    // Don't read the first line
    fgets(buffer, LINE_BUFFER, fp);

    while (fgets(buffer, LINE_BUFFER, fp)) {
        char* q = strsep(&buffer, ",");
        if (atoi(q) != id) {
            fputs(buffer, tmp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(tmp);

    if (found) {
        remove(filename);
        rename(temp_file, filename);
    } else {
        remove(temp_file);
        perror("ID not found!\n");
        return 1;
    }
    return 0;
}

int getID(char* filename) {
    int last_id;
    if (strcmp(filename, "utentes") == 0)
        last_id = 1001;
    else
        last_id = 1;
    char* buffer = malloc(sizeof(char) * LINE_BUFFER);
    char* q;
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error while opening file!\n");
        return 1;
    }

    // Don't read the first line
    fgets(buffer, LINE_BUFFER, fp);

    while (fgets(buffer, LINE_BUFFER, fp) != NULL) {
        while ((q = strsep(&buffer, ",")) != NULL) {
            last_id = atoi(q);
            break;
        }
        free(q);
    }
    fclose(fp);
    return last_id;
}