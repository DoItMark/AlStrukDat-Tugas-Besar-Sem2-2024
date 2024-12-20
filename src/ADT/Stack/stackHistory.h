#include "../../boolean.h"

#ifndef stackHistory_H
#define stackHistory_H

#define Stack_Nil -1
#define MaxEl 100

typedef struct {
  char name[MaxEl];
  int totalharga;
} barang_dibeli;
typedef int stack_address;

typedef struct { 
  barang_dibeli T[MaxEl]; 
  stack_address TOP;
  int size;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

void PushStack(Stack * S, barang_dibeli X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void PopStack(Stack * S, barang_dibeli* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif