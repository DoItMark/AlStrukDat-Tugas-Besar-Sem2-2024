#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

int main(){
    // TEST MEMBACA KARAKTER DARI FILE
    StartReadFile("test.txt");
    printf("Karakter pertama di file test.txt adalah: %c\n", GetCC());
    while(!endOfFile){
        ADVFile();
    }
    printf("\n");

    // TEST MEMBACA KARAKTER DARI INPUT
    printf("Masukkan satu karakter dan tekan ENTER: ");
    StartReadNewLine();
    printf("Kamu menulis: %c\n", GetCC());
    printf("\n");
    if(IsEOP){
        printf("Selesai\n");
    }
}