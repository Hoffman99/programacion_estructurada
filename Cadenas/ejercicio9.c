#include <stdio.h>
void mayus(char cad[]);
int main() {
    int i = 0, j = 0, longitud=0, palindromo=1;
    char cadena[100];
    printf("Introduce la palabra: ");
    fgets(cadena, 100, stdin);
    while (cadena[i] != '\0') {
        if (cadena[i] == '\n') {
            cadena[i] = '\0';
            break;
        }
        i++;

    }
    mayus(cadena);
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    for (i = 0, j = longitud - 1; i < j; i++, j--) {
        if (cadena[i] != cadena[j]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo==1) {
        printf("La palabra '%s' es un palindromo.\n", cadena);
    } else {
        printf("La palabra '%s' no es un palindromo.\n", cadena);
    }

    return 0;
}
void mayus(char cad[]){
    int i=0;
    while (cad[i]!='\0')
    {
        if (cad[i]>=97 && cad[i]<=122)
        {
         cad[i]=cad[i]-32;
        }
        i++;
    }
}
