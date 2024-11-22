#include <stdio.h>
#include "../Barang/barang.h"

void STORE_REQUEST(Queue *antrian, Arraydin *toko){
    printf("Nama barang yang diminta: ");
    STARTINPUT();

    Barang barang;
    CreateBarang(&antrian, TabWord);

    if {
    IsBarangDiToko(*toko, TabWord);
    print("Barang dengan nama yang sama sudah ada di toko!");
    }
    else if {
    IsBarangDiAntrian(*antrian, TabWord);
    print("Barang dengan nama yang sama sudah ada di antrian!");
    }
    else {
    enqueue(antrian, barang);
    printf("Barang anda sudah ditambahkan ke dalam toko!");
    }
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struktur untuk menyimpan data barang
typedef struct {
    char nama[MAX_LEN];
    int price;
} Barang;

// Struktur untuk menyimpan data pengguna
typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  integer money;
} User;

// Fungsi untuk inisialisasi antrian
void InitAntrian(AntrianBarang *antrian) {
    antrian->head = 0;
    antrian->tail = 0;
}

// Fungsi untuk mengecek apakah antrian kosong
bool IsAntrianKosong(AntrianBarang antrian) {
    return antrian.head == antrian.tail;
}

// Fungsi untuk mengecek apakah antrian penuh
bool IsAntrianPenuh(AntrianBarang antrian) {
    return antrian.tail == 100;
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
void Enqueue(AntrianBarang *antrian, char *namaBarang) {
    if (!IsAntrianPenuh(*antrian)) {
        CopyString(antrian->queue[antrian->tail].NamaBarang, namaBarang);
        antrian->tail++;
    } else {
        printf("Antrian penuh. Tidak dapat menambahkan barang baru.\n");
    }
}

// Fungsi untuk mengecek apakah nama barang ada dalam antrian
bool IsBarangDiAntrian(AntrianBarang antrian, char *namaBarang) {
    for (int i = antrian.head; i < antrian.tail; i++) {
        if (CompareString(antrian.queue[i].NamaBarang, namaBarang)) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk mengecek apakah nama barang ada di toko
bool IsBarangDiToko(Barang barangList[], int totalBarang, char *namaBarang) {
    for (int i = 0; i < totalBarang; i++) {
        if (CompareString(barangList[i].NamaBarang, namaBarang)) {
            return true;
        }
    }
    return false;
}

// Fungsi STORE REQUEST
void STORE_REQUEST(Barang barangList[], int totalBarang, AntrianBarang *antrian) {
    printf("Nama barang yang diminta: ");
    START(); // Mulai membaca input
    IgnoreBlanks();
    char namaBarang[50] = {0};
    WordToCharArray(currentWord, namaBarang);

    // Cek apakah barang ada di toko
    if (IsBarangDiToko(barangList, totalBarang, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // Cek apakah barang ada di antrian
    if (IsBarangDiAntrian(*antrian, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }

    // Tambahkan barang ke antrian
    Enqueue(antrian, namaBarang);
    printf("Barang '%s' berhasil ditambahkan ke antrian.\n", namaBarang);
}

// buat scan
void STARTINPUT(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == ';')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyInput();
    }
}

void CopyInput()
{
    ResetInput();  // Reset array
    int i = 0;
    while ((currentChar != ';') && (currentChar != EOF))
    {
        currentInput.TabWord[i] = currentChar;
        // printf("%c", CC);
        i++;
        ADV();
        
    }
    currentInput.Length = i;
}

void IgnoreBlanks(){
    while (CC == BLANK){
        ADV();
    }
}