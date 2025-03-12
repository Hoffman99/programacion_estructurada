#include <stdio.h>

void remplazar(char cadena[], char caracter, char cambio);

int main(){
    char cadena[200];
    char caracter, cambio;
    printf("Ingrese una cadena\n");//Solicita al usuario la cadena
    fgets(cadena, 200, stdin);
    printf ("Esta es su cadena %s\n", cadena);
    printf("Ingrese el caracter a eliminar:\n");//Solicita al usuario un caracter que desee eliminar de la cadena
    scanf("%c", &caracter);
    getchar();
    printf("Ingrese el caracter por el que lo va a cambiar:\n");//Solicita al usuario un caracter por el que desea cambiar el caracter eliminado
    scanf("%c", &cambio);
    getchar();
    remplazar(cadena, caracter, cambio);
    printf("Esta es su cadena modificada:\n%s\n", cadena);
    return 0;
}

void remplazar(char cadena[], char caracter, char cambio){
    int i=0;
    while(cadena[i]!=0){//Si encuentra alguno de los caracteres que desea elimar lo cambia por el que se desea cambiar
        if(cadena[i]==caracter){
            cadena[i]=cambio;
        }
    i++;
    }
}
