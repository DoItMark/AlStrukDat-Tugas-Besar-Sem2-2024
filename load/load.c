#include <stdio.h>
#include <stdlib.h>
#include "load.h"

//file load
void LOAD(const char *filename) {
    char filepath[100]; //tidak perlu diganti jd main.c, menyimpan path
    FILE *saveFile = fopen("save.txt", "w"); 
    if (saveFile == NULL) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    printf("Save file berhasil ditemukan. PURRMART berhasil dijalankan.\n");
    printf("Meload...");
    
    STARTWORD();
            while (!EndWord) {
                for (int i = 0; i < currentWord.Length; i++) {
                    fprintf(currentWord.TabWord[i], saveFile);
                }
            fprintf(' ', saveFile);
            ADVWORD();
        }
    fclose(saveFile); 
}

int main(){
    char filename[100];

    LOAD(filename);
}
