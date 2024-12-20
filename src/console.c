#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

static User currentUser;
static boolean isLoggedIn = false;

void STARTConfig(ArrayDin* arrayItems, TabInt* arrayUsers) { 
    int total = 0; // representasi jumlah barang atau user yang tercatat
    int n_riwayat_pembelian, n_wishlist;
    Barang currentBarang; // menyimpan barang yg sedang diproses
    User currentUser; // menyimpan user yg sedang diproses

    // Membuka file konfigurasi
    StartFileWord("../save/config.txt");

     // Membaca total barang yang tersimpan dalam file
    total = wordToInt(currentWord);

    // Memasukkan informasi barang ke arrayItems
    for (int i = 0; i < total; i++) {
        ADVFileWordSpace();
        currentBarang.price = wordToInt(currentWord);

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentBarang.name[j] = currentWord.TabWord[j];
        }
        currentBarang.name[currentWord.Length] = '\0';

        InsertLastArrDin(arrayItems, currentBarang);
    }

    // Membaca total user yang tersimpan dalam file
    ADVFileWordNewLine();
    total = wordToInt(currentWord);

    // Memasukkan informasi user ke arrayUsers
    for (int i = 0; i < total; i++) {
        currentUser.riwayat_pembelian = malloc(sizeof(Stack));
        currentUser.wishlist = malloc(sizeof(LinkedList));
        currentUser.keranjang = malloc(sizeof(Map));

        CreateEmptyStack(currentUser.riwayat_pembelian);
        CreateEmptyListLinier(currentUser.wishlist);
        CreateEmptyMap(currentUser.keranjang);

        ADVFileWordSpace();
        currentUser.money = wordToInt(currentWord);

        ADVFileWordSpace();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.name[j] = currentWord.TabWord[j];
        }
        currentUser.name[currentWord.Length] = '\0';

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.password[j] = currentWord.TabWord[j];
        }
        currentUser.password[currentWord.Length] = '\0';

        ADVFileWordNewLine();
        n_riwayat_pembelian = wordToInt(currentWord);
        for (int i = 0; i < n_riwayat_pembelian; i++) {
            barang_dibeli X;

            ADVFileWordSpace();
            X.totalharga = wordToInt(currentWord);

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X.name[j] = currentWord.TabWord[j];
            }
            X.name[currentWord.Length] = '\0';
            PushStack(currentUser.riwayat_pembelian, X);
        }

        ADVFileWordNewLine();
        n_wishlist = wordToInt(currentWord);
        for (int i = 0; i < n_wishlist; i++) {
            nama_barang X;

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X[j] = currentWord.TabWord[j];
            }
            X[currentWord.Length] = '\0';
            InsVLast(currentUser.wishlist, X);
        }

        SetEl(arrayUsers, i, currentUser);
    }

    arrayUsers->Neff = total;
    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void WORK() {
    const char *pekerjaan[] = {
        "Evil Lab Assistant",
        "OWCA Hiring Manager",
        "Cikapundunginator Caretaker",
        "Mewing Specialist",
        "Inator Connoisseur"
    };
    int pendapatan[] = {100, 4200, 7000, 10000, 997};
    int durasi[] = {14, 21, 30, 22, 15};
    int num_works = 5;

    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < num_works; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, pekerjaan[i], pendapatan[i], durasi[i]);
    }

    char pilih[100];
    int choice = -1;

    while (choice == -1) {
        printf("Masukkan nama pekerjaan yang dipilih: ");
        readString(pilih, sizeof(pilih));

        for (int i = 0; i < num_works; i++) {
            if (bandingkan_string(pilih, pekerjaan[i])) {
                choice = i;
                break;
            }
        }

        if (choice == -1) {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan[choice]);

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < durasi[choice]) {
        // Menunggu hingga durasi pekerjaan selesai
    }

    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan[choice]);
}

void WORDL3() {
    const int PANJANG_KATA = 5;
    const int CHANCE = 6;
    const char *kata_kunci[] = {
        "BALAP", "BOGOR", "HITAM", "KAPAL", "KARAM",
        "RUSDI", "JOMOK", "HERTA", "IKUYO", "MEKAR"
    };
    srand(time(NULL));
    const char *jawaban = kata_kunci[rand() % 10];

    char tebakan[PANJANG_KATA + 1];
    char tampilan[CHANCE][PANJANG_KATA * 3 + 1];
    int count = 0;

    // Inisialisasi tampilan
    for (int i = 0; i < CHANCE; i++) {
        for (int j = 0; j < PANJANG_KATA; j++) {
            tampilan[i][j * 3] = '_';
            tampilan[i][j * 3 + 1] = ' ';
            tampilan[i][j * 3 + 2] = ' ';
        }
        tampilan[i][PANJANG_KATA * 3] = '\0';
    }

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n\n", CHANCE);

    // Cetak tampilan awal
    for (int i = 0; i < CHANCE; i++) {
        printf("%s\n", tampilan[i]);
    }
    printf("\n");

    while (count < CHANCE) {
        printf("Masukan kata tebakan Anda (%d huruf): ", PANJANG_KATA);
        readString(tebakan, PANJANG_KATA + 1);

        // Validasi panjang kata
        if (hitung_panjang(tebakan) != PANJANG_KATA) {
            printf("Kata harus berisi tepat %d huruf!\n\n", PANJANG_KATA);
            continue;
        }

        // Proses tebakan dan update tampilan
        for (int i = 0; i < PANJANG_KATA; i++) {
            tampilan[count][i * 3] = tebakan[i];
            if (tebakan[i] == jawaban[i]) {
                tampilan[count][i * 3 + 1] = ' '; // Benar posisi
                tampilan[count][i * 3 + 2] = ' ';
            } else if (cari_karakter(jawaban, tebakan[i])) {
                tampilan[count][i * 3 + 1] = '*'; // Benar huruf, salah posisi
                tampilan[count][i * 3 + 2] = ' ';
            } else {
                tampilan[count][i * 3 + 1] = '%'; // Huruf tidak ada
                tampilan[count][i * 3 + 2] = ' ';
            }
        }

        // Tampilkan hasil
        printf("\nHasil:\n");
        for (int i = 0; i <= count; i++) {
            printf("%s\n", tampilan[i]);
        }
        for (int i = count + 1; i < CHANCE; i++) {
            printf("_ _ _ _ _\n");
        }
        printf("\n");

        // Cek kemenangan
        if (bandingkan_string(tebakan, jawaban)) {
            printf("\nSelamat, Anda menang!\n");
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }

        count++;
    }
    printf("Maaf, Anda kalah. Jawaban yang benar adalah: %s\n", jawaban);
}