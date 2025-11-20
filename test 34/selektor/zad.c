#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXIME 21
#define MAXPREZIME 31
#define MAXPOZICIJA 11
#define MAXIGRACA 30

typedef struct igraci{
    char ime[MAXIME];
    char prezime[MAXPREZIME];
    int broj_dresa;
    char pozicija[MAXPOZICIJA];
}IGRAC;

FILE *safe_fopen(char *naziv, char *rezim, int greska);
void ucitaj(FILE *ulazni, IGRAC *igraci, int *pn );
void ispisi(FILE *izlazni, IGRAC *igraci, int n, int o, int s, int na);
void analizirajpostavu(char *formacija , int *po, int *ps, int *pn);

int main(int argc, char **argv){

    if(argc != 4){
        printf(" Nije dobar unos, primer kako treba: %s fudbaleri.txt postava.txt 4-3-3 ", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n;
    IGRAC igraci[MAXIGRACA];

    FILE *ulazni = safe_fopen(argv[1], "r", 4);
    ucitaj(ulazni, igraci, &n);
    fclose(ulazni);

    int odbrana, sredina , napad;
    analizirajpostavu(argv[3], &odbrana, &sredina, &napad);
    FILE *izlazni = safe_fopen(argv[2], "w", 5);
    ispisi(izlazni,igraci,n, odbrana, sredina , napad);

    return 0;
}

FILE *safe_fopen(char *naziv, char *rezim, int greska){
    FILE *fp = fopen(naziv, rezim );
    if(fp == NULL){
        exit(greska);
    }
    return fp;
}

void ucitaj(FILE *ulazni, IGRAC *igraci, int *pn ){
    int odb=0, srd=0, nap=0;
    int i=0; 
    while(fscanf(ulazni,"%s %s %2d %s", igraci[i].ime, igraci[i].prezime, &igraci[i].broj_dresa, igraci[i].pozicija)!=EOF){
        if(strcmp(igraci[i].pozicija,"odbrana")== 0){
            odb++;
        }else if (strcmp(igraci[i].pozicija,"sredina")== 0){
            srd++;
        }else if(strcmp(igraci[i].pozicija,"napad")== 0){
            nap++;
        }
        i++;
    }
    if(odb>5 || srd>5 || nap>5){
        exit(3);
    }
    else{
        *pn = i;
    }

}
void analizirajpostavu(char *formacija, int *po, int *ps, int *pn){
    if(strlen(formacija) != 5 || formacija[1] != '-' || formacija[3] != '-'){
        printf("formacija nije dobro uneta\n");
        exit(2);
    }
    *po = formacija[0] -'0';
    *ps = formacija[2] - '0';
    *pn = formacija[4] - '0';

}

void ispisi(FILE *izlazni, IGRAC *igraci, int n, int o, int s, int na){
    for(int i =0 ;i <n ; i++){
        if(strcmp(igraci[i].pozicija,"napad") == 0 && na !=0 ){
            fprintf(izlazni, "%2d %s %c.\n", igraci[i].broj_dresa, igraci[i].prezime, igraci[i].ime[0]);
            na--;
        }
        if(strcmp(igraci[i].pozicija,"sredina") == 0 && s !=0 ){
            fprintf(izlazni, "%2d %s %c.\n", igraci[i].broj_dresa, igraci[i].prezime, igraci[i].ime[0]);
            s--;
        }
        if(strcmp(igraci[i].pozicija,"odbrana") == 0 && o !=0 ){
            fprintf(izlazni, "%2d %s %c.\n", igraci[i].broj_dresa, igraci[i].prezime, igraci[i].ime[0]);
            o--;
        }
    }

}