#include <stdio.h>
#include <math.h>

#define MAX 20

int main(){

double R[MAX];
int n;

do{
    printf("unesi broj elemenata niza \n");
    scanf("%d", &n);
    
    
}while(n<=1 || n>MAX);


    for(int i=0; i<n; i++){

        printf("R[%d] = ", i);
        scanf("%lf", &R[i]);
        if(R[i]<=0){
            printf("Nisi uneo pozitivan\n");
            i--;
        }

    }
    double U;
    printf("Unesite jacinu napona u voltima: ");
    scanf("%lf", &U);
    double sum=0;
    for(int i=0; i<n; i++ ){

        sum+= 1/R[i];

    }
double I = U * sum;
printf(" Ukupna struja: %.2fA\n", I);

double i1 = U / R[0];

double procenat = i1 / (I/100);

printf("Procentualni udeo struje: %.2lf%%\n", procenat);
printf("[ ");
for(int i=0; i<n; i++){

    double k = pow(U,2)/R[i];
    printf("%.2fW ", k);

}
printf("]");


return 0;

}

