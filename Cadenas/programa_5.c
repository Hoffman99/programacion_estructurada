#include <stdio.h>

int tamanio(char cadena[]);
void espacio(char cadena[], int tam);

int main(){
    char cadena[200];
    int tam;
    printf("Ingrese una cadena\n");//Solicita al usuario cadena
    fgets(cadena, 200, stdin);
    printf ("Esta es su cadena %s\n", cadena);
    tam=tamanio(cadena);
    espacio(cadena, tam);
    printf("Esta es tu cadena sin espacios:\n%s", cadena);//Imprime la cadena sin los espacios
    return 0;
}

int tamanio(char cadena[]){//Se calcula el tamaño de la cadena
    int tam=0;
    while(cadena[tam]!=0){//Recorre la cadena hasta encontrar ´\0´
        tam++;
    }
    return tam;
}

void espacio(char cadena[], int tam){
    int i, y;
    for(i=0; i<tam; i++){
        if (cadena[i]==' '){//Si en la cadena encuentra un espacio, recorre todos los elementos uno a la izquierda
            for(y=i; y<tam-1; y++){
                cadena[y]=cadena[y+1];
            }
            tam--;
        }
    }
}