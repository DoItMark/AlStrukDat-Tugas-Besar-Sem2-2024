#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (q.idxHead == IDX_UNDEF) && (q.idxTail == IDX_UNDEF);
}

boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return ((q.idxHead == 0) && (q.idxTail == CAPACITY-1));
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q)) {
        return 0;
    } else {
        return q.idxTail - q.idxHead + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{ 
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        (*q).idxTail = ((*q).idxTail + 1) % CAPACITY;
    }
    (*q).buffer[(*q).idxTail] = val;
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val = (*q).buffer[(*q).idxHead];
    
    if ((*q).idxHead == (*q).idxTail) {
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    } else {
        (*q).idxHead = (*q).idxHead + 1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i;

    if (isEmpty(q)) {
        printf("[]\n");
    } else {
        printf("[");
        for (i = q.idxHead; i <= q.idxTail; i++) {
            if (i == q.idxTail) {
                printf("%d", q.buffer[i]);
            } else {
                printf("%d,", q.buffer[i]);
            }
        }
        printf("]\n");
    }
}