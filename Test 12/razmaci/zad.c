#include <stdio.h>
#include <string.h>

#define MAX 101

int main(){


    char str1[MAX];
    char str2[MAX];
    int br=0;

    printf(" Unesi string: ");
    fgets(str1,MAX,stdin);
    if(str1[strlen(str1) - 1] == '\n'){
        str1[strlen(str1) - 1] == '\0';
    }
    __fpurge(stdin);

printf(" uneti string : \n");
printf(" '");
for(int i=0;i<strlen(str1);i++){

    printf("%c", str1[i]);

}
printf("'");
printf("\n\n");
int j=0;
while(str1[j] == ' '){
    int duzina=strlen(str1) -1;
    for(int i=0;i<duzina;i++){
        str1[i]=str1[i+1];
    }
    j++;
    br++;
}
int k=str1[strlen(str1) - 1];
while(str1[k] == ' '){
    int duzina=strlen(str1) -1;
    for(int i = duzina; i>=0; i--){
        str1[i]=str1[i-1];
    }
    k--;
    br++;
}
printf("String sa izbacenim razmacima: \n");
printf(" '");
for(int i=0;i<strlen(str1);i++){
    printf("%c", str1[i]);
}
printf("'");


    return 0;
}