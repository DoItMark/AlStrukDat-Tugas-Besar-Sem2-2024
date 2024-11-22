#include <stdio.h>
#include "../Barang/barang.h"

void STORE_REQUEST(Queue *antrian, Arraydin *toko)
    printf("Nama barang yang diminta: ");
    STARTINPUT();

    Barang barang;
    CreateBarang(&antrian, TabWord);

    if {
    IsBarangDiToko(*toko, TabWord);
    print("Barang dengan nama yang sama sudah ada di toko!")
    }
    else if {
    IsBarangDiAntrian(*antrian, TabWord);
    print("Barang dengan nama yang sama sudah ada di antrian!")
    }
    else {
    enqueue(antrian, barang);
    printf("Barang anda sudah ditambahkan ke dalam toko!")
    }


// Fungsi untuk menyalin string secara manual
void CopyString(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0' && i < 50) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Null-terminate string
}

// Fungsi untuk membandingkan dua string secara manual
bool CompareString(const char *str1, const char *str2) {
    int i = 0;
    // Bandingkan karakter satu per satu
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false; // Jika ada perbedaan karakter, kembalikan false
        }
        i++;
    }
    // Pastikan kedua string berakhir pada saat yang sama
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Fungsi untuk menambahkan barang ke antrian
void CreateBarang(AntrianBarang *antrian, char *namaBarang) {
    if (!IsAntrianPenuh(*antrian)) {
        CopyString(antrian->queue[antrian->tail].NamaBarang, namaBarang);
        antrian->tail++;
    } else {
        printf("Antrian penuh. Tidak dapat menambahkan barang baru.\n");
    }
}

// Fungsi untuk menyalin string secara manual
void CopyString(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0' && i < 50) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Null-terminate string
}


// Fungsi untuk mengecek apakah nama barang ada dalam antrian
bool IsBarangDiAntrian(Queue antrian, char namaBarang) {
    for (int i = antrian.head; i < antrian.tail; i++) {
        if (CompareString(antrian.queue[i].NamaBarang, namaBarang)) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk mengecek apakah nama barang ada di toko
bool IsBarangDiToko(Barang barangList[], char namaBarang) {
    for (int i = 0; i < LengthArray(&toko); i++) {
        if (CompareString(barangList[i].NamaBarang, namaBarang)) {
            return true;
        }
    }
    return false;
}


int main() {
    Barang barangList[3] = {
        {"Platypus Laser", 10000},
        {"Shrink Ray", 5000},
        {"Net Shooter", 7500}
    };
    int totalBarang = 3;

    AntrianBarang antrianBarang;
    InitAntrian(&antrianBarang);

    // Contoh penggunaan STORE REQUEST
    STORE_REQUEST(barangList, totalBarang, &antrianBarang);
    STORE_REQUEST(barangList, totalBarang, &antrianBarang);
    STORE_REQUEST(barangList, totalBarang, &antrianBarang);

    return 0;
}
