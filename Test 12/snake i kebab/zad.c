#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define MAX 31

int main(){


char str[MAX];

printf("Uneti string: ");
fgets(str,MAX,stdin);
int duzina=strlen(str);
if(str[duzina - 1] == '\n'){
    str[duzina-1 ] == '\0';
    duzina --;
}

printf("izaberi notaciju: ");
char c;
scanf("%c", &c);
switch(c){
    case '-' :
        for(int i =0; i<duzina;i++){
            if(str[i] == ' '){
                str[i]='-';
            }
        }
         break;
    
    case '_' :
        for(int i =0; i<duzina;i++){
            if(str[i] == ' '){
                str[i]='_';
            }
        }
        break;
    

    default:
        printf("nisi uneo jednu od notacija...");
    

}
int dobar = 1;
for(int i=0; i<duzina; i++){
    if((str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && (str[i]!='-') && (str[i]!='_')){
        dobar = 0;
    }
}
if(dobar){
    printf("%s", str);
}
else{
    printf(" greskaa");
}

return 0;

}