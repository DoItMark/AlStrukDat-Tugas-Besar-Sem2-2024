#include <stdio.h>
#include "string.c"
#include "string.h"

int main(){
    char *a = "15";
    int length = hitung_panjang(a);
    int aint = stringtoint(a,length);
    printf("%d\n",aint);
    return 0;
}