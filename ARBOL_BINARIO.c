#include<stdio.h>
#define bin 1024
typedef struct{
    int derecha;
    int izquierda;
    int padre;
    int arbol;
    int nivel;
}binario;

// EL FER COGE CON GORDAS

void buscar(binario arbol[bin], int *indice);
void insertar_valor(binario arbol[bin], int *indice);
int nivel (binario arbol[bin], int indice);
void mostrar(binario arbol[bin]);
void transver(binario arbol[bin], int posicion);

int main(){
    binario arbol[bin];
    int band=0, indice=0;
    while (band==0){
        int eleccion;
        printf("\n1. Insertar un valor\n");
        printf("2. Buscar un valor\n");
        printf("3. Recorrido en orden\n");
        printf("4. Mostrar\n");
        printf("5. Cerrar programa\n");
    scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                insertar_valor(arbol, &indice);
            break;
            case 2:
                buscar(arbol, &indice);
            break;
            case 3:
             //   recorrido();
            break;
            case 4:
                mostrar(arbol);
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

int nivel (binario arbol[bin], int i){
    int nivel_anterior=arbol[i-1].nivel, resultado=1, nivel=1;
    for (int i = 0; i < nivel_anterior; i++) {
        resultado *= 2;
    }
    if (resultado>i+1){
        nivel=nivel_anterior;
    }else{
        nivel=nivel_anterior+1;
    }
    return nivel;
}

int padre(binario arbol[bin], int i){
   int trans=arbol[i].arbol, padre;
    padre=(int)trans/2;
    return padre;
}

void insertar_valor(binario arbol[bin], int *indice){
    int respuesta, i=*indice;
    printf("¿Cuál número deseas agregar al árbol?\n");
    scanf("%d", &respuesta);
    if(*indice==0){
        arbol[*indice].arbol=i+1;
        arbol[*indice].izquierda=respuesta;
        arbol[*indice].nivel=1;
    }else{
        if(*indice%2!=0){
            arbol[*indice].izquierda=respuesta;
        }else{
            arbol[*indice].derecha=respuesta;
        }
        arbol[*indice].arbol=i+1;
        arbol[*indice].nivel=nivel(arbol, i);
        arbol[*indice].padre=padre(arbol, i);
    }
    (*indice)++;
}

void buscar(binario arbol[bin], int *indice){
    int val, posicion=-1;
    printf("\nIngresa el valor a buscar >> ");
    scanf("%d", &val);
    for (int i = 0; i < *indice; i++)
    {
        if (arbol[i].izquierda == val || arbol[i].derecha == val)
        {
            int respues;
            printf("\nEl valor %4d fue encontrado en el nivel %2d\n1--> SALIR\n2-->Recorrido transversal\n---> Cualquier otro para continuar la busqueda\n>>> ", val, arbol[i].nivel);
            scanf("%d", &respues);
            if (respues==1)
            {
                posicion=i;
                break;
            }
            if (respues==2)
            {
                posicion=i;
                transver(arbol,posicion);
                break;
            }
            
        }   
    }
    if (posicion == -1)
    {
        printf("\nEl valor no fue encontrado \n");
    }
} 

void mostrar(binario arbol[bin]){
    for(int i=0;i<9;i++){
        int lado=arbol[i].arbol;
        if (lado==1){
            printf("#%d en el nodo %d, su padre es %d y esta en el nivel %d\n", arbol[i].izquierda, arbol[i].arbol, arbol[i].padre, arbol[i].nivel);
        }else{
            if(i%2==0){
                printf("#%d en el nodo %d, su padre es %d y esta en el nivel %d\n", arbol[i].derecha, arbol[i].arbol, arbol[i].padre, arbol[i].nivel);
            }else{
                printf("#%d en el nodo %d, su padre es %d y esta en el nivel %d\n", arbol[i].izquierda, arbol[i].arbol, arbol[i].padre, arbol[i].nivel);
            }
        }
    }
} 

void transver(binario arbol[bin], int posicion){
    int trans; 
    while (posicion>=0){
        trans = arbol[posicion].padre;
        if((trans%2)==0){
            printf("#%d en el nodo %d, su padre es %d y esta en el nivel %d\n", arbol[posicion].derecha, arbol[posicion].arbol, arbol[posicion].padre, arbol[posicion].nivel);
        }else{
            printf("#%d en el nodo %d, su padre es %d y esta en el nivel %d\n", arbol[posicion].izquierda, arbol[posicion].arbol, arbol[posicion].padre, arbol[posicion].nivel);
        }
        posicion = trans - 1;    /* code */

    }
    }
