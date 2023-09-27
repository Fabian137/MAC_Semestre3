#include <stdio.h>


int main(){
    int i= 0;
    int datoFactorial, resultadoFactorial=1;
    
    printf("***FACTORIAL***\nINGRESA DATO DE FACTORIAL:  ");
    scanf("%d", &datoFactorial);
    for(i=datoFactorial; i>0; i--)
        resultadoFactorial *= i;
    
    printf("El resultado de Factorial es: %d\n", resultadoFactorial);
    return 0;
}