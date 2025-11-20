#include <stdio.h>
#include <string.h>
#define MAX 23

int main(){

    char nekom[MAX];
    char kom[MAX];
    printf("unesi string: ");
    fgets(nekom,MAX,stdin);
    int duzina = strlen(nekom);
    if(nekom[duzina -1 ] == '\n'){
        nekom[duzina - 1] = '\0';
        duzina --;
    }
    int k=0;
    int i = 0;
    while(nekom[i]!=' '){
        kom[k++]=nekom[i];
        i++;
    }
    int j =0;
    while(nekom[duzina - j] != ' '){
        kom[] = nekom[duzina - j];
        j++;
    }
    printf("%s",kom  );


return 0;

}