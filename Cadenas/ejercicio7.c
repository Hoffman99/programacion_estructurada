#include <stdio.h>
int main(){
  int i=0, j=0;
  char cadena[100];
  char subcadena[100];
  printf("introduce la cadena.... ");
  fgets(cadena,100,stdin);
 while (cadena[i] != '\0') {
        if (cadena[i] == '\n') {
            cadena[i] = '\0';
            break;
        }
        i++;
    }
  printf("Introduce la subcadena: ");
    fgets(subcadena, 100, stdin);
    i = 0;
    while (subcadena[i] != '\0') {
        if (subcadena[i] == '\n') {
            subcadena[i] = '\0';
            break;
        }
        i++;
    }
    i=0;
  while((subcadena[j]!='\0') && (cadena[i]!='\0')){
      if(cadena[i]==subcadena[j]) {
        j++;
  }else{
        j=0;
      }
      i++;
  }
  if(subcadena[j]=='\0'){
    printf("Se encontro la subcadena %s en la cadena %s \n",subcadena,cadena);
  }else {
    printf("No se encontro tu subcadena en tu cadena");
  }
return 0;
}
