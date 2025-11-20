#include <stdio.h>

#define MAX 30

int main(){

    int niz[MAX];
    int n;
    int pom;
    do{
        printf("unesi broj elemenata niza: \n");
        scanf("%d", &n);
    }while(n<1 || n > MAX);
    // UVEK UNESI N PREKO DO WHILE DA BI PROVERIO
    for(int i=0;i<n;i++){
        printf("unesi %d. clan: \n ", i);
        scanf("%d", &niz[i]);
    }
    for(int i =0; i<n/2;i++){
        // ovde je do n/2 jer da ide do n opet bi vratio u prvobitan redosled !!!
        pom = niz[i];
        niz[i]=niz[n-1-i];
        niz[n-1-i]=pom; 

    }
    printf(" obrnuti redosled je : [ ");
    for(int i=0; i<n;i++){

        printf("%d ", niz[i]);
    }
    printf(" ]");






        return 0;
}