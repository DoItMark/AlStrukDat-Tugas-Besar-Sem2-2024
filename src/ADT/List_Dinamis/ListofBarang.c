#include <stdio.h>
#include <stdlib.h>
#include "ListofBarang.h"

/**`
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListBarang kosong dengan ukuran InitialSize
 */
ListBarang MakeListBarang() {
    ListBarang array;
    array.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateListBarang(ListBarang *array) {
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ListBarang array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ListBarang array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ListBarang array, IndexType i) {
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ListBarang array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAt(ListBarang *array, ElType el, IndexType i) {
    int length = Length(*array);
    int capacity = GetCapacity(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        ElType *arr = (ElType *) malloc(desiredCapacity * sizeof(ElType));
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*array, a);
        }
        free(array->A);
        
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ListBarang *array, ElType el) {
    int insertAt = Length(*array);
    InsertAt(array, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ListBarang *array, ElType el) {
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ListBarang *array, IndexType i) {
    int length = Length(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ListBarang
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ListBarang *array) {
    int deleteAt = Length(*array) - 1;
    DeleteAt(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ListBarang
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ListBarang *array) {
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ListBarang.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintListBarang(ListBarang array) {
    if (IsEmpty(array)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < array.Neff; i++) {
            printf("%s", array.A[i].name);
            if (i < array.Neff - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ListBarang.
 * Prekondisi: array terdefinisi
 */
void ReverseListBarang(ListBarang *array) {
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        ElType temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ListBarang.
 * Prekondisi: array terdefinisi
 */
ListBarang CopyListBarang(ListBarang array) {
    ListBarang copy = MakeListBarang();
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ListBarang.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IndexType SearchListBarang(ListBarang array, ElType el) {
    for (int i = 0; i < array.Neff; i++) {
        if (array.A[i].name == el.name) {
            return i;
        }
    }
    return -1;
}
