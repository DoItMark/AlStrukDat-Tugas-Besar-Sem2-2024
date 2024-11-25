#include <stdio.h>
#include <stdlib.h>
#include "help.c"
#include "mesinkata.c"
#include "string.h"

int main(){
    char status;
    salin_string(status,"main_menu");
    STARTWORD();
    if (banding_kata(currentWord.TabWord,"HELP")){
        help(status);
    }

}