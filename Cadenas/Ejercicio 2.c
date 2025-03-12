#include <stdio.h>

int cont_voc(char cad[]);

int main(){
    char cad[100]; 
    printf("Ingresa una cadena de texto: ");
    fgets(cad,100,stdin);
    printf("Se encontraron %3d vocales", cont_voc(cad));
}

int cont_voc(char cad[]){
    int voc=0,i=0;
    while (cad[i]!='\0')
    {
        if (cad[i]=='a' || cad[i]=='A' || cad[i]=='e' || cad[i]=='E' || cad[i]=='i' || cad[i]=='I' || cad[i]=='o' || cad[i]=='O' || cad[i]=='u' || cad[i]=='U')
        {
            voc++;
        }
        i++; 
    }
    return voc;
}