/* File : queueBarang.h */
/* Definisi ADT QueueBarang dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEBARANG_H
#define QUEUEBARANG_H

#include "../../boolean.h"
#include "barang.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef Barang ElType;
typedef struct {
    ElType buffer[CAPACITY]; 
    int idxHead;
    int idxTail;
} QueueBarang;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueBarang, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueueBarang(QueueBarang *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(QueueBarang q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(QueueBarang q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar */

int length(QueueBarang q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(QueueBarang *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(QueueBarang *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueBarang *** */
void displayQueueBarang(QueueBarang q);
/* Proses : Menuliskan isi QueueBarang dengan traversal, QueueBarang ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueBarang kosong : menulis [] */

boolean SearchQueueBarang(QueueBarang q, char *name);
/* Mengirim true jika terdapat elemen dengan nama yang sesuai dalam queue */

#endif