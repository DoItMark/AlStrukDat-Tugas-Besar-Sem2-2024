#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../List_Dinamis/ListofBarang.h"
#include "../string/string.h"
#include "../Barang/barang.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/
/* Diedit untuk menyesuaikan kebutuhan tugas
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 205
#define Undefined 0

// typedef int bool;
typedef Barang keytype; // keytype = nama barang
typedef int quantitytype; // jumlah barang
typedef int address;

typedef struct {
	keytype Key;
	quantitytype Qty;
} infotype; // infotype jadi char nama_barang, int harga_barang

typedef struct {
	infotype Elements[MaxEl];
	address Count;
} Map; // map jadi Qty. Infotype

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */

quantitytype Quantity(Map M, keytype k);
/* Mengembalikan nilai quantity dengan key k dari M*/
/* Jika tidak ada key k pada M, akan mengembalikan undefined*/

void Insert(Map *M, keytype k, quantitytype);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

void SubstractQty (Map *M, keytype k, quantitytype q);
/* mengurangi quantitiy dari sebuah barang di cart*/
/* I.S M tidak kosong
	   element key k mungkin anggota / bukan anggota dari M*/
/* F.S element key q dari key k akan berkurang sejumalh key q yang di input*/

boolean IsMember(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

boolean IsInToko (keytype k, ListBarang L);
/* mengembalika nilai true jika key k ada di toko */
/* I.S L bisa kosong*/
/* F.S mengembalikan nilai boolean berdasakarkan keberadaan key k pada List toko*/

void PrintMap (Map M);
/* mencetak map yang di input*/
/* I.S M Bisa Kosong*/
/* F.S Isi Element dari map tercetak di terminal */

#endif