#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
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
void LOAD(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers, boolean * SessionStatus);
void HELP(boolean sessionStatus, boolean loginStatus);
void QUIT (char* filename, ArrayDin* arrayItems, TabInt* arrayUsers);
void SAVE (char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers);
boolean validity_check(User users, char username[], char password[]);
void LOGIN(TabInt arrayUsers, boolean * loginStatus, char username_sekarang[], int * username_idx);
void LOGOUT (char * username, int * username_idx);
void WORK(TabInt *arrayUsers, int username_idx);
void workChallenge(TabInt *arrayUsers, int username_idx);
void WORDL3(TabInt *arrayUsers, int username_idx);
void TebakAngka(TabInt *arrayUsers, int username_idx);
void REGISTER(TabInt * arrayUsers);
void PROFILE(TabInt *arrayUsers, int username_idx);
void HISTORY(TabInt *arrayUsers, int username_idx, Word N);
/*--------------- Cart Programs ---------------*/
void cartfunction(TabInt *arrayUsers, int username_idx, ArrayDin arrayitems, Word currentWord);
/* menerima perintah panggilan cartfunction yang menerima input fungsi program
    : ADD REMOVE PAY SHOW */
void ADD (Map* UserCart, ArrayDin arrayItems);
/* Menambah item ke keranjang dari item yang dijual di toko*/
void REMOVE (Map* UserCart, ArrayDin arrayItems);
/* Menghapus item dari keranjang sejumlah qty yang diinginkan*/
void PAY (Map* UserCart, TabInt *arrayUsers, int username_idx, ArrayDin arrayItems);
/* Membayar semua barang yang ada di keranjang*/
void SHOW (Map UserCart, ArrayDin arrayItems);
/* Memberikan tampilan pada user item yang ada di keranjang*/

#endif