#include <stdio.h>
#include "login.h" 

#define MAX_USERS 100
#define MAX_LEN 50

// Fungsi untuk membandingkan dua string
int stringCompare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0; // Tidak sama
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0'; // Sama jika keduanya mencapai akhir
}

// Fungsi untuk menyalin string
void stringCopy(char *destination, char *source) {
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Tambahkan null terminator
}

// Fungsi untuk membaca string dari input
void readString(char *buffer, int maxLength) {
    int i = 0;
    char c;
    while (i < maxLength - 1 && (c = getchar()) != '\n' && c != EOF) {
        buffer[i++] = c;
    }
    buffer[i] = '\0'; // Tambahkan null terminator
}

// Fungsi untuk memeriksa apakah username ada dalam list
int findUserIndex(List *users, char *username) {
    for (int i = 0; i < users->size; i++) {
        if (stringCompare(users->elements[i].name, username)) {
            return i; // Return index user
        }
    }
    return -1; // Tidak ditemukan
}

// Fungsi LOGIN
void login(List *users, char *currentUser) {
    char username[MAX_LEN], password[MAX_LEN];
    printf(">> LOGIN\n");
    printf("Username: ");
    readString(username, MAX_LEN);
    printf("Password: ");
    readString(password, MAX_LEN);

    // Cek apakah sudah ada pengguna yang login
    if (currentUser[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser);
        return; // Hentikan proses login jika masih ada pengguna yang login
    }

    // Cari user berdasarkan username
    int userIndex = findUserIndex(users, username);
    if (userIndex != -1) {
        // Username ditemukan, cocokkan password
        if (stringCompare(users->elements[userIndex].password, password)) {
            // Login berhasil
            stringCopy(currentUser, username); // Salin username ke currentUser
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        } else {
            // Password salah
            printf("Password salah.\n");
        }
    } else {
        // Username tidak ditemukan
        printf("Username tidak ditemukan.\n");
    }
}

// Fungsi untuk menambahkan pengguna baru ke list (opsional untuk testing)
void addUser(List *users, char *username, char *password, int money) {
    stringCopy(users->elements[users->size].name, username);
    stringCopy(users->elements[users->size].password, password);
    users->elements[users->size].money = money;
    users->size++;
}

// Fungsi utama untuk testing
int main() {
    List users;
    users.size = 0;

    char currentUser[MAX_LEN] = ""; // Menyimpan username pengguna yang login

    // Tambahkan beberapa akun untuk testing
    addUser(&users, "johndoe", "janedoe", 1000);
    addUser(&users, "alice", "wonderland", 500);
    addUser(&users, "janedoe", "kelompok7", 500);

    // Test login
    while (1) {
        login(&users, currentUser);
    }
    return 0;
}
