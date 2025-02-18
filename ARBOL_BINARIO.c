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

int nivel (binario arbol[bin], int i){
    int nivel_anterior=arbol[i-1].nivel, resultado=1, nivel=0;
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
`   int nodo=arbol[*indice].arbol, padre;
    padre=(int)nodo/2;
    return padre;
}

void insertar_valor(binario arbol[bin], int *indice){
    int respuesta, i=*indice;
    printf("¿Cuál número deseas agregar al árbol?/n");
    scanf("%d", &respuesta);
    if(*indice==0){
        arbol[*indice].arbol=i+1;
        arbol[*indice].izquierda=respuesta
        arbol[*indice].nivel=0;
    }else{
        if(*indice%2!=0){
            arbol[*indice].izquierda=respuesta;
        }else{
            arbol[*indice].derecha=respuesta;
        }
        arbol[*indice].arbol=i+1;
        arbol[*indice].nivel=nivel(arbol, i);
        arbol[*indice].padre=padre(arbol, i);
        (*indice)++;
    }

}

void buscar(binario arbol[bin], int *indice){
    int val, i = 0, band_encontrar = 0,band_valor=0 , posicion;;
    printf("\nIngresa el valor a buscar >> ");
    scanf("%d", &val);

    while (i <= *indice) //recorrido de todos los hijos izquierdos
    {   
        while (band_valor=0)
        {
            if (arbol[i].izquierda==val)
            {
                int respu;
                printf("\nEl valor %4d fue encontrado en el nivel %2d", val, arbol[i].nivel);
                band_encontrar=1;
                printf("\nDeseas quedarte con este valor o seguir buscando \n1 --> quedarse con el valor y salir \n2 --> continuar la busqueda del lado izquierdo");
                scanf("%d", &respu);
                if (respu==1)
                {
                    posicion=i;
                    i=*indice+1;
                }   
            }
        }               
    i++;
    }
    int respues,o;
    printf("\nDeseas continuar la busqueda del lado derecho o finalizar\n 1. Continuar\n2. Terminar");
    scanf("%d", respues);
    if (respues==1)
    {
        
        while (o <= *indice) //recorrido de todos los hijos derechos
        {                           
         if (arbol[o].derecha==val)
         {
            int respu;
            printf("\nEl valor %4d fue encontrado en el nivel %2d", val, arbol[o].nivel);
            band_encontrar=1;
            printf("\nDeseas quedarte con este valor o seguir buscando \n1 --> quedarse \n2 --> terminar la busqueda");
            scanf("%d", &respu);
            if (respu==1)
            {
                posicion=o;
                o=*indice+1;
            }
        }
         o++;
        }
    }
    
    if (band_encontrar==0) //si el valor nunca fue encontrado, la bandera nunca habra cambiado de valor, por lo tanto se imprime el siguiente mensaje
    {
        printf("\nEl valor no se encontró dentro del árbol\n");
    }
}  
