#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX_STRING 31
int main () {

    char string[MAX_STRING], karakter;
    int duzina_stringa, brojac = 0;
    printf("Unesite string");
    fgets (string, MAX_STRING, stdin);
    duzina_stringa = strlen(string);
    if (string[duzina_stringa - 1] == '\n') {
        string[duzina_stringa -1] = '\0';
        duzina_stringa--;
    }
    __fpurge(stdin);

    printf("Unesi karakter koji zelis a izbacis iz stringa: ");
    scanf("%c", &karakter);

    for (int i = 0; i < duzina_stringa; i++) {
        if (string[i] == karakter) {
            brojac++;
            duzina_stringa--;
            for(int j=i; j < duzina_stringa; j++) {
                string[j] = string[j+1];

            }
        }
    }
    string[duzina_stringa] = '\0';

    for (int i = 0; i < duzina_stringa; i++) {
        char temp = string[i];
        string[i] = string[i+1];
        string[i+1] = temp;
        i++;
    }

    printf("String nakon modifikacija je %s", string);
    return 0;
}
