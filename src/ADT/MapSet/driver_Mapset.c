#include<stdio.h>
#include "mapsetCart.h"
#include "mapsetCart.c"
#include "../string/string.c"

void main(){
    char item;
    char *pitem = &item;
    Map Cart;
    CreateEmptyMap(&Cart);
    salin_string(&item,"barang");
    InsertMap(&Cart,&item,5);
    printf("name : %s \nprice: 10 \nqty : %d ",Cart.Elements->Key,Cart.Elements->Value);
}