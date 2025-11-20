#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>

#define MAX_NAZIV 21
#define MAX_RESTORANI 20

typedef struct restoran {
    char naziv[MAX_NAZIV];
    double cena_po_osobi;
    int kapacitet;
    int broj_konobara;
}RESTORAN;

double racunanje_koeficijenta(RESTORAN a, int broj_gostiju) {
    return a.cena_po_osobi / ((broj_gostiju)/(a.broj_konobara));
}

RESTORAN pronadji_optimalni_restoran (RESTORAN *restorani, int n, int broj_gostiju) {
    RESTORAN optimalni_restoran;
    double min_koeficijent, koeficijent_restorana; 
    
    for (int i = 0; i < n; i++) {
        if(restorani[i].kapacitet >= broj_gostiju) {
            optimalni_restoran = restorani[i];
            min_koeficijent = racunanje_koeficijenta(restorani[i], broj_gostiju);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (restorani[i].kapacitet > broj_gostiju) {
            if(racunanje_koeficijenta(restorani[i], broj_gostiju) < min_koeficijent) {
                min_koeficijent = racunanje_koeficijenta(restorani[i], broj_gostiju);
                optimalni_restoran = restorani[i];
            }
        }
    }
}

FILE *safe_fopen(char *ime, char *rezim, int kod_greske) {
    FILE *fp = fopen(ime, rezim);
    if (fp == NULL) {
        printf("Greska prilikom otvaranja file-a.");
        exit(kod_greske);
    }

    return fp;
}

void unos_niza_restorana (FILE *ulazni, RESTORAN *restorani, int *pn)  {
    int i = 0;
    while(fscanf(ulazni, "%s %lf %d %d", restorani[i].naziv, &restorani[i].cena_po_osobi, &restorani[i].kapacitet, &restorani[i].broj_konobara) != EOF) {
        i++;
    }
    *pn = i;
}

void ispis (FILE *izlazni, int broj_gostiju, RESTORAN *niz_restorana, int n, double kurs) {
    for (int j = 0; j < n; j++) {
        if (niz_restorana[j].kapacitet < broj_gostiju) {
            fprintf(izlazni, "%s nedovoljno kapaciteta \n", niz_restorana[j].naziv );        
        } else {
            fprintf(izlazni, "%s %lfe %d/%d\n", niz_restorana[j].naziv, broj_gostiju * niz_restorana[j].cena_po_osobi/kurs, broj_gostiju, niz_restorana[j].broj_konobara);
        }

    } 
}


int main (int argc, char **argv ){

    if (argc != 4) {
        printf("Program nije ispravno pokrenut.");
        exit(EXIT_FAILURE);
    }
    
    double kurs = atof(argv[3]);

    int broj_gostiju = atoi(argv[2]);

    RESTORAN niz_restorana[MAX_RESTORANI];
    int n;

    FILE *ulazni = safe_fopen(argv[1], "r", 2);
    unos_niza_restorana(ulazni, niz_restorana, &n);
    fclose(ulazni);

    char naziv_izlazni[26] = "cene_za_";
    strcat(naziv_izlazni, argv[2]);
    strcat(naziv_izlazni, "_gostiju.txt");
    FILE *izlazni_file = safe_fopen(naziv_izlazni, "w", 3);
    ispis(izlazni_file, broj_gostiju, niz_restorana, n, kurs);
    fclose(izlazni_file);

    RESTORAN optimalni_restoran = pronadji_optimalni_restoran(niz_restorana, n, broj_gostiju);
    fprintf( stdout, "Najpogodniji restoran za slavlje je: %s %lfe", optimalni_restoran.naziv, optimalni_restoran.cena_po_osobi*broj_gostiju/kurs );



    return 0;
}