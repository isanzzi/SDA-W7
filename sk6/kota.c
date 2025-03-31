#include "kota.h"

boolean isEmptynm (kt k){
    return (k.info == nil && k.elekt == nil);
}

boolean isCityInitialized(kt k) {
    return (k.info != nil);
}

boolean isEmptykt (kt *k){
    return (k==nil);
}

void Initkt (kt *k){
    nm(k)=nil;
    nextkt(k)=nil;
    k->elekt->info=nil;
    k->elekt->next=nil;
}

void Createkt (addrkt *k){
    *k = (addrkt) malloc (sizeof (kt));
}

void Addkt (addrkt *k, addrkt knew){
    if (isEmptykt(*k)) {
        *k = knew;
    } else {
        nextkt(knew) = *k;
        *k = knew;
    }
}

void Isikt (addrkt *k, infotype nilai){
    if (*k != nil){
        nm(*k)=nilai;
        nextkt(*k)=nil;
    }
}

addrkt SetKota (infotype *nilai){
    addrkt k;
    Createkt (&k);
    if (isEmptykt(k)){
        printf ("malloc failed\n");
        return nil;
    }
    nm(k)=*nilai;
    nextkt(k)=nil;
    return k;
}

void TampilKota (addrkt k){
    if (isEmptykt(k)){
        printf ("empty list\n");
        return;
    } 
    else if (isEmptynm(*k)) {
        printf ("no people\n");
        return;
    } 
    else {
        printf ("%s", nm(k));
    }
}