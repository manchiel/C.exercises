#include <stdio.h>

#define MAX 50
int main(){

    int X[MAX];
    int A[MAX];
    int B[MAX/2];
    int n;
    do{
        printf("unesi broj elemenata pocetnog niza: \n");
        scanf("%d", &n);
    }while(n<=1 || n> MAX);
    int j=0;
    int k=0;
    for(int i=0; i<n; i++){
        printf("X[%d]= \n", i);
        scanf(" %d", &X[i]);
        
    }
    for(int i=0; i<n; i++){
        if(X[i]%2==0){
            A[j]=X[i];
            j++;
            
        }
        if(i%2 != 0){
            B[k]=X[i];
            k++;
        }
        
    }
    int sum=0;
    for(int i=0; i<=j; i++){
            sum+=A[i];
        }
    double srva = (double)sum/j;
printf(" A = [ ");
    for(int i=0; i<j; i++){
            printf("%d ", A[i]);
        }
        printf("]\n");
        printf(" B = [ ");
    for(int i=0; i<k; i++){
            printf("%d ", B[i]);
        }
        printf("]\n");
        printf(" srednje vrednos niza A je: %f", srva);
    
  





    return 0;
}