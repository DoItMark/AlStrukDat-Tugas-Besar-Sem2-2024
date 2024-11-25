#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
            ADV();
        } else {
            break;
        }
    }
    currentWord.TabWord[currentWord.Length] = '\0'; // Null terminate the string
}

void StartWordFile(FILE *input) {
    readFileChar(input);
    IgnoreBlanks();
    if (currentChar == MARK || IsEOF()) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

boolean isEndWord() {
    return EndWord;
}

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0' && src[i] != MARK) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

boolean stringComp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

boolean stringSearch(const char *str, char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return true;
        }
    }
    return false;
}