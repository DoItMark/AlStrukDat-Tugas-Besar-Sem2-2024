#include <stdio.h>
#include <stdlib.h>
#include "save.h"

// saving
void SAVE(const char *filename) {
    char filepath[100];
    FILE *saveFile = fopen("save.txt", "w");
    if (saveFile == NULL) {
        printf("Gagal menyimpan file.\n");
        return;
    }
    STARTWORD();
        while (!EndWord) {
            for (int i = 0; i < currentWord.Length; i++) {
                fprintf(currentWord.TabWord[i], saveFile);
            }
        fprintf(' ', saveFile);

        ADVWORD();
        }
    fclose(saveFile); 
    printf("Save file berhasil disimpan.\n");
}

int main(){
    char filename[100];

    SAVE(filename);
}