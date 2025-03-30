#ifndef KOTA_H
#define KOTA_H
#include "linked.h"
#include "convention.h"

typedef struct kota *addrkt;
typedef struct kota{
    infotype info;
    address elekt; //pointer ke telmt list
    addrkt nextkt;
}kt;

boolean isEmptykt (kt *k);
boolean isCityInitialized(kt p);

void Initkt (kt *p);

#endif