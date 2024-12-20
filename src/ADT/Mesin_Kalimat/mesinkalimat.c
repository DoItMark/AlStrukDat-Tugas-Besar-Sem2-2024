#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat CurrentKalimat;

void IgnoreBlank(){
    while(GetCC()==BLANK){
        ADV();
    }
}

void STARTKALIMAT(){
    START();
    IgnoreBlank();
    EndKalimat = GetCC() == NEWLINE;
    if (!EndKalimat) {
        ADVKALIMAT();
    }
}

void ADVKALIMAT(){
    IgnoreBlank();
    EndKalimat = GetCC()==NEWLINE;
    if(!EndKalimat){
        CopyKalimat();
    }
}

void CopyKalimat(){
    int i = 0;
    while(GetCC()!=NEWLINE && i<Max){
        CurrentKalimat.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    CurrentKalimat.TabWord[i] = '\0';
    CurrentKalimat.Length = i;
}

boolean compareKalimatToString(Kalimat word, char* string) {
    int stringLength = 0;
    char temp[50];

    for (int i = 0; string[i] != '\0'; i++){
        stringLength++;
    }

    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] != '\n'){    
            if (word.TabWord[i] >= 'a' && word.TabWord[i] <= 'z'){
                temp[i] = word.TabWord[i] - 32;
            }else {
            temp[i] = word.TabWord[i];
            }
        }
        
    }

    if (word.Length == stringLength) {
        for (int i = 0; i < word.Length; i++){
            if(temp[i] != string[i]){
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}