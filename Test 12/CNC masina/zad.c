#include <stdio.h>
#include <math.h>
#define MAX 30 

int main(){


    double x[MAX],y[MAX];
    int n;

    do{

        printf("Unesi broj kordinata: ");
        scanf("%d", &n);

    }while( n < 1 || n > MAX);

    for(int i = 0;i<n;i++){
        printf("%d. tacka \n x[%d] = ",i+1, i);
        scanf("%lf" , &x[i]);
        printf(" y[%d] = ",i);
        scanf("%lf", &y[i]);
    }
    printf("\n\n [");
    printf("(%.2lf,%.2lf)" , x[0], y[0]);
    for(int i = 1; i < n; i++){

        printf(" , (%.2lf,%.2lf)", x[i], y[i]);

    }
    printf("\n");
    double d = 0;
    for(int i=0; i<n-1; i++){
        d= d + sqrt(pow(x[i]-x[i+1],2) + pow(y[i]-y[i+1],2) );
    }
    printf(" ukupna duzina svih rastojanja: %.2lf", d);

    return 0;
}