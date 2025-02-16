#include <stdio.h>

typedef struct {
    int apuntador;
    int numero;
}elemento;

void insertar(elemento lista[20], int *indice, int *indicef);
void insertar_final(elemento lista[20], int *indicef, int *indice);
void eliminar(elemento lista[20], int *indice, int *indicef);
void buscar(elemento lista[20], int *indice, int *indicef);
void mostrarlista(elemento lista[20], int *indice, int *indicef);

int main(){
    elemento lista[20];
    int indice=9, indicef=9, band=0;
    while (band==0){
        int eleccion;
        printf("\n1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Eliminar un valor\n");
        printf("4. Buscar un valor\n");
        printf("5. Mostrar lista\n");
        printf("6. Cerrar programa\n");
        scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                insertar(lista, &indice, &indicef);
            break;
            case 2:
                insertar_final(lista, &indicef, &indice);
            break;
            case 3:
                eliminar(lista, &indice, &indicef);
            break;
            case 4:
                buscar(lista, &indice, &indicef);
            break;
            case 5:
                mostrarlista(lista, &indice, &indicef);
            break;
            case 6:
                band=1;
            break;
            default:
                printf("Valor invalido");


        }
    }
}

void mostrarlista(elemento lista[20], int *indice, int *indicef){
    if(*indice==9 && *indicef==9){
        printf("La lista está vacia");
    }else{
        int i=*indice, final=*indicef;
        while (i<final-1)
        {
            if(lista[i+1].numero>=0){
                printf("# %d en la posición %d\n", lista[i+1].numero, i+1);
            }
            i=lista[i+1].apuntador;
        }
        
    }
}

void insertar(elemento lista[20], int *indice, int *indicef){
    if (*indice==-1){
        printf("La lista está llena");
    }else{
        printf("¿Cuál número deseas agregar?\n");
        int respuesta;
        scanf("%d", &respuesta);
        if(*indice==9){
            lista[9].numero=respuesta;
            lista[9].apuntador=*indicef;
            (*indicef)++;
        }else{
            int direccion=*indice;
            lista[*indice].numero=respuesta;
            lista[*indice].apuntador=direccion;
        }
        (*indice)--;
    }
}

void insertar_final(elemento lista[20], int *indicef, int *indice){
    if (*indicef==21){
        printf("La lista está llena");
    }else{
        printf("¿Cuál número deseas agregar?\n");
        int respuesta;
        scanf("%d", &respuesta);
        if(*indicef==9){
            lista[9].numero=respuesta;
            lista[9].apuntador=*indicef;
            (*indice)--;
        }else{
            int direccion=*indicef;
            lista[*indicef].numero=respuesta;
            lista[*indicef].apuntador=direccion;
            lista[direccion-1].apuntador=direccion-1;
        }
        (*indicef)++;
    }
}

void eliminar(elemento lista[20], int *indice, int *indicef){
    int respuesta;
    printf("¿Cuál dato deseas eliminar?\n");
    scanf("%d", &respuesta);
    if(respuesta>*indice && respuesta<*indicef){
        if(lista[respuesta].apuntador==-1){
            printf("El número ya fue eliminado\n");
        }else{
            lista[respuesta].numero=-1;
        }
    }else{
        printf("El número no está en la lista\n");
    }
}

void buscar(elemento lista[20], int *indice, int *indicef){
    int respuesta;
    printf("¿Cuál número que deseas buscar?\n");
    scanf("%d", &respuesta);
    int i=*indice, final=*indicef,band=0;
        while (i<final-1&&band==0)
        {
            if(lista[i+1].numero==respuesta){
                lista[i+1].numero=-1;
                band=-1;
                printf("Tu número está en la posición %d\n", lista[i+1].apuntador);
            }
            i=lista[i+1].apuntador;
        }
    if(band==0){
        printf("Tu número no está en la lista\n");
    }
}