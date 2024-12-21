#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Mesin_Kalimat/mesinkalimat.h"
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/Mesin_Karakter/mesinkarakter.h"
#include "ADT/List_Statis/ListofUser.h"
#include "ADT/List_Dinamis/ListofBarang.h"
#include "ADT/List_Linear/ListofWishlist.h"
#include "ADT/Queue/queueBarang.h"
#include "ADT/MapSet/mapsetCart.h"
#include "ADT/Stack/stackHistory.h"
#include "ADT/string/string.h"
#include "boolean.h"

void STARTConfig(ArrayDin* listBarang, TabInt* listUser);
void WORK();
void WORDL3();


/*--------------- Help --------------------*/
void help(boolean sessionStatus, boolean loginStatus);
/* menampilkan command berdasarkan status menu*/

/*--------------- Cart Programs ---------------*/
cartfunction(TabInt *arrayUsers, int username_idx, ArrayDin arrayitems, char CurrentKalimatWord);
/* menerima perintah panggilan cartfunction yang menerima input fungsi program
    : ADD REMOVE PAY SHOW */
void ADD (Map* UserCart, ArrayDin arrayitems);
/* Menambah item ke keranjang dari item yang dijual di toko*/
void REMOVE (Map* UserCart);
/* Menghapus item dari keranjang sejumlah qty yang diinginkan*/
void PAY (Map* UserCart);
/* Membayar semua barang yang ada di keranjang*/
void SHOW (Map UserCart);
/* Memberikan tampilan pada user item yang ada di keranjang*/

#endif