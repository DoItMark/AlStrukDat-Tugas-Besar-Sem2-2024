#include <stdio.h>
#include <stdlib.h>
#include "ListofWishlist.h"

boolean IsEmptyListLinier(LinkedList L){
    return First(L) == Nil;
}

void CreateEmptyListLinier(LinkedList *L){
    L->First = Nil;
}

address AlokasiListLinier(nama_barang X){
     address P = (address) malloc (sizeof(ElmtList));
     if (P!=NULL){
        copyStringMap(P->info, X);
        P->next = Nil;
        return P;
     }
     else{
        return Nil;
     }
}

void DealokasiListLinier(address *P){
    free(*P);
}

address SearchListLinier(LinkedList L, nama_barang X){
    address now = First(L);
    while(now->next!=Nil){
        if(now->info!=X){
            now = now->next;
        }
        else{
            return now;
        }
    }
    if(now->info==X){
        return now;
    }
    return Nil;
}

void InsVFirst(LinkedList *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nil){
        if(IsEmptyListLinier(*L)){
            L->First = P;
        }
        else{
            P->next = L->First;
            L->First = P;
        }
    }
}

void InsVLast (LinkedList *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nil){
        InsertLast(L, P);
    }
}

void DelVFirst (LinkedList *L, nama_barang *X){
    address P;
    DelFirst(L, &P);
    copyStringMap(*X, P->info);
    DealokasiListLinier (&P);
}

void DelVLast (LinkedList *L, nama_barang *X){
    address P;
    DelLast(L, &P);
    copyStringMap(*X, P->info);
    DealokasiListLinier (&P);
}

void InsertFirst (LinkedList *L, address P){
    P->next = First(*L);
    First(*L) = P;
}

void InsertAfter (LinkedList *L, address P, address Prec){
    P->next = Prec->next;
    Prec->next = P;
}

void InsertLast (LinkedList *L, address P){
    if(IsEmptyListLinier(*L)){
        InsertFirst(L, P);
    }
    else{
        address Prec = L->First;
        while(Prec->next!=Nil){
            Prec = Prec->next;
        }
        InsertAfter(L, P, Prec);
    }
}

void DelFirst (LinkedList *L, address *P){
    *P = First(*L);
    First(*L) = First(*L)->next;
    (*P)->next = Nil;
}

void DelP (LinkedList *L, nama_barang X){
    address P = SearchListLinier(*L, X);
    if(P!=Nil){
        address now = First(*L);
        if(P == now){
            DelFirst(L, &P);
        }
        else{
            while(now->next!=P){
                now = now->next;
            }
            DelAfter(L, &P, now);
        }
    }
}

void DelAddr (LinkedList *L, address P){
    if(P!=Nil){
        address now = First(*L);
        if(P == now){
            DelFirst(L, &P);
        }
        else{
            while(now->next!=P){
                now = now->next;
            }
            DelAfter(L, &P, now);
        }
    }
}

void DelLast (LinkedList *L, address *P){
	address last = First(*L);
	address prec = Nil;

	while (Next(last) != Nil){
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == Nil){
		First(*L) = Nil; 
	} else {
		Next(prec) = Nil;
	}
}

void DelAfter (LinkedList *L, address *Pdel, address Prec){
    *Pdel = Prec->next;
    if(Prec->next!=Nil){
        Prec->next = Prec->next->next;
        (*Pdel)->next = Nil;
    }
}

void PrintInfoListLinier(LinkedList L){
    printf("[");
    if(!IsEmptyListLinier(L)){
        address W = First(L);
        while(W->next!=Nil){
            printf("%s,", W->info);
            W = W->next;
        }
        printf("%s", W->info);
    }
    printf("]\n");
}

int NbElmtListLinier(LinkedList L){
    if(IsEmptyListLinier(L)){
        return 0;
    }
    else{
        int jum = 1;
        address W = First(L);
        while(W->next!=Nil){
            jum++;
            W = W->next;
        }
        return jum;
    }
}

void InversListLinier(LinkedList *L){
   if(!IsEmptyListLinier(*L)){
        address W =First(*L);
        address sebelah = W->next;
        while(sebelah!=Nil){
            address temp = sebelah;
            sebelah = sebelah->next;
            InsertFirst(L, temp);
            W->next = sebelah;
        }
   }
}

void KonkatListLinier(LinkedList *L1, LinkedList *L2, LinkedList *L3){
    CreateEmptyListLinier(L3);
    if(IsEmptyListLinier(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);
        address W = First(*L1);
        while(W->next!=Nil){
            W = W->next;
        }
        W->next = First(*L2);
    }
    CreateEmptyListLinier(L2);
    CreateEmptyListLinier(L1);
}