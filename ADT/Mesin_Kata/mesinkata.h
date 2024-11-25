#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Mesin_Karakter/mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct {
   char TabWord[NMax];
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void StartWordFile(FILE *input);
/* Memulai mesin kata dengan input dari file */

boolean isEndWord();
/* Mengecek apakah sudah mencapai akhir kata */

int stringLength(const char *str);
/* Menghitung panjang string */

void stringCopy(char *dest, const char *src);
/* Menyalin string dari src ke dest */

boolean stringComp(const char *str1, const char *str2);
/* Membandingkan dua string */

boolean stringSearch(const char *str, char ch);
/* Mencari karakter dalam string */

#endif