#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE * pita;
static int retval;

void START(){ // CHANGE PITA TO FILE INPUT WHEN LOAD THEN BACK TO STDIN
    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
boolean IsEOF(){
    // START();
    return (feof(pita));

}
void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC(){
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP(){
    return (currentChar == MARK);
}
/* Mengirimkan true jika currentChar = MARK */
void closePita(){
    fclose(pita);
}

void readFileChar(FILE *f){
    pita = f;
    ADV();
    // retval = fscanf(pita, "%c", &currentChar);
}

void readString(char *str, int maxLength) {
    int idx = 0;
    START();
    while (!IsEOP() && idx < maxLength - 1) {
        str[idx] = GetCC();
        idx++;
        ADV();
    }
    str[idx] = '\0';
}