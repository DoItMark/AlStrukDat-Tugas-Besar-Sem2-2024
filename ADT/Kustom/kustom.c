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
