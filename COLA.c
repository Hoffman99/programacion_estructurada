#include<stdio.h>

void encolar(int cola[10], int *final, int *frente);
void verificar(int cola[10], int *final, int *frente);
void desencolar (int cola[10], int *final, int *frente);

int main(){
    int band=0, cola[10], final=-1, frente=0;
    while (band==0){
        int eleccion;
        printf("\n1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Verificar\n");
        printf("4. Cerrar programa\n");
    scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                encolar(cola, &final, &frente);
            break;
            case 2:
                desencolar(cola, &final, &frente);
            break;
            case 3:
                verificar(cola, &final, &frente);
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

void encolar(int cola[10], int *final, int *frente){
    if (*frente==10){
        printf("El arreglo está lleno");
    }else{
        int respuesta;
        printf("¿Cuáñ número deseas agregar?\n");
        scanf("%d", &respuesta);
        if(*frente==0){
            (*final)=0;
        }else{
            
            for(int i=*frente; i>0; i--){
                cola[i]=cola[i-1];
            }
        }
        (*frente)++;
        cola[0]=respuesta;
    }
        
}

void verificar(int cola[10], int *final, int *frente){
    if(*final==-1){
        printf("La estructura está vacia");
    }else{
        for(int i=0;i<*frente;i++){
            printf("%d\n", cola[i]);
        }
    }
}

void desencolar (int cola[10], int *final, int *frente){
    if(*final==-1){
        printf("La estructura está vacia");
    }else{
        int i=*frente;
        printf("El valo que vas a eliminar es el: %d", cola[i-1]);
        if(*frente==0){
            (*final)=-1;
        }else{
            (*frente)--;
        }
    }
}
