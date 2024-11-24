#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i) {
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
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
void InsertLast(ArrayDin *array, ElType el) {
    int insertAt = Length(*array);
    InsertAt(array, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el) {
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i) {
    int length = Length(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array) {
    int deleteAt = Length(*array) - 1;
    DeleteAt(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array) {
    if (IsEmpty(array)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < array.Neff; i++) {
            printf("%d", array.A[i]);
            if (i < array.Neff - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array) {
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        ElType temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array) {
    ArrayDin copy = MakeArrayDin();
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el) {
    for (int i = 0; i < array.Neff; i++) {
        if (array.A[i] == el) {
            return i;
        }
    }
    return -1;
}