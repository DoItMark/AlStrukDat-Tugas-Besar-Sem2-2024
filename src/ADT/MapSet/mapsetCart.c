#include "mapsetCart.h"



/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */

quantitytype Quantity(Map M, keytype k)
/* Mengembalikan nilai quantity dengan key k dari M*/
/* Jika tidak ada key k pada M, akan mengembalikan undefined*/
{
    address idx = 0;

    while (idx < M.Count){
        if (bandingkan_string(M.Elements[idx].Key.name,k.name)) return M.Elements[idx].Qty;
        idx++;
    }

    return Undefined;
}

void Insert(Map *M, keytype k, quantitytype q) //bisa digunakan untuk Add Cart
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMember(*M, k)) return;

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Qty = q;
    M->Count++;
}

void Delete(Map *M, keytype k) // cart remove untuk hasil qqty = 0
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (!IsMember(*M, k)) return;

    address idx = 0, iterator;

    while (idx < M->Count) {
        if (bandingkan_string(M->Elements->Key.name,k.name)) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Qty = M->Elements[iterator].Qty;
    }

    M->Count--;
}

void SubstractQty(Map *M, keytype k, quantitytype q)
/* mengurangi quantitiy dari sebuah barang di cart*/
/* I.S M tidak kosong
	   element key k mungkin anggota / bukan anggota dari M*/
/* F.S element key q dari key k akan berkurang sejumalh key q yang di input*/
{
    if (!IsMember(*M, k)) return;
    address idx = 0 , iterator;
    while (idx < M->Count) {
        if (bandingkan_string(M->Elements[idx].Key.name,k.name))
        {
            M->Elements[idx].Qty =  M->Elements[idx].Qty - q;
            break;
        } 
        
        idx++;
    }
}


boolean IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    address idx = 0;  
    while (idx < M.Count) {
        if (bandingkan_string(M.Elements->Key.name,k.name)) return true;
        idx++;
    }
    
    return false;
}

boolean IsInToko(keytype k,ListBarang L ){
    for(int i; i = 0; i < L.Neff , i++){
        if (bandingkan_string(L.A[i].name,k.name)){
            return true;
        }
    }
    return false;
}

void PrintMap(Map M){  //bisa dipake buat show cart
    if (IsEmpty(M)){
        printf("Cart Kosong\n");
    }
    else{
        address idx = 0, iterator;
        printf("Your Cart: \n");
        printf("Nama_Barang     Harga       Qty");
        for (idx < M.Count; idx++;){
            printf("%s      %d      %d",M.Elements->Key.name,M.Elements->Key.price, M.Elements->Qty);
        }
    }
}