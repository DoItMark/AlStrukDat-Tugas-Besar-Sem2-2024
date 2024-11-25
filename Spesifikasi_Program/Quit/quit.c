#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void QUIT(Barang *barang_list, Pengguna *pengguna_list) {
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    START();
    chat input;
    input = getChar();


    if (input == 'Y' || input == 'y') {
        SAVE("savefile.txt", barang_list, pengguna_list);
        printf("Data sesi disimpan.\n");
        
    }
    else if (input == 'N' || input == 'n') {
        printf("Data sesi tidak disimpan\n");
    }
    else {
        printf("Input tidak valid\n");
    }

    printf("Kamu keluar dari PURRMART.\nDadah ^_^\n");

}

// int main() {
//     Barang barang_List[3] = {
//         {"Platypul Laser", 10000},
//         {"Shrink Ray", 5000},
//         {"Net Shooter", 7500}
//     };
//     Pengguna pengguna_list[2] = {
//         {"Alice", "alice123", 100000},
//         {"Bob", "bob456", 50000}
//     };

//     QUIT(barang_list, pengguna_list);

//     return 0;
// }

