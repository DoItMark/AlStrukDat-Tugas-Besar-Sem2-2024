#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            if (stringComp(pilih, pekerjaan[i])) {
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
        if (stringLength(tebakan) != PANJANG_KATA) {
            printf("Kata harus berisi tepat %d huruf!\n\n", PANJANG_KATA);
            continue;
        }

        // Proses tebakan dan update tampilan
        for (int i = 0; i < PANJANG_KATA; i++) {
            tampilan[count][i * 3] = tebakan[i];
            if (tebakan[i] == jawaban[i]) {
                tampilan[count][i * 3 + 1] = ' '; // Benar posisi
                tampilan[count][i * 3 + 2] = ' ';
            } else if (stringSearch(jawaban, tebakan[i])) {
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
        if (stringComp(tebakan, jawaban)) {
            printf("\nSelamat, Anda menang!\n");
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }

        count++;
    }

    printf("Maaf, Anda kalah. Jawaban yang benar adalah: %s\n", jawaban);
}

int main() {
    WORK();
    WORDL3();
    return 0;
}