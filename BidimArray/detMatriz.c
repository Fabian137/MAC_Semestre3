#include <stdio.h>
#include <stdlib.h>

void escribirMatriz(int matriz[3][3], int n);
int determinante(int a[3][3]);

int main(){
    int i, j, matriz[3][3], det;

    escribirMatriz(matriz, 3);

    det = determinante(matriz);
    printf("\nEl determinante de la matriz dada es: %d\n", det);
    return 0;
}

// Ya que la matriz está definida como de 3x3 puedo una "formula" que se cumple para matrices de 3x3
int determinante(int a[3][3]){
    int i, j, det=0;

    det = (a[0][0]*a[1][1]*a[2][2]) + (a[0][1]*a[1][2]*a[2][0]) + (a[0][2]*a[1][0]*a[2][1]);
    det += -(a[0][2]*a[1][1]*a[2][0]) - (a[0][0]*a[1][2]*a[2][1]) - (a[0][1]*a[1][0]*a[2][2]);

    return det;
}

void escribirMatriz(int matriz[3][3], int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf(" a%d%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    //Imprimo la matriz escrita
    for(i=0; i<n; i++){
        printf("\n |");
        for(j=0; j<n; j++){
            printf("\t%d ", matriz[i][j]);
        }
        printf("\t|");
    }
}

