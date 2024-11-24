#include <stdio.h>
#include <stdlib.h>

int main() {
    int Neff = 6; // Jumlah elemen test case
    char **storeItems; // Pointer ke array dinamis untuk string

    // Alokasi memori untuk array dinamis
    storeItems = (char **)malloc(Neff * sizeof(char *));
    if (storeItems == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; // Keluar dari program dengan kode error
    }

    // Mengisi array dinamis dengan test case
    storeItems[0] = "Platypus Laser";
    storeItems[1] = "Shrink Ray";
    storeItems[2] = "Net Shooter";
    storeItems[3] = "Camouflage Cloak";
    storeItems[4] = "Sleep Dart Gun";
    storeItems[5] = "Bubble Blaster";

    // Menampilkan daftar barang
    printf("List barang yang ada di toko:\n");
    for (int i = 0; i < Neff; i++) {
        printf("- %s\n", storeItems[i]);
    }

    // Membersihkan memori (tidak diperlukan karena kita tidak melakukan malloc per string)
    free(storeItems);

    return 0;
}
