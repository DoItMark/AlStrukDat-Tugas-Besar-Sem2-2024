#include "ArrayDinofBarang.h"
#include <stdio.h>
#include <stdlib.h>
#include "QueueBarang.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "barang.h"
#include "string.h"

void StoreSupply(Queue *AntrianBarang, ArrayDin *ListBarang){
    boolean quit = false;
    while (!quit){
        printf("Apakah kamu ingin menambahkan barang %c : ",HEAD(*AntrianBarang));
        STARTWORD();
        if (banding_kata(currentWord.TabWord,"Terima")){
            Barang item;
            salin_string(item.name,HEAD(*AntrianBarang));
            printf("Harga barang : ");
            STARTWORD();
            item.price = atoi(currentWord.TabWord);
            InsertLast(ListBarang,item);
            printf("%s seharga %d telah dimasukkan ke toko",item.name,item.price);
        }
        else if(banding_kata(currentWord.TabWord,"Tunda")){
            char item;
            dequeue(&AntrianBarang,item);
            enqueue(&AntrianBarang,item);
            printf("%s di tunda dalam antrian",item);
        }
        else if(banding_kata(currentWord.TabWord,"Tolak")){
            char item;
            dequeue(&AntrianBarang,item);
            printf("%s di hapus dari antrian",item);
        }
        else if(banding_kata(currentWord.TabWord,"PURRY")){
            quit = true;
        }
        else{printf("input salah");
        }
        
    }
    
}