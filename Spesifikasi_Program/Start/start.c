#include <stdio.h>
#include <stdlib.h>
#include "start.h"


void START(User *userList, Barang *barangList) {
    FILE *file = fopen("Quit/tes.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file konfigurasi.\n");
        return;
    }
    
    STARTFILE(tes.txt);

    ADVWORD();
    *totalBarang = WordToInt(currentWord);
    

    for (int i = 0; i < *totalBarang; i++) {
        
        ADVWORD();
        barangList[i].HargaBarang = WordToInt(currentWord);

        
        ADVWORD();
        WordToCharArray(currentWord, barangList[i].NamaBarang);
    }


    ADVWORD();
    *totalPengguna = WordToInt(currentWord);

    
    for (int i = 0; i < *totalPengguna; i++) {
        
        ADVWORD();
        penggunaList[i].Uang = WordToInt(currentWord);

    
        ADVWORD();
        WordToCharArray(currentWord, penggunaList[i].Nama);

        
        ADVWORD();
        WordToCharArray(currentWord, penggunaList[i].Password);
    }

    fclose(file);
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

// // Program utama
// int main() {

//     Barang barangList[100];
//     Pengguna penggunaList[100];
//     int totalBarang = 0, totalPengguna = 0;

//     const char *filename = "tes.txt";

//     printf(">> START\n");
//     START(userList, barangList, &totalBarang, &totalPengguna);

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
