#include <stdio.h>


#define MAX_LEN 50 // Panjang maksimum pengguna yang dugunakan dalam program (50 karakter)

// Deklarasi fungsi LOGOUT
void logout(char *currentUser); // 

int main() {
    char currentUser[MAX_LEN] = "johndoe"; // Contoh pengguna yang login
    char input[MAX_LEN];
    int choice;
    char c;
    
    do {
        printf("\n=== PURRMART MENU ===\n");
        printf("1. LOGOUT\n");
        printf("Pilihan Anda: ");

        choice = 0;
        int i = 0;

        while ((c = getchar()) != '\n' && c != EOF && i < MAX_LEN - 1) {
            if (c >= '0' && c <= '9') {
                choice = choice * 10 + (c - '0');
            }
            i++;
        }

        switch (choice) {
            case 1:
                 logout(currentUser); // Panggil fungsi logout
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 1);

    return 0;
    }
// Definisi fungsi LOGOUT
void logout(char *currentUser) {
    int i = 0;
    while (currentUser[i] != '\0') {
        i++;
    }

    if (i == 0) {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", currentUser);
        currentUser[0] = '\0'; // Kosongkan currentUser
    }
}
