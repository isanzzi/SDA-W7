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

void Tampil_ListKota (addrkt k){
    if (isEmptykt(k)){
        printf ("empty list\n");
        return;
    } 
    else if (isEmptynm(*k)) {
        printf ("no people\n");
        return;
    } 
    else {
        addrkt temp=k;
        int i=0;
        while (k!=nil){
            printf ("city-%d (%s)", (i+1), nm(k));
        }
    }
}

addrkt ByNumberInput(addrkt k, int maxkota) {
    int kotake, i = 1;
    printf("Masukkan nomor kota: ");
    scanf("%d", &kotake);
       
    addrkt temp = k;
    if (kotake > 0 && kotake <= maxkota) {
        if (!isCityInitialized(*temp)) {
            printf("City not initialized. Please initialize city first\n");
            return nil;
        }
        while (i < kotake && temp != nil) {
            temp = nextkt(temp);
            i++;
        }
        return temp;
    } 
    else {
        printf("Invalid city number\n");
        return nil;
    }
}

addrkt BySearchKota(addrkt k) {
    char *cari = InsertTitle();
    addrkt compare = k;
       
    while (compare != nil) {
        if (strcmp(compare->info, cari) == 0) {
            printf("Data ditemukan!\n");
            free(cari);
            return compare;
        }
        compare = nextkt(compare);
    }
       
    printf("Data tidak ditemukan\n");
    free(cari);
    return nil;
}

void DeAlokasiKota(addrkt *k){
    addrkt temp;
    while (*k !=nil){
        temp=*k;
        *k=nextkt(temp);
        free (temp);
    }
}