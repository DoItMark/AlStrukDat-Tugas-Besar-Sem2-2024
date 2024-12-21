#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"

// Struktur Linked List untuk Wishlist
typedef struct tElmtList *address;
typedef struct tElmtList {
    char info[50]; // Nama barang
    address next;  // Pointer ke elemen berikutnya
} ElmtList;

typedef struct {
    address first;
} LinkedList;

// Fungsi-fungsi dasar Linked List
void CreateEmpty(LinkedList *L) {
    L->first = NULL;
}

int IsEmpty(LinkedList L) {
    return L.first == NULL;
}

address Alokasi(char *barang) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        // Salin manual tanpa strcpy
        int i = 0;
        while (barang[i] != '\0' && i < 50) {
            newNode->info[i] = barang[i];
            i++;
        }
        newNode->info[i] = '\0'; // Akhiri string
        newNode->next = NULL;
    }
    return newNode;
}

void InsVLast(LinkedList *L, char *barang) {
    address newNode = Alokasi(barang);
    if (newNode != NULL) {
        if (IsEmpty(*L)) {
            L->first = newNode;
        } else {
            address P = L->first;
            while (P->next != NULL) {
                P = P->next;
            }
            P->next = newNode;
        }
    }
}

void PrintInfo(LinkedList L) {
    if (IsEmpty(L)) {
        printf("WISHLIST KOSONG\n");
    } else {
        address P = L.first;
        printf("WISHLIST: ");
        while (P != NULL) {
            printf("%s -> ", P->info);
            P = P->next;
        }
        printf("NULL\n");
    }
}

void DelP(LinkedList *L, char *barang) {
    if (IsEmpty(*L)) {
        printf("WISHLIST KOSONG, tidak ada barang yang dapat dihapus.\n");
        return;
    }

    address P = L->first, prev = NULL;

    // Cari elemen yang akan dihapus (manual tanpa strcmp)
    while (P != NULL) {
        int i = 0, match = 1;
        while (barang[i] != '\0' && P->info[i] != '\0') {
            if (barang[i] != P->info[i]) {
                match = 0;
                break;
            }
            i++;
        }
        if (match && barang[i] == '\0' && P->info[i] == '\0') {
            break; // Barang ditemukan
        }
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", barang);
        return;
    }

    if (prev == NULL) {
        // Hapus elemen pertama
        L->first = P->next;
    } else {
        // Hapus elemen di tengah atau akhir
        prev->next = P->next;
    }
    free(P);
    printf("%s berhasil dihapus dari WISHLIST!\n", barang);
}

void readStringManual(char* buffer, int bufferSize) {
    char c;
    int i = 0;
    while (i < bufferSize - 1 && (c = getchar()) != '\n' && c != EOF) {
        buffer[i++] = c;
    }
    buffer[i] = '\0'; // Akhiri string
}

// Fungsi utama untuk menghapus barang dari wishlist
void wishlist_remove(LinkedList *wishlist) {
    char barang[50];

    printf(">> WISHLIST REMOVE\n");
    printf("Masukkan nama barang yang akan dihapus: ");

    readStringManual(barang, 50); // Membaca input pengguna secara manual

    // Hapus barang dari wishlist
    DelP(wishlist, barang);
}

int main() {
    LinkedList wishlist;
    CreateEmpty(&wishlist);

    // Menambahkan barang ke wishlist
    InsVLast(&wishlist, "Lalabu");
    InsVLast(&wishlist, "Ayam Geprek");
    InsVLast(&wishlist, "Platypus Laser");


    // Menghapus barang dari wishlist
    wishlist_remove(&wishlist);

    // Menampilkan wishlist setelah penghapusan
    printf("Isi Wishlist Setelah Penghapusan:\n");
    PrintInfo(wishlist);

    return 0;
}
