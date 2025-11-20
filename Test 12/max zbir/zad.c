#include <stdio.h>

#define MAX 15

int main(){

int niz[MAX];
int n;
do{

    printf("unesi broj elemenata niza :");
    scanf("%d", &n);

}while(n<=1 || n> MAX);

for(int i=0; i<n; i++){

    printf("Niz[%d]= ", i);
    scanf("%d", &niz[i]);
    
    }
int najveci=niz[0], druginajveci=niz[0];
int index_najveceg;
for(int i=1; i<n;i++){

    if(niz[i]>najveci){
        najveci = niz[i];
        index_najveceg=i;

    }
}
for(int i=1;i<n;i++){
    if(niz[i]>druginajveci && i!=index_najveceg ){
        druginajveci=niz[i];
    }
}
int zbir=najveci+druginajveci;
printf(" Maksimalni zbir je %d", zbir);



    return 0;
}