#include <stdio.h>

#define MAX 30

int main(){

    double niz[MAX];
    int n;
    double m;

    do{

        printf("unesite broj visina");
        scanf("%d", &n);
    }while(n < 1 || n > MAX);

    for(int i=0; i<n, i++){

        printf("h[%d] = ", i);
        scanf("%lf", &niz[i]);     
        
        
                            // POTPUNO NEJASNO DEFINISAN ZADATAK






    }
    do{
        printf("unesi masu tela [kg]: ");
        scanf("%lf", &m);
    }while(m<0);

    double euk=0;
    const double g= 9.81;

    for(int i=0; i<n;i++){

        euk+=m*g*niz[i];
    }
    printf(" Ukupna energija je %.2lfJ", euk);











    return 0;
}