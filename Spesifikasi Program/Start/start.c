#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkalimat.h"

// Struktur untuk menyimpan data barang
typedef struct {
    char NamaBarang[50];
    int HargaBarang;
} Barang;

// Struktur untuk menyimpan data pengguna
typedef struct {
    char Nama[50];
    char Password[50];
    int Uang;
} Pengguna;

// Fungsi untuk mengonversi Word menjadi integer
int WordToInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result;
}

// Fungsi untuk mengonversi Word menjadi string (tanpa strcpy)
void WordToCharArray(Word w, char *destination) {
    for (int i = 0; i < w.Length; i++) {
        destination[i] = w.TabWord[i];
    }
    destination[w.Length] = '\0'; // Null-terminate string
}

// Fungsi START untuk membaca file konfigurasi
void START(const char *filename, Barang barangList[], int *totalBarang, Pengguna penggunaList[], int *totalPengguna) {
    STARTFILE(filename); // Memulai pembacaan file
    
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

    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
    END();
}

// Program utama
int main() {
    // Deklarasi daftar barang dan pengguna
    Barang barangList[100];
    Pengguna penggunaList[100];
    int totalBarang = 0, totalPengguna = 0;

    // Nama file konfigurasi default
    const char *filename = "config.txt";

    // Memulai aplikasi PURRMART
    START(filename, barangList, &totalBarang, penggunaList, &totalPengguna);

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