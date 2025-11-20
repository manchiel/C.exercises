#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXT 10
#define MAXI 19

typedef struct tacka{
    double x;
    double y;
}TACKA;

FILE *safe_fopen(char *, char *);
void ucitaj(FILE *, TACKA *, int *);
TACKA nadji_teziste(TACKA *, int);
void ispisi(FILE *, TACKA *, int, TACKA, double);
double razdaljina(TACKA, TACKA);

int main(int argc, char **argv){

    if(argc!=3){
        printf("nije dobro pokrenut program ");
        exit(EXIT_FAILURE);
    }

    TACKA tacke[MAXT];
    int n;

    FILE *ulazna = safe_fopen(argv[1], "r");
    ucitaj(ulazna, tacke, &n );
    fclose(ulazna);

    TACKA teziste = nadji_teziste(tacke,n);

    char ime_izlaznog[] = "pripada_krugu_poluprecnika_";
    strcat(ime_izlaznog, argv[2]);
    strcat(ime_izlaznog,".txt");

    FILE *izlazni = safe_fopen(ime_izlaznog, "w"); 
    double r = atof(argv[2]);
    ispisi(izlazni, tacke, n, teziste, r);



    return 0;
}

FILE *safe_fopen(char *naziv, char *rezim){

    FILE *fp = fopen(naziv,rezim);
    if(fp == NULL){
        printf("nije moguce otvoriti fajl");

    }

    return fp;
}

void ucitaj(FILE *ulaz, TACKA *tacke, int *pn){
    int i=0;
    while(fscanf(ulaz,"%lf %lf", &tacke[i].x, &tacke[i].y ) != EOF){
        i++;
    }
    *pn = i;
}

TACKA nadji_teziste(TACKA *tacke, int n){
    TACKA teziste;
    double sumx=0; 
    double sumy=0;
    for(int i=0;i<n;i++){
        sumx += tacke[i].x;
        sumy += tacke[i].y;
    }
    teziste.x = sumx/n;
    teziste.y = sumy/n;

    return teziste;
}

void ispisi(FILE *izlaz, TACKA *tacke, int n, TACKA teziste, double poluprecnik){
    
    fprintf(izlaz, "Krug poluprecnika %lf sa centrom u (%.2lf,%.2lf)", poluprecnik, teziste.x, teziste.y );
    fprintf(izlaz,"\n");
    for(int i =0; i<n; i++){
        double d = razdaljina(tacke[i],teziste);
        if(d < poluprecnik){
            fprintf(izlaz,"(%.2lf,%.2lf)\n", tacke[i].x, tacke[i].y);
        }
    }
}
double razdaljina(TACKA t, TACKA tez){

    return sqrt(pow(t.x - tez.x, 2) + pow(t.y - tez.y, 2));

}