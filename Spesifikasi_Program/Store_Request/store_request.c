#include <stdio.h>
#include <stdlib.h>
#include "store_request.h"

void Store_Request(Queue *antrian, ArrayDin *toko){
    printf("Nama barang yang diminta: ");
    STARTWORD();

   InsertLast(&toko, barang);

    if {
    SearchArrayDin(*toko, barang);
    print("Barang dengan nama yang sama sudah ada di toko!");
    }
    else if {
    SearchQueue(*antrian, barang);
    print("Barang dengan nama yang sama sudah ada di antrian!");
    }
    else {
    enqueue(*antrian, barang);
    printf("Barang anda sudah ditambahkan ke dalam antrian!");
    }
}

// int main() {
//     Barang barangList[3] = {
//         {"Platypus Laser", 10000},
//         {"Shrink Ray", 5000},
//         {"Net Shooter", 7500}
//     };

//     Queue antrianBarang;
//     SearchQueue(&antrianBarang);

//     STORE_REQUEST(barangList, totalBarang, &antrianBarang);

//     return 0;
// }