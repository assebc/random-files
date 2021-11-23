typedef struct llist{
    char * player;
    struct llist *prox;
} *LPlayers;

LPlayers default_start();
void append(LPlayers ** head_ref, int new_data);
int size(LPlayers p);
void clear_console();
void playerdata();