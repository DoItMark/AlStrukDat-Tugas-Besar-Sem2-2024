/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"

#define NEWLINE '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;
extern boolean endOfFile;

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

void StartReadFile(char* input);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari file input.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika belum mencapai karakter terakhir dalam file, maka EOP akan padam (false)
          Jika telah mencapai karakter terakhir dalam file, maka EOP akan menyala (true) */

void ADVFile();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, belum mencapai karakter terakhir dalam file
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          Jika belum mencapai karakter terakhir dalam file, maka EOP akan padam (false)
          Jika telah mencapai karakter terakhir dalam file, maka EOP akan menyala (true) */

void StartReadNewLine();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != NEWLINE maka EOP akan padam (false)
          Jika currentChar = NEWLINE maka EOP akan menyala (true) */

void ADVNewLine();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = NEWLINE
          Jika  currentChar = NEWLINE maka EOP akan menyala (true) */

boolean isFileValid(char* input);

#endif