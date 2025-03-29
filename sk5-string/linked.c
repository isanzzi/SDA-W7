#include "linked.h"

boolean isEmpty(address p) {
    if (p==nil){
        return true;
    } else{
        return false;
    }
}

void CreateEmpty(address *q) {
    *q = nil;
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != nil) {
        strcpy(info(*p), nilai);
        next(*p) = nil;
    }
}

void InsertTitle(infotype dest) {
    printf("input name : ");
    scanf(" %[^\n]s", dest);
}

address SetNode(infotype nilai) {
    address P;
    Create_Node(&P);
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(info(P), nilai);
    next(P) = nil;
    return P;
}

void Tampil_List(address p) {
    if (isEmpty(p)) {
        printf("Empty List\n");
        return;
    }
    
    address temp = p;
    while (temp != nil) {
        printf("%s", info(temp));
        if (next(temp) != nil) {
            printf(" -> ");
        }
        temp = next(temp);
    }
    printf("\n");
}

address Search(address p, infotype nilai) {
    while (p != nil) {
        if (info(p) == nilai) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void Ins_Awal(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        next(PNew) = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        address temp = *p;
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = PNew;
    }
}

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != nil) {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
}

void Del_Awal(address *p, infotype X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        strcpy(X, info(temp));
        *p = next(temp);
        free(temp);
    }
}

void Del_Akhir(address *p, infotype X) {
    if (isEmpty(*p)) return;

    if (next(*p) == nil) {
        strcpy(X, info(*p));
        free(*p);
        *p = nil;
    } else {
        address temp = *p;
        while (next(next(temp)) != nil) {
            temp = next(temp);
        }
        strcpy(X, info(next(temp)));
        free(next(temp));
        next(temp) = nil;
    }
}

void DeleteValue(address *p, infotype target, infotype X) {
    if (*p == nil) {
        return;
    }

    if (strcmp(info(*p), target) == 0) {
        Del_Awal(p, X);
        return;
    }

    address prev = *p;
    address temp = next(prev);

    while (temp != nil && strcmp(info(temp), target) != 0) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != nil) {
        strcpy(X, info(temp));
        next(prev) = next(temp);
        free(temp);
    }
}

void DeAlokasi(address *p) {
    address temp;
    while (*p != nil) {
        temp = *p;
        *p = next(temp);
        free(temp);
    }
}

int NbElmt(address p) {
    if (p == nil) return 0;
    return 1 + NbElmt(next(p));
}