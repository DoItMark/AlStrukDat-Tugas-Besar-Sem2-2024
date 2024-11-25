#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include "barang.h"
#include "arraydin.h"

/* Fungsi untuk membandingkan dua string tanpa menggunakan string.h */
int string_equals(const char *str1, const char *str2);

/* Fungsi untuk mencari indeks string tertentu dalam list barang */
int find_item_index(ArrayDin *toko, char itemName[]);

#endif
