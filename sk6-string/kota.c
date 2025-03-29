#include "kota.h"

void Initkt(kt *p) {
    p->cityName[0] = '\0';  // Changed from info to cityName
    p->knama = nil;
}

boolean isEmptykt(kt *p) {
    return (p->cityName[0] == '\0' && p->knama == nil);
}

boolean isCityInitialized(kt p) {
    return (p.cityName[0] != '\0');
}