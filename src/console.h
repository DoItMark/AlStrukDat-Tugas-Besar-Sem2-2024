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

#endif