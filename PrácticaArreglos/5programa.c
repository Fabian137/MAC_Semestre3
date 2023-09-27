#include <stdio.h>
#include <stdlib.h>

void escribirMatriz(float matriz[10][10][10], int n, int m, int p);
void imprimirMatriz(float matriz[10][10][10], int n, int m, int p);
float sumaVector(float vector[10], int dimension);

int main(){
    float matrix[10][10], princ[10], secu[10], sumasPricSec;
    /*La suma en cada diagonal? 
    O la suma de ambas diagonales*/

        escribirMatriz(matrix, 3, 4, 2);

        printf("\n");
    
    return 0;
}


float sumaVector(float vector[10], int dimension){
    float sums=0;
    int i, j;
    return sums;
}

void escribirMatriz(float matriz[10][10][10], int n, int m, int p){
    int i,j,k;
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            for (k = 0; k < p; k++){
                printf(" a%d%d: ", i+1, j+1);
                scanf("%f", &matriz[i][j]);
                
            }
            
        }
        printf("\n");
    }
    imprimirMatriz(matriz, n, m, p);
}
void imprimirMatriz(float matriz[10][10][10], int n, int m, int p){
    int i,j, k  ;
    for(i=0; i<n; i++){
        printf("\n|");
        for(j=0; j<m; j++){
            for (k = 0; k < p; k++){
                printf("\t %.2f", matriz[i][j]);
            }
        }
        printf("\t |");
    }
}