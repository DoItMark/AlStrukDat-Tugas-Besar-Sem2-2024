/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESINKARAKTER_H_
#define __MESINKARAKTER_H_

#include <stdio.h>

#define MARK '\n'
#define MARK_newline '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

void closePita();

void readFileChar(FILE * f);

boolean IsEOF();

void readString(char *str, int maxLength);
#endif