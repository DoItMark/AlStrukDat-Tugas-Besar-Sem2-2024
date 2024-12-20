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
