#include <stdio.h>

int main(){
    int i, control=0;
    float numero; 
    
printf("\n\nDame el numero que deseas descomponer: \n");
scanf("%f", &numero);

if(numero !=0 ){

while(numero>1){

    numero = numero/10; 
    control++;
}

printf("\nEL numero total de digitos es: %d", control);

}else{
    printf("\nEl numero total de digitos es: 1 "); 

}

    return 0; 
}