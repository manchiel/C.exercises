#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 31
#define MAX_EKIPA 30

typedef struct fudbal {

    char naziv[MAX_NAZIV];
    int golrazlika;
    unsigned int bodovi;
} FUDBAL;

FILE *safe_fopen(char *imefajla, char *rezim, int greska);
void ucitajstatistiku(FILE *pulazna, FUDBAL *ekipe, int *pn);
unsigned izracunaj_bodove(unsigned p, unsigned n);
void ispisi_interval(FILE *pizlazna, FUDBAL *ekipe, int n,unsigned bodovi);
double prosek_bodova(FUDBAL *ekipe, int n);
void sortiraj_ekipe(FUDBAL *ekipe, int n);
void ispisi_tabelu(FILE *tabela, FUDBAL *ekipe, int n);

int main(int argc, char **argv){

    int n;
    FILE *pulazna, *pizlazna, *tabela ;

    FUDBAL ekipe[MAX_EKIPA];

    if(argc != 4){
        printf("Primer poziva programa: %s statistika.txt tabela.txt 25\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pulazna = safe_fopen(argv[1] , "r", 2);
    ucitajstatistiku(pulazna,ekipe, &n);
    fclose(pulazna);

    char ime_datoteke[MAX_NAZIV] = "izmedju_proseka_i_";
    strcat(ime_datoteke,argv[3]);
    strcat(ime_datoteke,"_bodova.txt");
    pizlazna = safe_fopen(ime_datoteke, "w", 3);
    unsigned broj_bodova = atoi(argv[3]);
    ispisi_interval(pizlazna, ekipe, n , broj_bodova );
    fclose(pizlazna);


    sortiraj_ekipe(ekipe, n);
    tabela = safe_fopen(argv[2], "w", 3);
    ispisi_tabelu(tabela, ekipe, n);
    fclose(tabela);






    return 0;
}

FILE *safe_fopen(char *imefajla, char *rezim, int greska){
    FILE * fp = fopen(imefajla,rezim);

    if(fp == NULL ){
        printf("datoteku %s nije moguce otvoriti", imefajla);
        exit(greska);

    }
    return fp;
}

void ucitajstatistiku(FILE *pulazna, FUDBAL *ekipe, int *pn){
    int i =0;
    unsigned pobede, porazi, nereseno;
    while(fscanf(pulazna, "%s %d %u %u %u", ekipe[i].naziv, &ekipe[i].golrazlika, &pobede, &nereseno , &porazi)!= EOF){
        ekipe[i].bodovi = izracunaj_bodove(pobede,nereseno);
        i++;
    }
    *pn =i;

}

unsigned izracunaj_bodove(unsigned p, unsigned n){
    
    return  p*3 + n ;
}
void ispisi_interval(FILE *pizlazna, FUDBAL *ekipe, int n,unsigned bodovi){

    double prosek = prosek_bodova(ekipe, n);
    for(int i = 0; i<n ; i++){
        if(ekipe[i].bodovi >= prosek && ekipe[i].bodovi <= bodovi){
            fprintf(pizlazna,"%s %d %u\n", ekipe[i].naziv, ekipe[i].golrazlika, ekipe[i].bodovi);
        }
    }
}

double prosek_bodova(FUDBAL *ekipe, int n){
    double sum=0;
    for(int i = 0 ; i<n; i++){
        sum+=ekipe[i].bodovi;
    }
    return (double) sum/n;
}

void sortiraj_ekipe(FUDBAL *ekipe, int n){
    FUDBAL tmp_ekipa;
    for(int i =0; i<n-1; i++){
        int maxind = i;
        for(int j=i+1; j<n; j++){

            if(ekipe[maxind].bodovi<ekipe[j].bodovi ||( ekipe[maxind].bodovi == ekipe[j].bodovi && ekipe[i].golrazlika < ekipe[j].golrazlika)){
                maxind = j;
            }

         }
         if(maxind != i){
            tmp_ekipa = ekipe[i];
            ekipe[i] = ekipe[maxind];
            ekipe[maxind] = tmp_ekipa;
         }
    }
}

void ispisi_tabelu(FILE *tabela, FUDBAL *ekipe, int n){
    for(int i =0; i<n ; i++ ){
        if( i ==3 || i == 5 || i == n-3){
            fprintf(tabela,"------------------------\n");
        }
        fprintf(tabela,"%s ( BODOVI : %u, GR: %d)\n", ekipe[i].naziv, ekipe[i].bodovi, ekipe[i].golrazlika);
    }
}