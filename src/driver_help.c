#include <stdio.h>
#include <stdlib.h>
#include "help.c"
#include "ADT/Mesin Kata/mesinkata.c"


int main(){
    char status;
    salin_string(&status,"main_menu");
    STARTWORD();


    if (bandingkan_string(currentWord.TabWord,"HELP")){
        help(status);
    }
    return 0;
}