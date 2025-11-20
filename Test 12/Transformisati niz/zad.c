#include <stdio.h>

#define MAX 30

int main(){

    unsigned int A[MAX];
    unsigned int B[MAX];
    int k = 0;
    int n;
    do{
        printf("unesi broj elemenata niza: \n");
        scanf("%d", &n);
    }while(n<=1 || n>MAX);

    for(int i=0; i<n ; i++){

        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
     }
    
    for(int i=0;i<n-1;i++){
        
        for(int j=i+1;j<n;j++){
            
            if(A[i]==A[j]){

                    n--;
                for(int k = j;k<n;k++){

                    A[k]=A[k+1];
                }
                    j--;
                }
            
            
            
            
        }
    }

    for(int i=0; i<n;i++){

        printf("%d", A[i]);
    }

               
                

            

        


     




    return 0;
}