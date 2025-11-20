#include <stdio.h>

#define MAX 30

int main(){

int X[MAX];
int n;

do{
    printf("unesi broj elemenata niza \n");
    scanf("%d", &n);
    
    
}while(n<=1 || n>MAX);

    int sum=0;

    for(int i=0; i<n; i++){

        printf("X[%d] = ", i);
        scanf("%d", &X[i]);

        sum+=X[i];

    }

    double srv =(double) sum/n;

    int brojac = 0;

    for(int i=0; i<n; i++){
        if(X[i]>srv){

            brojac++;
        }
    }
    printf("Clanovi niza X = [");
    for(int i=0; i<n; i++){

        printf("%d ", X[i]);

    }
    printf("]\n ");
    printf("Srednja vrednost je %.2f \n", srv);
    printf("Broj elemenata vece od srednje vrednost je %d \n",brojac);

    return 0;
}