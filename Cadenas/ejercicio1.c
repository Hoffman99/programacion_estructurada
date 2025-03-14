#include <stdio.h>
int main(){
int i=0, n=0;
char cadena[100];
printf("introduce la cadena..... ");
scanf("%s", &cadena);
 while(cadena[i] != '\0'){
   n++;
   i++;
 }
 printf("tu cadena tiene una longitud de %d bytes \n",n);
return 0;
}
