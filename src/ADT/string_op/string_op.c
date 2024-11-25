#include "string_op.h"
#include "boolean.h"

/* Membandingkan dua string, return 1 jika sama, 0 jika tidak */
boolean string_equals(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // Karakter tidak cocok
        }
        i++;
    }
    // Pastikan panjang string sama
    return (str1[i] == '\0' && str2[i] == '\0');
}

/* Mencari indeks barang berdasarkan nama di ArrayDin */
int find_item_index(ArrayDin *toko, char itemName[]) {
    for (int i = 0; i < Length(*toko); i++) {
        if (string_equals(toko->A[i].name, itemName)) {
            return i; // Return indeks jika ditemukan
        }
    }
    return -1; // Return -1 jika tidak ditemukan
}

