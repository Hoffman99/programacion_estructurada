#include <stdio.h>

void mayus(char cad[]);

int main(){
    char cad[200];
    printf("Ingresa el texto --> ");
    fgets(cad,200,stdin);
    mayus(cad);
    return 0;
}

void mayus(char cad[]){
    int i=0;
    while (cad[i]!='\0')
    {
        if (cad[i]>=97 && cad[i]<=122)
        {
            printf("%c", cad[i]-32);
        }
        else
        {
            printf("%c", cad[i]);
        }
        i++;
    }
}