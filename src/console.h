#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/User/user.h"
#include "ADT/Barang/Barang.h"
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
void REGISTER(TabInt * arrayUsers);

#endif