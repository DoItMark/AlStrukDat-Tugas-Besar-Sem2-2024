#ifndef LOAD_H
#define LOAD_H
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkalimat.h"

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

void LOAD(const char *filename);

#endif 
