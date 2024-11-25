#ifndef SAVE_H
#define SAVE_H 
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkalimat.h"

//menyimpan data barang
typedef struct {
    char NamaBarang[50];
    int HargaBarang;
} Barang;

//menyimpan data pengguna
typedef struct {
    char Nama[50];
    char Password[50];
    int Uang;
} Pengguna;

void SAVE(const char *filename);

#endif 