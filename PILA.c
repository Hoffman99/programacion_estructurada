#include<stdio.h>

void push(int pila[10], int *indice);
void pop(int pila[10], int *indice);
void peek(int pila[10], int *indice);
void verificar(int pila[10], int *indice);

int main(){
    int band=0, pila[10], indice=-1;
    while (band==0){
        int eleccion;
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Verificar\n");
        printf("5. Cerrar programa\n");
    scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                push(pila, &indice);
            break;
            case 2:
                pop(pila, &indice);
            break;
            case 3:
                peek(pila, &indice);
            break;
            case 4:
                verificar(pila, &indice);
            break;
            case 5:
                band=1;
            break;
            default:
                printf("El numero no está en la lista");
        }
    }
    return 0;
}

void push(int pila[10], int *indice){
    int respuesta;
    if(*indice==10){
        scanf("La pila está llena");
    }else{
        (*indice)++;
        printf("¿Cuál número deseas agregar?");
        scanf("%d", &respuesta);
        pila[*indice]=respuesta;
    }
}

void pop(int pila[10], int *indice){
    if(*indice==-1){
        scanf("La pila está vacia");
    }else{
        printf("El dato que va a salir es: %d", pila[*indice]);
        (*indice)--;
    }
}

void peek(int pila[10], int *indice){
    printf("El último dato es: %d", pila[*indice]);
}
void verificar(int pila[10], int *indice){
   if (*indice==-1)
   {
    printf("Tu pila está vacia");
   }else{
    for (int i = *indice; i >= 0; i--)
        {
            printf("\nposicion %3d --> %d\n", i, pila[i]);
        }
   }
   
}
