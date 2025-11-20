#include <stdio.h>
#include <string.h>

#define MAX 100

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
    for(int i=0;i<duzina;i++){
        if(nekom[i]==nekom[i+1]){
            int j=i+1;
            int br=1;
            while(nekom[j] == nekom[i]){
                br++;
                j++;
            }
            int desetice = br/10;
            int jedinice = br%10;
            if(desetice>0){
                kom[k++]=desetice + '0';
                kom[k++]=jedinice + '0';
                kom[k++]=nekom[i+1];
                i = i+br-1;

            }
            else{

            kom[k++]=jedinice + '0';
            kom[k++]=nekom[i+1];
            i = i+br-1;
            }
        }
        else{
            kom[k++]=nekom[i];
        }
    }
    puts(kom);
    double kompresija = (1 - ((double)strlen(kom)/strlen(nekom)))*100;
    printf(" Procenat kompresije: %.2lf %%", kompresija);









    return 0;
}