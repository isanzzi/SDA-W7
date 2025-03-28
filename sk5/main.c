#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

int main(){
    boolean lanjut=true;
    int jmlkota, i=0;
    char tambah;

    printf ("How many city : ");
    scanf ("%d", &jmlkota);
    getchar();
    kt kota [jmlkota];

    while (lanjut==true){ //loop setiap kota
        printf ("\n1. tambah kota\n");
        printf ("2. tambah nama\n");
        printf ("3. print nama di kota\n");
        printf ("4. exit\n");

        char menu;
        scanf (" %c", &menu);
        getchar();

        switch (menu){
            case '1':

            break;

            case '2':
            tambah='y';//reset

            while (tambah == 'y') { // Loop untuk menambah nama orang
                while (1) {//hanya menerima y/n
                    printf("Add people? (y/n): ");
                    scanf(" %c", &tambah);
                    getchar();
    
                    if (tambah == 'y' || tambah == 'n') {
                        break; // jika y/n keluar
                    }
                    printf("Invalid input! Please enter 'y' or 'n'.\n");
                }
                printf("Input name of person: ");
            }
            break;

            case '3':

            break;

            case '4':

            break;

            default :
            break;
        }
        
    }
//dealokasi
return 0;
}