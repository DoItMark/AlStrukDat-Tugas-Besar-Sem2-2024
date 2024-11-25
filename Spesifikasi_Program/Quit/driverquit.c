#include <stdio.h>
#include "quit.c"

int main() {
    Barang barang_List[3] = {
        {"Platypul Laser", 10000},
        {"Shrink Ray", 5000},
        {"Net Shooter", 7500}
    };
    Pengguna pengguna_list[2] = {
        {"Alice", "alice123", 100000},
        {"Bob", "bob456", 50000}
    };

    QUIT(barang_list, pengguna_list);

    return 0;
}