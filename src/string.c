#include "boolean.h"
#include "string.h"

int hitung_panjang(const char *str) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

void salin_string(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

boolean bandingkan_string(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false; 
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0'; 
}

boolean cari_karakter(const char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return true;
        }
        i++;
    }
    return false;
}