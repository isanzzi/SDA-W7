#ifndef KOTA_H
#define KOTA_H
#include "linked.h"
#include "convention.h"

typedef struct
{
    char cityName[STRING_LENGTH];  // Changed from info to cityName
    address knama;
}kt;

boolean isEmptykt (kt *p);
boolean isCityInitialized(kt p);

void Initkt (kt *p);

#endif