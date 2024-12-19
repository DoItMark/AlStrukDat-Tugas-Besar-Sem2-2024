#ifndef STRING_H
#define STRING_H

#include "../../boolean.h"

// Menghitung panjang string
int hitung_panjang(const char *str);

// Menyalin string dari src ke dest
void salin_string(char *dest, const char *src);

// Membandingkan dua string, mengembalikan true jika sama, false jika berbeda
boolean bandingkan_string(const char *str1, const char *str2);

// Mencari karakter c dalam string, mengembalikan true jika ditemukan, false jika tidak
boolean cari_karakter(const char *str, char c);

void hapuskarakter(char str[], int offset);

#endif