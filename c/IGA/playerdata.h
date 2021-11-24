typedef struct llist{
    char * player;
    struct llist *prox;
} *LPlayers;

void clear_console();
LPlayers default_start();
void append(LPlayers ** head_ref, int new_data);
int size(LPlayers p);
int lookfor(LPlayers * p, char * data);
void playerdata();