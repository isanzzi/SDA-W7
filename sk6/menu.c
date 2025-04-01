#include <stdio.h>
#include "menu.h"

void MainMenu (){
        printf ("\n1. add/init city\n");
        printf ("2. add name in city\n");
        printf ("3. print name\n");
        printf ("4. delete name in city\n");
        printf ("5. delete city\n");
        printf ("6. exit\n");
        printf ("input the number you choose : ");
}

void SearchOptions(){
    printf("\n1. by number input");
    printf("\n2. by search kota name");
    printf("\ninput your choice : ");
}

void PrintOptions(){
    printf ("\n1. print only in input city");
    printf ("\n2. print entire city");
    printf ("\n3. exit");
    printf ("\ninput your choice : ");
}

void PrintFirstLast(){
    printf ("1. first\n");
    printf ("2. last\n");
    printf ("input your choice: ");
}

void PrintForDelete (){
    printf ("1. first\n");
    printf ("2. last\n");
    printf ("3. search name");
}
