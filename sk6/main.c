#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "menu.h"

int main(){
    boolean lanjut=true;
    int kotake, i=0, maxkota = 0;
    char tambah;
    addrkt kota=nil;

    while (lanjut==true){
        MainMenu ();
        char menu;
        scanf (" %c", &menu);
        getchar();

        switch (menu){
            case '1': //init city
            {
                addrkt new;
                Createkt(&new);
                Initkt(new);
                Isikt (&new, InsertTitle());
                    if (!isCityInitialized(*new)){
                        printf ("input nama berhasil");
                    }
                Addkt (&kota, new);
                maxkota+=1;
            break;
            }

            case '2': //add name
                { 
                    while (1) {
                        printf("Add people? (y/n): ");
                        scanf(" %c", &tambah);
                        getchar();

                        if (tambah=='y') {
                            addrkt temp = kota; 
                            Tampil_ListKota (temp);
                            SearchOptions ();
                            char tambah2;
                            scanf(" %c", &tambah2);
                            switch (tambah2) {
                                case '1': {
                                    temp = ByNumberInput (kota,maxkota);
                                    break;
                                    }
                                case '2': {
                                    temp=BySearchKota (kota);
                                    break;
                                    }
                                default:
                                    break;
                            if (!isEmptykt(temp)){
                                address new;
                                PrintFirstLast();
                                char tambah2;
                                scanf (" %c", &tambah2);
                                switch (tambah2) {
                                    case '1':
                                        Create_Node (&new);
                                        Isi_Node (&new, InsertTitle());
                                        Ins_Awal (&temp, new);
                                        Tampil_List (temp->elekt);
                                        break;
                                    case'2':
                                        Create_Node (&new);
                                        Isi_Node (&new, InsertTitle());
                                        Ins_Akhir (&temp, new);
                                        Tampil_List (temp->elekt);
                                        break;
                                    default:
                                        break;
                                }
                            }

                        else if (tambah == 'n') {
                            break;
                        }
                        }
                    }
                break;
                    }
                }

            case '3': //print name
            {
            while (1){
                PrintOptions();
                char menu2;
                scanf (" %c", &menu2);
                getchar();
                switch (menu2){
                    case '1' :
                    {
                    addrkt temp=kota;
                    Tampil_ListKota (temp);
                    SearchOptions();
                    char menu3;
                    scanf (" %c", menu3);
                    switch (menu3){
                        case '1': {
                            temp=ByNumberInput(temp, maxkota);
                            break; }
                        case '2':{
                            temp=BySearchKota(temp);}
                            break;
                        default:
                            break;
                        }
                        Tampil_List(temp->elekt);
                    }
                    case '2' :
                    {
                        i=1;
                        addrkt temp=kota;
                        while (i<=maxkota){
                            if (isCityInitialized(*temp)){
                                printf ("\nCity-%d (%s):", i, temp->info);
                                if (temp->elekt != NULL) {
                                    Tampil_List(kota->elekt);
                                } else {
                                    printf(" No names registered\n");
                                }
                            }
                            temp=nextkt(temp);
                        }
                        break;
                    }
                    case '3' : {
                        break;
                    }
                    default: {
                        printf ("Invalid option\n");
                        break;
                    }
                    if (menu2 == '3'){
                    break;
                    }
                } //switch
            } //while
            break;
            } //end case

            case '4': //delete name in city
                { 
                    while (1) {
                        printf("Do you want to delete people from city? (y/n): ");
                        scanf(" %c", &tambah);
                        getchar();

                        if (tambah=='y') {
                            addrkt temp = kota; 
                            Tampil_ListKota (temp);
                            SearchOptions();
                            char tambah2;
                            scanf(" %c", &tambah2);
                            switch (tambah2) {
                                case '1':{
                                    temp=ByNumberInput (temp, maxkota);
                                    break; }
                                case '2': {
                                    temp=BySearchKota (temp);
                                    break; }
                                default:
                                break;
                            }
                            if (!isEmptykt(temp)){
                                PrintForDelete();
                                infotype deleted;
                                char tambah3;
                                scanf (" %c", &tambah3);
                                switch (tambah2) {
                                    case '1':
                                        Del_Awal (&(temp)->elekt, deleted);
                                        printf ("name deleted is %s\n", deleted);
                                        break;
                                    case'2':
                                        Del_Akhir (&(temp)->elekt, deleted);
                                        printf ("name deleted is %s\n", deleted);
                                    case '3':
                                        char *searching=InsertTitle();
                                        DeleteValue (&(temp)->elekt, searching, deleted);
                                        printf ("name deleted is %s\n", deleted);
                                    default:
                                        break;
                                }
                            }
                        }
                        else if (tambah == 'n') {
                            break;
                        }

                    }
                break;
                }

            case '5': //delete city
                {
                    while (1) {
                        printf("Do you want to delete a city? (y/n): ");
                        scanf(" %c", &tambah);
                        getchar();

                        if (tambah=='y') {
                            addrkt temp = kota; 
                            Tampil_ListKota (temp);
                            SearchOptions();
                            char tambah2;
                            scanf(" %c", &tambah2);
                            switch (tambah2) {
                                case '1':{
                                    temp=ByNumberInput (temp, maxkota);
                                    break; }
                                case '2': {
                                    temp=BySearchKota (temp);
                                    break; }
                                default:
                                break;
                            }
                            if (!isEmptykt(temp)){
                                DeAlokasi(temp->elekt);
                                DeAlokasiKota (temp);
                            }
                        }
                        else if (tambah == 'n') {
                            break;
                        }

                    }
                break;
                }

            case '6'://exit
                while (!isEmptykt(kota)){
                    while (!isEmpty(kota->elekt)){
                    DeAlokasi(&(kota)->elekt);
                    }
                DeAlokasiKota(&kota);
                }
                printf ("dealokasi success\n");
                lanjut = false;
            break;

            default :
            break;
        }
    }
}