#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/User/user.h"


static User currentUser;
static boolean isLoggedIn = false;

void readConfig(const char *filename, ListBarang *listBarang, ListUser *listUser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d", &listBarang->Neff);
    for (int i = 0; i < listBarang->Neff; i++) {
        fscanf(file, "%d", &listBarang->A[i].price);
        fgetc(file); // Mengabaikan spasi setelah harga
        fgets(listBarang->A[i].name, MAX_LEN, file);
        // Menghapus newline di akhir nama barang
        listBarang->A[i].name[strcspn(listBarang->A[i].name, "\n")] = '\0';
    }

    int jumlahUser;
    fscanf(file, "%d", &jumlahUser);
    for (int i = 0; i < jumlahUser; i++) {
        fscanf(file, "%d", &listUser->A[i].money);
        fscanf(file, "%s", listUser->A[i].name);
        fscanf(file, "%s", listUser->A[i].password);
    }

    fclose(file);
}

void START() {
    ListBarang listBarang = MakeListBarang();
    ListUser listUser = MakeListUser();

    readConfig("default.txt", &listBarang, &listUser);

    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

    // // Menampilkan daftar barang
    // printf("Daftar Barang:\n");
    // for (int i = 0; i < listBarang.Neff; i++) {
    //     printf("%d %s\n", listBarang.A[i].price, listBarang.A[i].name);
    // }

    // // Menampilkan daftar pengguna
    // printf("\nDaftar Pengguna:\n");
    // for (int i = 0; i < LengthUser(listUser); i++) {
    //     printf("%d %s %s\n", listUser.A[i].money, listUser.A[i].name, listUser.A[i].password);
    // }

    // Dealokasi memori
    // DeallocateListBarang(&listBarang);
}

void LOAD(const char *filename, ListBarang *listBarang) {
    DeallocateListBarang(&listBarang);
    ListBarang listBarang = MakeListBarang();
    ListUser listUser = MakeListUser();

    char filepath[256];
    snprintf(filepath, sizeof(filepath), "../save/%s", filename);

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    fclose(file);

    readConfig(filepath, &listBarang, &listUser);

    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");

    // // Menampilkan daftar barang
    // printf("Daftar Barang:\n");
    // for (int i = 0; i < listBarang.Neff; i++) {
    //     printf("%d %s\n", listBarang.A[i].price, listBarang.A[i].name);
    // }

    // // Menampilkan daftar pengguna
    // printf("\nDaftar Pengguna:\n");
    // for (int i = 0; i < LengthUser(listUser); i++) {
    //     printf("%d %s %s\n", listUser.A[i].money, listUser.A[i].name, listUser.A[i].password);
    // }

    // // Dealokasi memori
    // DeallocateListBarang(&listBarang);
}

boolean authenticate(ListUser listUser, char *username, char *password) {
    for (int i = 0; i < LengthUser(listUser); i++) {
        if (strcmp(listUser.A[i].name, username) == 0 && strcmp(listUser.A[i].password, password) == 0) {
            currentUser.money = listUser.A[i].money;
            return true;
        }
    }
    return false;
}

void LOGIN(ListUser listUser) {
    if (isLoggedIn) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser.name);
        return;
    }

    char username[MAX_LEN];
    char password[MAX_LEN];

    printf("Username: ");
    readString(username, MAX_LEN);
    printf("Password: ");
    readString(password, MAX_LEN);

    if (authenticate(listUser, username, password)) {
        isLoggedIn = true;
        strcpy(currentUser.name, username);
        strcpy(currentUser.password, password);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("Username atau password salah.\n");
    }
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

// Fungsi PROFILE untuk menampilkan data diri pengguna
void PROFILE(TabInt arrayUsers, int username_idx) {
    // Menampilkan data diri pengguna aktif
    printf(">> PROFILE\n");
    printf("Nama: %s\n", arrayUsers.TI[username_idx].name);
    printf("Saldo: %d\n", arrayUsers.TI[username_idx].money);

    printf("> Kembali ke menu utama\n");
}

// Fungsi HISTORY untuk menampilkan riwayat pembelian
void HISTORY(TabInt arrayUsers, int username_idx, int N) {
    // Periksa apakah riwayat pembelian kosong
    if (IsEmptyStack(*arrayUsers.TI[username_idx].riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun.\n");
        return;
    }

    printf(">> HISTORY %d\n", N);
    printf("Riwayat pembelian barang:\n");

    // Menampilkan riwayat pembelian
    Stack tempStack = *arrayUsers.TI[username_idx].riwayat_pembelian; // Salin stack untuk iterasi
    int count = 0;

    while (!IsEmptyStack(tempStack) && count < N) {
        // Ambil elemen dari stack
        barang_dibeli pembelian;
        PopStack(&tempStack, &pembelian);

        // Cetak elemen
        printf("%d. %s %d\n", count + 1, pembelian.name, pembelian.totalharga);
        count++;
    }

    printf("> Command mati; Kembali ke menu utama\n");
}

int main() {
    START();
    WORK();
    WORDL3();
    return 0;
}
