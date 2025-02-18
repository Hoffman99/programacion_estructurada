#include<stdio.h>
#define bin 1024
typedef struct{
    int derecha;
    int izquierda;
    int padre;
    int arbol;
    int nivel;
}binario;

void buscar(binario arbol[bin], int *indice);
void insertar_valor(binario arbol[bin], int *indice);
int nivel (binario arbol[bin], int indice);

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

void buscar(binario arbol[bin], int *indice){
    int val, i = 0, band = 0;
    printf("\nIngresa el valor a buscar >> ");
    scanf("%d", &val);

    while (i <= *indice)        //entramos al ciclo while para buscar nuestro valor en el arbol de izquierda a derecha,
    {                           // comenzando desde el nodo raiz hasta llegar a los hijos
        if (arbol[i] == val)
        {
            int pote = 1;       // una vez encontrado el valor debemos saber en que nivel del arbol esta, por lo que
            int nivel = 0;      // a traves de las potencias sabremos, cuando la potencia sea mayor a igual que nues-
            while (pote <= i)   //tro indice "i" es porque en ese nivel se encuentra el valor
            {
                pote = pote * 2;  // Calculamos el nivel usando potencias de 2 y aumentando el nivel cada ves
                nivel++;          // que aumentamos una potencia
            }

            printf("\nEl valor %d fue encontrado en el nivel %d\n", val, nivel);
            band = 1;
        }
        i++;
    }
                                //en caso de no encontrar el valor y por lo tanto no haber modificado la bandera
    if (band == 0)              // el programa nos dira que no se logro encontrar el valor
    {
        printf("\nEl valor no se encontró dentro del árbol\n");
    }   
}   
