#include<stdio.h>

double potencia(int base, int exponente){
	double res= 0;

    if (exponente == 0){
        return 1;
    }

    res = base * potencia(base, exponente -1);
    
	return res;
}

double factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }    
    
}

int fibonacci(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }    

}

int main(){
	double resultado;
	int fibo, opc, numero, base, exponente;

	printf("\n\nEliga la opción que desea probar ");
	printf("\n1) Factorial con recursividad ");
	printf("\n2) Fibonacci con recursividad ");
	printf("\n3) Potencia con recursividad ");
	printf("\nOpcion ");
	scanf("%d", &opc);

    switch (opc){
        case 1: //Factorial
            resultado = factorial(13);
            printf("\nDato de prueba n=13, factorial: %.1f\n", resultado);
            printf("\nIngresa el número del que quieres saber su factorial: ");
	        scanf("%d", &numero);
            resultado = factorial(numero);
            printf("\nFactorial de %d = %.1f\n", numero, resultado);

        break;
        case 2: //Fibonacci
            fibo = fibonacci(8);
            printf("\nDato de prueba n=8, fibonacci: %d\n", fibo);
            printf("\nIngresa la cantidad de terminos de la serie: ");
	        scanf("%d", &numero);
            fibo = fibonacci(numero);
            printf("\n Resultado de %d terminos: %d\n", numero, fibo);
        
        break;
        case 3: //Potencia
            resultado = potencia(3, 7);
            printf("\nDato de prueba base = 3, exponente = 7, fibonacci: %.1f\n", resultado);
            printf("\nIngresa la base: ");
	        scanf("%d", &base);
            printf("\nIngresa el exponente: ");
	        scanf("%d", &exponente);
            resultado = potencia(base, exponente);
            printf("\n %d ^ %d = %.1f\n", base, exponente, resultado);
        
        break;
    
        default:
	        printf("\nOpcion incorrecta");
        break;
    }

    return 0;
	

}