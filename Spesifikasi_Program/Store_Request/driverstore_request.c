#include <stdio.h>
#include <stdlib.h>
#include "store_request.c"

int main() {
    Barang barangList[3] = {
        {"Platypus Laser", 10000},
        {"Shrink Ray", 5000},
        {"Net Shooter", 7500}
    };

    Queue antrianBarang;
    SearchQueue(&antrianBarang);

    STORE_REQUEST(barangList, totalBarang, &antrianBarang);

    return 0;
}