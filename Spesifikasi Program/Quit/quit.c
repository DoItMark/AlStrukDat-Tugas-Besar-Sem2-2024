#include <stdio.h>
#include <stdbool.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

// Fungsi untuk menyimpan data (dummy function)
void SaveSession(const Barang barangList[], int totalBarang, const Pengguna penggunaList[], int totalPengguna) {
    FILE *saveFile = fopen("save.txt", "w");
    if (saveFile != NULL) {
        // Simpan barang
        fprintf(saveFile, "%d\n", totalBarang);
        for (int i = 0; i < totalBarang; i++) {
            fprintf(saveFile, "%d %s\n", barangList[i].HargaBarang, barangList[i].NamaBarang);
        }

        // Simpan pengguna
        fprintf(saveFile, "%d\n", totalPengguna);
        for (int i = 0; i < totalPengguna; i++) {
            fprintf(saveFile, "%d %s %s\n", penggunaList[i].Uang, penggunaList[i].Nama, penggunaList[i].Password);
        }

        fclose(saveFile);
        printf("Data sesi berhasil disimpan ke file save.txt.\n");
    } else {
        printf("Gagal menyimpan data sesi.\n");
    }
}

// Fungsi QUIT
void QUIT(const Barang barangList[], int totalBarang, const Pengguna penggunaList[], int totalPengguna) {
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");

    START(); // Mulai membaca dari input standar
    IgnoreBlanks(); // Abaikan spasi
    if (CC == 'Y' || CC == 'y') {
        SaveSession(barangList, totalBarang, penggunaList, totalPengguna); // Simpan data
    } else if (CC == 'N' || CC == 'n') {
        printf("Data sesi tidak disimpan.\n");
    } else {
        printf("Input tidak valid. Keluar tanpa menyimpan data.\n");
    }

    printf("Kamu keluar dari PURRMART.\nDadah ^_^\n");
    END(); // Mengakhiri pembacaan input
}

// Struktur Data
typedef struct {
    char NamaBarang[50];
    int HargaBarang;
} Barang;

typedef struct {
    char Nama[50];
    char Password[50];
    int Uang;
} Pengguna;

// Program utama
int main() {
    // Data simulasi
    Barang barangList[3] = {
        {"Platypus Laser", 10000},
        {"Shrink Ray", 5000},
        {"Net Shooter", 7500}
    };
    Pengguna penggunaList[2] = {
        {"Alice", "alice123", 100000},
        {"Bob", "bob456", 50000}
    };
    int totalBarang = 3, totalPengguna = 2;

    // Memanggil QUIT
    QUIT(barangList, totalBarang, penggunaList, totalPengguna);

    return 0;
}
