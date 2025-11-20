#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX1 11
#define MAX2 4
#define MAX3 25
#define DUZINA1 5000
#define DUZINA2 10000


typedef struct letovi{

    char id_leta[MAX1];
    char mestop[MAX2];
    char mestod[MAX2];
    int duzina_leta;
    int br_presedanja;
}LET;

FILE *safe_fopen(char *, char*, int);
void ucitaj(FILE *,LET *, int *);
void ispisi(FILE *, LET *,char *, int);
double cena_leta(LET);

int main(int argc, char ** argv){

int n;
LET letovi[MAX3];

if( argc!=3 ){
    printf("Nije dobro uneta komandna linija");
    exit(1);
}

FILE *ulazni = safe_fopen(argv[1], "r", 1);
ucitaj(ulazni,letovi, &n);
fclose(ulazni);

char ime_izlazne[MAX3] = "Letovi_ka_";
strcat(ime_izlazne, argv[2]);
strcat(ime_izlazne,".txt");
FILE *izlazna = safe_fopen(ime_izlazne, "w", 2);
ispisi(izlazna, letovi,argv[2], n);
fclose(izlazna);






    return 0;
}

FILE *safe_fopen(char *naziv, char *rezim, int greska){
    FILE *fp = fopen(naziv,rezim);
    if(fp == NULL ){
        printf("Nije moguce otvoriti fajl");
        exit(2);

    }
    return fp;
}

void ucitaj(FILE *ulazni,LET *letovi, int *pn){
    int i =0;
    while(fscanf(ulazni,"%s %s %s %d %d",letovi[i].id_leta, letovi[i].mestop, letovi[i].mestod, &letovi[i].duzina_leta, &letovi[i].br_presedanja) != EOF){
        i++;
    }
    *pn = i;
}

void ispisi(FILE *izlazna, LET *letovi, char *mesto, int n){
    int br =0;
    for(int i = 0 ; i < n ; i++ ){
        if(strcmp(mesto, letovi[i].mestod)==0){

            double cena = cena_leta(letovi[i]);
            fprintf(izlazna,"%s %s %.2lf\n", letovi[i].id_leta, letovi[i].mestop, cena);
            br=1;

        }
        
    }
    if(br == 0){
        fprintf(izlazna," Nema letova zatu destinaciju sry sir");
    }
}
double cena_leta(LET let){
    if(let.duzina_leta<5000 ){
        return let.duzina_leta * 0.5 - 5*let.br_presedanja;
    }
    else if(let.duzina_leta > DUZINA1 && let.duzina_leta < DUZINA2){
        return let.duzina_leta * 0.75 - 5*let.br_presedanja;
    }
    else{

        return let.duzina_leta - 5*let.br_presedanja;
    }
    
}