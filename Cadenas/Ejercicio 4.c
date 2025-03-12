#include <stdio.h>

int tam(char cad[]);
void invertir(char cad[]);

int main(){
    char cad[200];
    printf("ingresa la cadena -->");
    fgets(cad,200,stdin);
    invertir(cad);
    return 0;
}

int tam(char cad[]){
    int i=0;
    while (cad[i]!='\0')
    {
        i++;
    }
    return i;
}

void invertir(char cad[]){
    for ( int i = tam(cad); i >= 0; i--)
    {
        printf("%c", cad[i]);
    }
}