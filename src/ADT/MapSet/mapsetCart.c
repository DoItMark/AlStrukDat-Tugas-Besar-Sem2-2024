#include "mapsetCart.h"

void copyStringMap(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int compareStrings(const char *key1, const char *key2) {
    int i = 0;
    while (key1[i] != '\0' && key2[i] != '\0') {
        if (key1[i] != key2[i]) {
            return key1[i] - key2[i];
        }
        i++;
    }
    return key1[i] - key2[i];
}


void CreateEmptyMap(Map *M){
    M->Count = Map_Nil;
}

boolean IsEmptyMap(Map M){
    return (M.Count == Map_Nil);
}

boolean IsFullMap(Map M){
    return (M.Count == MaxEl);
}

valuetype ValueMap(Map M, keytype k){
    if(IsMemberMap(M, k)){
        for(int i = 0; i<M.Count; i++){
        if(compareStrings(M.Elements[i].Key, k) == 0){
            return M.Elements[i].Value;
            break;
        }
    }
    }
    else{
        return Undefined;
    }
}

void InsertMap(Map *M, keytype k, valuetype v){
    if(!IsMemberMap(*M,k)){
        if(IsEmptyMap(*M)){
            M->Count = 1;
            copyStringMap(M->Elements[0].Key, k);
            M->Elements[0].Value = v;
        }
        else{
            int idx = M->Count;
            M->Count++;
            copyStringMap(M->Elements[idx].Key, k);
            M->Elements[idx].Value = v;
        }
    }
    else{
        int idx = IdxMemberMap(*M, k);
        M->Elements[idx].Value+=v;
    }
}

void DeleteMap(Map *M, keytype k, valuetype v){
    if(IsMemberMap(*M, k)){
        int idx = IdxMemberMap(*M, k);
        if(M->Elements[idx].Value-v<=0){
            M->Elements[idx].Value = 0;
            if(M->Count==1){
                M->Count = Map_Nil;
            }
            else{
                for(int i = idx+1; i<M->Count; i++){
                    M->Elements[i-1] = M->Elements[i];
                }
                M->Count--;
            }
        }
        else{
            M->Elements[idx].Value-=v;
        }
    }
}

boolean IsMemberMap(Map M, keytype k){
    boolean ada = false;
    for(int i = 0; i<M.Count; i++){
        if(compareStrings(M.Elements[i].Key, k)==0){
            ada = true;
            break;
        }
    }
    return ada;
}

int IdxMemberMap(Map M, keytype k){
    if(IsMemberMap(M, k)){
        for(int i = 0; i<M.Count; i++){
            if(compareStrings(M.Elements[i].Key, k)==0){
                return i;
            }
        }
    }
}