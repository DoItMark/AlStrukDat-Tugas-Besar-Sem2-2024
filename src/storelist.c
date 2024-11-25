#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100 // Panjang maksimum per baris
#define MARK '\n' // Penanda akhir baris

// Deklarasi mesin karakter
char currentChar;
FILE *tape;
char buffer[MAX_LINE_LENGTH];
int bufferIndex;
int bufferSize;

void start(char *filename) {
    tape = fopen(filename, "r");
    if (tape != NULL) {
        bufferSize = fread(buffer, sizeof(char), MAX_LINE_LENGTH, tape);
        bufferIndex = 0;
        if (bufferSize > 0) {
            currentChar = buffer[bufferIndex++];
        } else {
            currentChar = EOF;
        }
    } else {
        currentChar = EOF;
    }
}

void adv() {
    if (bufferIndex < bufferSize) {
        currentChar = buffer[bufferIndex++];
    } else {
        bufferSize = fread(buffer, sizeof(char), MAX_LINE_LENGTH, tape);
        bufferIndex = 0;
        if (bufferSize > 0) {
            currentChar = buffer[bufferIndex++];
        } else {
            currentChar = EOF;
        }
    }
}

int eot() {
    return currentChar == EOF;
}

int main() {
    char filename[] = "store.txt"; // Nama file yang akan dibaca
    char **storeItems;            // Pointer ke array dinamis untuk string
    int Neff = 0;                 // Jumlah elemen efektif (jumlah barang)
    char line[MAX_LINE_LENGTH];   // Buffer untuk membaca setiap baris di file

    // Membuka file untuk dibaca menggunakan mesin karakter
    start(filename);
    if (currentChar == EOF) {
        printf("Gagal membuka file: %s\n", filename);
        return 1;
    }

    // Hitung jumlah baris (barang) dalam file
    while (!eot()) {
        if (currentChar == MARK) {
            Neff++;
        }
        adv();
    }

    // Jika file kosong, langsung tampilkan "TOKO KOSONG"
    if (Neff == 0) {
        printf(">> STORE LIST\n");
        printf("TOKO KOSONG\n");
        fclose(tape);
        return 0;
    }

    // Alokasi memori untuk array dinamis
    storeItems = (char **)malloc(Neff * sizeof(char *));
    if (storeItems == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        fclose(tape);
        return 1;
    }

    // Kembali ke awal file untuk membaca isi file
    rewind(tape);
    start(filename);

    // Membaca isi file dan menyimpan ke dalam array dinamis
    int i = 0;
    int length = 0;
    while (!eot()) {
        if (currentChar == MARK) {
            // Alokasikan memori untuk setiap string (length + 1 untuk '\0')
            storeItems[i] = (char *)malloc((length + 1) * sizeof(char));
            if (storeItems[i] == NULL) {
                printf("Gagal mengalokasikan memori untuk barang ke-%d.\n", i + 1);
                fclose(tape);
                return 1;
            }

            // Salin string secara manual ke memori yang dialokasikan
            for (int j = 0; j < length; j++) {
                storeItems[i][j] = line[j];
            }
            storeItems[i][length] = '\0'; // Akhiri string dengan '\0'

            i++;
            length = 0; // Reset panjang untuk baris berikutnya
        } else {
            line[length++] = currentChar;
        }
        adv();
    }

    fclose(tape); // Menutup file setelah selesai membaca

    // Menampilkan daftar barang
    printf(">> STORE LIST\n");
    printf("List barang yang ada di toko:\n");
    for (int j = 0; j < Neff; j++) {
        printf("- %s\n", storeItems[j]);
    }

    // Membersihkan memori
    for (int j = 0; j < Neff; j++) {
        free(storeItems[j]); // Bebaskan memori untuk setiap string
    }
    free(storeItems); // Bebaskan memori untuk array pointer

    return 0;
}
