#include<stdio.h>
#include "mapsetCart.h"

void main(){
    Barang item;
    Map Cart;
    CreateEmptyMap(&Cart);
    copyStringMap(item.name,"barang");
    item.price = 12;
    InsertMap(&Cart,item,5);
    printf("name : %s \nprice: %d \nqty : %d ",Cart.Elements->Key.name,Cart.Elements->Key.price,Cart.Elements->Value);
}