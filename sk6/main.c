#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

int main(){
    boolean lanjut=true;
    int kotake, i=0, maxkota = 0;
    char tambah;
    addrkt kota=nil;

    while (lanjut==true){
        printf ("\n1. add/init city\n");
        printf ("2. add name in city\n");
        printf ("3. print name\n");
        printf ("4. delete first name\n");
        printf ("5. modify city name\n");
        printf ("6. exit\n");
        printf ("input the number you choose : ");

        char menu;
        scanf (" %c", &menu);
        getchar();

        switch (menu){
            case '1':
                addrkt new;
                Createkt(&new);
                Initkt(new);
                Isikt (&new, InsertTitle());
                    if (!isEmptykt(new)){
                        printf ("input nama berhasil");
                    }
                Addkt (&kota, new);
            break;

            case '2':
                { 
                    while (1) {
                        printf("Add people? (y/n): ");
                        scanf(" %c", &tambah);
                        getchar();

                        if (tambah=='y') {
                            printf("\n1. add by number input");
                            printf("\n2. add by search name");
                            printf("\ninput your choice : ");
                            addrkt temp = kota; 
                            char tambah2;
                            scanf(" %c", &tambah2);
                            switch (tambah2) {
                                case '1':
                                    {
                                        i = 0;
                                        scanf("%d", &kotake);
                                        if (kotake >= 0) {
                                            if (!isCityInitialized(*temp)) {
                                                printf("City not initialized. Please initialize city first\n");
                                                break;
                                            }
                                            while (i < kotake && temp != nil) {
                                                temp = nextkt(temp);
                                                i++;
                                            }
                                        } else {
                                            printf("Invalid city number\n");
                                        }
                                    }
                                    break;

                                case '2':
                                    {
                                        char *cari = InsertTitle();
                                        addrkt found = nil;
                                        while (temp != nil) {
                                            if (strcmp(temp->info, cari) == 0) {
                                                found = temp;
                                                printf("Data ditemukan!\n");
                                                break;
                                            }
                                            temp = nextkt(temp);
                                        }
                                        if (found == nil) {
                                            printf("data tidak ditemukan\n");
                                        }
                                        free(cari);
                                    }
                                    break;
                            }
                        } else if (tambah == 'n') {
                            break;
                        }
                    }
                }
                break;

            case '3':
            while (1){
                printf ("\n1. print only in input city");
                printf ("\n2. print entire city");
                printf ("\n3. exit");
                printf ("\ninput your choice : ");
                char menu2;
                scanf (" %c", &menu2);
                getchar();
                switch (menu2){
                    case '1' :
                    {
                        printf ("Input which city you want to print : ");
                        scanf("%d", &kotake);
                        kotake--;
                        addrkt temp =kota;
                        i=0;
                        if (kotake >= 0){
                            if (!isCityInitialized(*temp)) {
                                printf("City not initialized\n");
                            } else if (temp->elekt->info == nil) {
                                printf("No names in this city\n");
                            } else {
                                while (i<kotake){
                                temp=nextkt(temp);
                                }
                                printf ("%s", temp->elekt->info);
                            }
                        }
                        else {
                            printf ("Invalid city number\n");
                        }
                        break;
                    case '2' :
                        i=0;
                        addrkt temp;
                        while (i<maxkota){
                            if (isCityInitialized(*temp)){
                                printf ("\nCity-%d (%s):", i+1, temp->info);
                                if (temp->elekt != NULL) {
                                    Tampil_List(kota->elekt);
                                } else {
                                    printf(" No names registered\n");
                                }
                            }
                            temp=nextkt(temp);
                        }
                        break;
                    case '3' : 
                        break;
                    default:
                        printf ("Invalid option\n");
                        break;
                }
                if (menu2 == '3'){
                    break;
                }
            }
            break;

            case '4':
                printf("\nWhich city number do you want to delete from (1-%d): ", maxkota);
                scanf("%d", &kotake);
                kotake--; 
                if (kotake > 0) {
                    if (!isCityInitialized(kota[kotake])) {
                        printf("City not initialized\n");
                    } else if (kota[kotake].info != nil && kota[kotake].elekt->info==nil){ // Fixed: check first character instead of pointer
                        printf ("name city - %s", kota[kotake].info);
                        printf ("but no name in this city");
                    } else {
                        printf("Current list: ");
                        Tampil_List(kota[kotake].elekt);
                        infotype deleted;
                        Del_Awal(&(kota[kotake].elekt), &deleted);
                        printf("Deleted name: %s\n", deleted);
                        free(deleted); 
                        printf("Updated list: ");
                        Tampil_List(kota[kotake].elekt);
                    }
                } else {
                    printf("Invalid city number. Please enter 1-%d\n", jmlkota);
                }
                break;

            case '5':
                printf("\nWhich city to modify? (1-%d): ", jmlkota);
                scanf("%d", &kotake);
                kotake--;
                if (kotake >= 0 && kotake < jmlkota) {
                    if (!isCityInitialized(kota[kotake])) {
                        printf("City not initialized\n");
                    } else {
                        ModifyString(kota[kotake].info);
                    }
                }
                break;

            case '6':
                i=0;
                while (i<jmlkota){
                    if (kota[i].info != NULL) {
                        free(kota[i].info);
                    }
                    DeAlokasi(&(kota[i].elekt));
                    i++;
                }
                printf ("dealokasi success\n");
                lanjut = false;
            break;

            default :
            break;
        }
    }
}
}