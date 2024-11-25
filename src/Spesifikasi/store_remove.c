#include "../header/mesinkata.h"
#include "../header/arraydin.h"
#include <stdio.h>

int find_item_index(ArrayDin *toko, char itemName[]) {
    for (int i = 0; i < Length(*toko); i++) {
        if (string_cmp(toko->A[i].name, itemName)) {
            return i; // Return indeks jika ditemukan
        }
    }
    return -1; // Return -1 jika tidak ditemukan
}


void StoreRemove(ArrayDin *toko, char itemName[]) {
    printf("=====REMOVE STORE=====\n");
    while (!IsEmpty(*toko)) {
        printf("Masukkan nama barang yang ingin dihapus (atau 'Purry' untuk keluar): ");
        STARTWORD();

        // Salin currentWord ke buffer string
        char input[MAX_LEN];
        for (int i = 0; i < currentWord.Length; i++) {
            input[i] = currentWord.TabWord[i];
        }
        input[currentWord.Length] = '\0'; // Tambahkan terminator null

        // Jika input adalah "Purry", keluar dari fungsi
        if (stringComp(input, "Purry")) {
            printf("Anda sudah Keluar dari Store Remove.\n");
            break;
        }

        // Cari indeks barang berdasarkan input
        int idxToRemove = find_item_index(toko, input);

        if (idxToRemove != -1) {
            // Barang ditemukan, hapus
            DeleteAt(toko, idxToRemove);
            printf("%s telah berhasil dihapus.\n", input);
        } else {
            // Barang tidak ditemukan
            printf("Toko tidak menjual %s.\n", input);
        }
    }
}
