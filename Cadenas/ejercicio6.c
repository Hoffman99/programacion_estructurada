#include <stdio.h>
int main(){
int i=0, n=1;
char cadena[100];
printf("introduce una cadena...... ");
fgets(cadena,100,stdin);
 while(cadena[i] != '\0'){
 if(cadena[i] == ' '){
   if(cadena[i+1] == '\0'){
   n--;
   }else{
     n++;
   }
 }
 i++;
 }
 printf("tu frase cuenta con %d palabras\n",n);
return 0;
}
