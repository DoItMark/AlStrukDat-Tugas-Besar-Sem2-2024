#include "../../boolean.h"

#ifndef mapsetCart_H
#define mapsetCart_H

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-astatik rata kiri
*/

// #define false 0
// #define true 1
#define Map_Nil 0
#define MaxEl 100
#define Undefined -999

// typedef int bool;
typedef char keytype[MaxEl];
typedef int valuetype;
typedef int map_address;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxEl];
	map_address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

void copyStringMap(char *dest, const char *src);

int compareStrings(const char *key1, const char *key2);

void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

valuetype ValueMap(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M dengan value v, apabila k sudah ada maka ditambahkan valuenya dengan v */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, value ditambah dengan nilai v */

void DeleteMap(Map *M, keytype k, valuetype v);
/* Mengurangi value Elmt dengan v, apabila v<=0 maka dihapuskan dari M */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k valuenya dikurangi v, kalau kurang dari 1 maka dihapuskan dari M. Jika bukan member maka dibiarkan. */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

int IdxMemberMap(Map M, keytype k);
/* Mengembalikan Indeks dari key pada M apabila key merupakan bagian dari M*/
#endif