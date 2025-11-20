#include <stdio.h>
#include <string.h>

#define MAX 31

int main(){


    char str[MAX];
    printf("unesi recenicu: ");
    fgets(str,MAX,stdin);

    int duzina=strlen(str);
    if(str[duzina - 1] == '\n'){

        str[duzina - 1] = '\0';

    }
for(int i=0;i<strlen(str);i++){
        if(str[i]>='A' && str[i]<='Z'){

           str[i] = str[i] + 32;

        }
    }
    
    int palindrom=1;
    int i=0;
    int j=strlen(str)-1;
    while(i<j){
        if(str[i] == ' '){
            i++;
            continue;
        }
        if(str[j]  == ' '){
            j--;
            continue;
        }
        printf("%c %c\n",str[i], str[j]);
        if(str[i] != str[j]){
            palindrom = 0;
            break;
        }
        i++;
        j--;
    }
    if(palindrom){
        printf("palindrom je");
    }
else{
    printf("nije");
}




    return 0;
}