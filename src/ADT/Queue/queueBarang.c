#include <stdio.h>
#include "queueBarang.h"

void CreateQueuebarang(Queuebarang *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptybarang(Queuebarang q){
    return ((IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}

boolean isFullbarang(Queuebarang q){
    return ((IDX_TAIL(q)-IDX_HEAD(q)+1)%CAPACITY==0);
}

int lengthbarang(Queuebarang q){
    if (isEmptybarang(q)){
        return 0;
    }
    else{
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            return (IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
        else{
            return (CAPACITY+IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
    }
}

void enqueuebarang(Queuebarang *q, elType val){
    if (isEmptybarang(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q)+=1;
        IDX_TAIL(*q)=IDX_TAIL(*q)%CAPACITY;
        (*q).buffer[IDX_TAIL(*q)] = val;
    }
}

void dequeuebarang(Queuebarang *q, elType *val){
    *val = HEAD(*q);
    if(lengthbarang(*q)==1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)+=1;
        IDX_HEAD(*q) = IDX_HEAD(*q)%CAPACITY;
    }
}