#include <stdio.h>
#include <stdlib.h>
#include "start.h"

// Fungsi START untuk membaca file konfigurasi
void START(User *userList, Barang *barangList) {
    FILE *file = fopen("Quit/tes.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file konfigurasi.\n");
        return;
    }
    
    STARTFILE(tes.txt);

    // Membaca jumlah barang
    ADVWORD();
    *totalBarang = WordToInt(currentWord);
    
    // Membaca data barang
    for (int i = 0; i < *totalBarang; i++) {
        // Membaca harga barang
        ADVWORD();
        barangList[i].HargaBarang = WordToInt(currentWord);

        // Membaca nama barang
        ADVWORD();
        WordToCharArray(currentWord, barangList[i].NamaBarang);
    }

    // Membaca jumlah pengguna
    ADVWORD();
    *totalPengguna = WordToInt(currentWord);

    // Membaca data pengguna
    for (int i = 0; i < *totalPengguna; i++) {
        // Membaca jumlah uang pengguna
        ADVWORD();
        penggunaList[i].Uang = WordToInt(currentWord);

        // Membaca nama pengguna
        ADVWORD();
        WordToCharArray(currentWord, penggunaList[i].Nama);

        // Membaca password pengguna
        ADVWORD();
        WordToCharArray(currentWord, penggunaList[i].Password);
    }

    fclose(file); // Menutup file
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

// // Program utama
// int main() {
//     // Deklarasi daftar barang dan pengguna
//     Barang barangList[100];
//     Pengguna penggunaList[100];
//     int totalBarang = 0, totalPengguna = 0;

//     // Nama file konfigurasi default
//     const char *filename = "tes.txt";

//     // Memulai aplikasi PURRMART
//     printf(">> START\n");
//     START(userList, barangList, &totalBarang, &totalPengguna);

//     // Menampilkan data yang dibaca
//     printf("\nDaftar Barang:\n");
//     for (int i = 0; i < totalBarang; i++) {
//         printf("- %s (Rp%d)\n", barangList[i].NamaBarang, barangList[i].HargaBarang);
//     }

//     printf("\nDaftar Pengguna:\n");
//     for (int i = 0; i < totalPengguna; i++) {
//         printf("- %s (Uang: Rp%d, Password: %s)\n", penggunaList[i].Nama, penggunaList[i].Uang, penggunaList[i].Password);
//     }

//     return 0;
// }
