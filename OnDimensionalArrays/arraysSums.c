#include <stdio.h>

void SumaArrays(float a[], float b[], int leng){
    int i;
    float c[leng];

    printf("\nArreglo resultante al sumar\n");
    for (i = 0; i < leng; i++){
        c[i] = a[i] + b[i];
        printf("\n %dª:%.2f", i, c[i]);
    }
}

int main(){
	double resultado;
	int n, i, leng = 3;
    float array1[leng], array2[leng];    

	printf("\n\nIngrese los elementos del primer arrreglo\n ");
    for (i = 0; i < leng; i++){
	    printf("%dº: ", i);
	    scanf("%f", &array1[i]);
    }
    
	printf("\n\nIngrese los elementos del segundo arrreglo \n");
    for (i = 0; i < leng; i++){
	    printf("%dº: ", i);
	    scanf("%f", &array2[i]);
    }

    SumaArrays(array1, array2, leng);
    printf("\n");
    return 0;
}