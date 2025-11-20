#include <stdio.h>

#include <math.h>

#define MAX 15

int zbir(int i){

        int prvacif= i/10;
        int drugacif= i%10;
        return pow(prvacif,2)+pow(drugacif,2);
    }


int main(){

    int n;
    int niz[MAX];

    do{
        printf("unesi broj clanova niza");
        scanf("%d" , &n);
    }while(n<1 || n>MAX);

    for(int i=0;i<n;i++){

        printf("A[%d] = ", i);
        scanf("%d", &niz[i]);
        if(niz[i]<10 || niz[i]>99){
            printf("Broj mora biti prirodan i dvocifren\n");
            i--;
        }

    }

    int zbirovi[MAX];//ili [n] ???
    printf("\n\n");
    for(int i=0; i<n; i++){

        zbirovi[i]=zbir(niz[i]);
        printf("Zbir(A[%d]) = %d\n", i, zbirovi[i]);

    }
printf("\n\n");
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){

                if(zbirovi[i] == zbirovi[j]){
                    printf(" zbir(A[%d] = zbir(A[%d]) = %d\n", i, j, zbirovi[i]);
                }
        }

    }

    

    return 0;
}