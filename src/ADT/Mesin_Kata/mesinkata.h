#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
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

void IgnoreFileBlanks();
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

boolean isEndWord();

void StartFileWord(char* input);
/* I.S. : currentChar sembarang, pita disiapkan untuk karakter pertama
          dalam file input
   F.S. : EndWord = true, dan currentChar == BLANK atau currentChar == NEWLINE;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVFileWordSpace();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin BLANK
          Jika currentChar = BLANK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordFileSpace 
            Dibuat untuk membaca kata sampai spasi dalam suatu file */

void ADVFileWordNewLine();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordFileNewLine
            Dibuat untuk membaca kata sampai spasi dalam suatu file */

void CopyWordFileSpace();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau sudah mencapai karakter terakhir dalam file
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordFileNewLine();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = NEWLINE atau sudah mencapai karakter terakhir dalam file
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void StartWordNewLine();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = NEWLINE;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata. 
          Digunakan untuk pembacaan seluruh stdin hingga diakhiri NEWLINE */

void StartWordSpace();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata
          Digunakan untuk pembacaan stdin hingga karakter BLANK */

void ADVWordNewLine();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordNewLine 
            Dibuat untuk membaca stdin yang terdiri atas beberapa baris */

void ADVWordSpace();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordSpace
            Dibuat untuk membaca stdin yang terdiri atas beberapa kata yang dipisahkan spasi */

void CopyWordNewLine();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = NEWLINE
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordSpace();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int wordToInt(Word word);
/* Melakukan konversi tipe data Word menjadi integer dan
   mengembalikan integer yang dihasilkan */

boolean compareWordToString(Word word, char* string);
/* Melakukan perbandingan antara 2 variabel dengan tipe data Word dan string.
   Menyimpan word yang telah dibuat uppercase ke array temp dan membandingkannya dengan string. 
   Mengembalikan true jika keduanya sama, false jika keduanya berbeda */

void readString(char* buffer, int bufferSize);
/* Membaca kata*/
#endif