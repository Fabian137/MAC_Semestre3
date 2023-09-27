#include <stdio.h>
#include <stdlib.h>

void escribirMatriz(float matriz[10][10], int n, int m);
void imprimirMatriz(float matriz[10][10], int n, int m);
void vectorPrincSecu(float a[10][10], float pr[10], float sec[10], int dimension);
float sumaVector(float vector[10], int dimension);

int main(){
    int dimension;

    float matrix[10][10], princ[10], secu[10], sumasPricSec;
    /*La suma en cada diagonal? 
    O la suma de ambas diagonales*/

    printf("\n Ingrese la dimensión de la matriz (solo un numero): ");
    scanf("%d", &dimension);
    if (dimension>10){
        system("exit");
    }
    else{
        princ[dimension];
        secu[dimension];
        
        escribirMatriz(matrix, dimension, dimension);

        printf("\n");
        vectorPrincSecu(matrix, princ, secu, dimension);
        printf("\n");

        sumasPricSec = sumaVector(princ, dimension);
        printf("\n\n -- La suma de la diagonal principal resulta: %.2f\n", sumasPricSec);
        
        sumasPricSec = sumaVector(secu, dimension);
        printf("\n\n -- La suma de la diagonal secundaria resulta: %.2f\n", sumasPricSec);

    }
    return 0;
}

void vectorPrincSecu(float a[10][10], float pr[10], float sec[10], int dimension){
    int i, j;
    float suma;
    for ( i = 0; i < dimension; i++){
        for (j = 0; j < dimension; j++){
            if (i==j){
                pr[i] = a[i][j];
                if (i+j == (dimension-1)){
                    sec[i] = a[i][j];
                }
            }
            else if (i+j == (dimension-1)){
                /* Segun el análisis debería de ser dimension + 1, pero al inicializar en 0 los for, cambia la condición*/
                sec[i] = a[i][j];
            }
        }
    }
}

float sumaVector(float vector[10], int dimension){
    float sums=0;
    int i;
    for( i = 0; i < dimension; i++){
        printf("\t %.2f", vector[i]);
        sums += vector[i];
    }
    return sums;
}

void escribirMatriz(float matriz[10][10], int n, int m){
    int i,j;
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf(" a%d%d: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
        printf("\n");
    }
    imprimirMatriz(matriz, n, m);
}
void imprimirMatriz(float matriz[10][10], int n, int m){
    int i,j;
    for(i=0; i<n; i++){
        printf("\n|");
        for(j=0; j<m; j++){
            printf("\t %.2f", matriz[i][j]);
        }
         printf("\t |");
    }
}