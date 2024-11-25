#include <stdio.h>
#include <stdlib.h>
#include "start.c"

int main() {
    // Deklarasi daftar barang dan pengguna
    Barang barangList[100];
    Pengguna penggunaList[100];
    int totalBarang = 0, totalPengguna = 0;

    // Nama file konfigurasi default
    const char *filename = "tes.txt";

    // Memulai aplikasi PURRMART
    printf(">> START\n");
    START(userList, barangList, &totalBarang, &totalPengguna);

    // Menampilkan data yang dibaca
    printf("\nDaftar Barang:\n");
    for (int i = 0; i < totalBarang; i++) {
        printf("- %s (Rp%d)\n", barangList[i].NamaBarang, barangList[i].HargaBarang);
    }

    printf("\nDaftar Pengguna:\n");
    for (int i = 0; i < totalPengguna; i++) {
        printf("- %s (Uang: Rp%d, Password: %s)\n", penggunaList[i].Nama, penggunaList[i].Uang, penggunaList[i].Password);
    }

    return 0;
}