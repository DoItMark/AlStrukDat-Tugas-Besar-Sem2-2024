#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#include "../Barang/barang.h"
#include "../../boolean.h"

#define InitialSize 10

typedef int IdxType;
typedef Barang ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ListBarang;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListBarang kosong dengan ukuran InitialSize
 */
ListBarang MakeListBarang();

/**
 * Destruktor
 * I.S. ListBarang terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateListBarang(ListBarang *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ListBarang array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ListBarang array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ListBarang array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ListBarang array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ListBarang *array, ElType el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ListBarang *array, ElType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ListBarang *array, ElType el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ListBarang
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ListBarang *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir ListBarang
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ListBarang *array);

/**
 * Fungsi untuk menghapus elemen pertama ListBarang
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ListBarang *array);

/**
 * Fungsi untuk melakukan print suatu ListBarang.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintListBarang(ListBarang array);

/**
 * Fungsi untuk melakukan reverse suatu ListBarang.
 * Prekondisi: array terdefinisi
 */
void ReverseListBarang(ListBarang *array);

/**
 * Fungsi untuk melakukan copy suatu ListBarang.
 * Prekondisi: array terdefinisi
 */
ListBarang CopyListBarang(ListBarang array);

/**
 * Fungsi untuk melakukan search suatu ListBarang.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchListBarang(ListBarang array, ElType el);

#endif