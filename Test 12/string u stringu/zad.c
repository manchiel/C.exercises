#include <stdio.h>
#include <string.h>

#define MAX1 71
#define MAX2 21

int main(){


    char str1[MAX1];
    char str2[MAX2];
    char str12[MAX1+MAX2];
    int n;
    printf("Unesite polazni string: ");
    fgets(str1,MAX1,stdin);
    int duzina1= strlen(str1);
    if(str1[duzina1 -1] == '\n'){
        str1[duzina1-1 ] == '\0';
        duzina1--;
    }
__fpurge(stdin);
    printf("Unesite podstring koji zelite da umetnete: ");
    fgets(str2,MAX2,stdin);

    int duzina2 = strlen(str2);
    if(str2[duzina2 -1] =='\n'){
        str2[duzina2-1] = '\0';
        duzina2--;
    }
    __fpurge(stdin);
    printf("Na koju poziciju zelite da umetnete string : ");
    scanf("%d", &n);
    if(n<1 || n>duzina1){

        printf(" Nije moguce umetnuti string na %d. poziciju.", n);

    }
    else{
        int k=0;
     for(int i=0; i<n; i++){
        str12[k++]=str1[i];
     }
    
     for(int i=0; i<duzina2; i++){
        str12[k++]=str2[i];
    
     }
     for(int i=n+duzina2+1; i<=duzina1+duzina2; i++){
        
        str12[k++]=str1[n++];
     }
     for(int i =0; i<duzina1+duzina2;i++){
        printf("%c", str12[i]);
     }
     




    }


    return 0;
}