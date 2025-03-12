#include <stdio.h>

void root(char cadena[]);

int main(){
    char cadena[200];
    printf("Ingrese la cadena\n");//Solicita cadena al usuario
    fgets(cadena, 200, stdin);
    root(cadena);
    printf("Esta es tu cadena en ROOT13:\n%s\n", cadena);
    return 0;
}

void root(char cadena[]){
    int ascii, i=0;
    while(cadena[i]!=0){
        ascii=cadena[i];
        if (ascii>=65 && ascii<=90){//ASCII Mayusculas
            ascii+=13;
            if(ascii>90){
                ascii-=26;
            }
        }
        if(ascii>=97 && ascii<=122){//ASCII Minusculas
            ascii+=13;
            if(ascii>122){
                ascii-=26;
            }
        }
        cadena[i]=ascii;
        i++;
    }
}