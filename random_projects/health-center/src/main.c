#include "../include/ui.h"
#include <sys/stat.h>

int main(){
    menu();
    // struct stat st;
    // const char * path = "data/medicos.txt";
    // if(stat(path, &st) == 0 && S_ISREG(st.st_mode)){
    //     printf("yes");
    // } else {
    //     printf("no");
    // }
    return 0;
}