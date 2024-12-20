#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100

// Daftar barang yang tersedia (hardcoded untuk contoh)
const char *availableItems[] = {
    "Ayam Geprek Bakar Crispy Besthal",
    "Nasi Goreng Spesial Besthal",
    "Burger Keju Double Besthal"
};
const int availableItemsCount = 3;

// Definisi ADT Wishlist
typedef struct {
    char items[MAX_ITEMS][MAX_NAME_LENGTH];
    int count;
} Wishlist;

// Inisialisasi wishlist
Wishlist wishlist = { .count = 0 };

// Fungsi untuk memeriksa apakah barang ada di wishlist
int isInWishlist(Wishlist *wishlist, const char *item) {
    for (int i = 0; i < wishlist->count; i++) {
        if (strcmp(wishlist->items[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fungsi untuk memeriksa apakah barang tersedia
int isAvailable(const char *item) {
    for (int i = 0; i < availableItemsCount; i++) {
        if (strcmp(availableItems[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fungsi untuk menambahkan barang ke wishlist
void addToWishlist(Wishlist *wishlist, const char *item) {
    if (isInWishlist(wishlist, item)) {
        printf("%s sudah ada di wishlist!\n", item);
    } else if (!isAvailable(item)) {
        printf("Tidak ada barang dengan nama %s!\n", item);
    } else {
        strcpy(wishlist->items[wishlist->count], item);
        wishlist->count++;
        printf("Berhasil menambahkan %s ke wishlist!\n", item);
    }
}

// Fungsi untuk menukar posisi barang pada wishlist
void swapWishlistItems(Wishlist *wishlist, int i, int j) {
    if (i < 1 || i > wishlist->count || j < 1 || j > wishlist->count) {
        printf("Indeks tidak valid untuk swap!\n");
        return;
    }

    char temp[MAX_NAME_LENGTH];
    strcpy(temp, wishlist->items[i - 1]);
    strcpy(wishlist->items[i - 1], wishlist->items[j - 1]);
    strcpy(wishlist->items[j - 1], temp);

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n",
           wishlist->items[i - 1], wishlist->items[j - 1]);
}

int main() {
    char command[20];
    char itemName[MAX_NAME_LENGTH];

    while (1) {
        printf(">> ");
        scanf("%s", command);

        if (strcmp(command, "WISHLIST") == 0) {
            scanf("%s", command);
            if (strcmp(command, "ADD") == 0) {
                printf("Masukkan nama barang: ");
                getchar(); // Membersihkan newline
                fgets(itemName, MAX_NAME_LENGTH, stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Menghapus newline di akhir
                addToWishlist(&wishlist, itemName);
            } else if (strcmp(command, "SWAP") == 0) {
                int i, j;
                scanf("%d %d", &i, &j);
                if (wishlist.count < 2) {
                    printf("Gagal menukar posisi! Wishlist hanya memiliki satu atau tidak ada barang.\n");
                } else {
                    swapWishlistItems(&wishlist, i, j);
                }
            } else {
                printf("Command tidak dikenal!\n");
            }
        } else {
            printf("Command tidak dikenal!\n");
        }
    }

    return 0;
}
