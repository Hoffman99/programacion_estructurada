#include<stdio.h>
#define bin 1024
typedef struct{
    int derecha;
    int izquierda;
    int padre;
    int arbol;
    int nivel;
}binario;

int main(){
    binario arbol[bin];
    int band=0, indice=0;
    while (band==0){
        int eleccion;
        printf("\n1. Insertar un valor\n");
        printf("2. Buscar un valor\n");
        printf("3. Recorrido en orden\n");
        printf("4. Cerrar programa\n");
    scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                insertar_valor(arbol, &indice);
            break;
            case 2:
                buscar();
            break;
            case 3:
                recorrido();
            break;
            case 4:
                band=1;
            break;
            default:
                printf("El numero no está en la lista");
        }
    }
    return 0;
}

int nivel (binario arbol[bin], int indice){
    int nivel_anterior=arbol[indice-1].nivel, resultado=1, nivel=0;
    for (int i = 0; i < nivel_anterior; i++) {
        resultado *= 2;
    }
    if (resultado>indice){
        nivel=nivel_anterior;
    }else{
        
    }


}

void insertar_valor(binario arbol[bin], int *indice){
    int respuesta;
    printf("¿Cuál número deseas agregar al árbol?/n");
    scanf("%d", &respuesta);
    if(*indice==0){
        arbol[*indice].arbol=respuesta;
        arbol[*indice].nivel=0;
        (*indice)++;
    }else{
        if(*indice%2==0){
            arbol[*indice].arbol=respuesta;
            arbol[*indice].izquierda=respuesta;
            arbol[*indice].nivel=nivel(arbol, indice);
        }
    }

}

int recorrido(binario arbol[bin], int indice){
    
