#include <stdio.h>

int main(){
    int filas = 4, colums = 3;
    int array[filas][colums],i, j, sums=0;

    printf("\n");
    //Como se ve la matriz general
    for(i=0; i<filas; i++){
        for (j = 0; j < colums; j++){
            printf(" a%d%d ", i+1, j+1);
        }
        printf("\n");
    }

    // Lectura de la matriz
    printf("\n");
    for(i=0; i<filas; i++){
        for (j = 0; j < colums; j++){
            printf("Ingresa el elemento a%d%d: ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    // Escritura de la matriz 
    // Y suma de los renglones
    for (i=0; i<filas; i++){
        for (j = 0; j < colums; j++){
            printf("%d \t ", array[i][j]);
            sums += array[i][j];
        }
        printf("\t :: %d", sums);
        sums = 0;
        printf("\n");
    }
    
    return 0;
}