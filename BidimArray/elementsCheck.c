#include <stdio.h>
#include <stdlib.h>

void escribirMatriz(float matriz[10][10], int n, int m);
int countSums(float a[10][10], int n, int m, int num);
void imprimirMatriz(float matriz[10][10], int n, int m);
void imprimirMatriz(float matriz[10][10], int n, int m);

int main(){
    int zeros, positivos, negativos;
    // double sumaPositivos = 0, sumaNegativos = 0;
    float matrix[10][10];

    escribirMatriz(matrix, 5, 4);

     zeros = countSums(matrix, 5,4, 0);
     positivos = countSums(matrix, 5,4, 1);
     negativos = countSums(matrix, 5,4, -1);
    
    printf("\nHay %d ceros en tu matriz\n", zeros);
    printf("\nHay %d positivos en tu matriz\n", positivos);
    printf("\nHay %d negativos en tu matriz\n", negativos);

    printf("\n");
    return 0;
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
    //Imprimo la matriz escrita
    imprimirMatriz(matriz, n, m);
}

int countSums(float a[10][10], int n, int m, int num){
    int i, j, cant = 0;
    float sumaPositivos = 0, sums = 0;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if ((num == 0 && a[i][j] == num) || (num == 1 && a[i][j] > 0) || (num == -1 && a[i][j] < 0)){
                cant++;
                sums += a[i][j];
            }          
        }
    }
    if (num == 1){
        printf("\n\nLa suma total de positivos es: %.2f\n", sums);
    }else if (num == -1){
        printf("\nLa suma total de negativos es: %.2f\n", sums);
    }
     return cant;
}

void imprimirMatriz(float matriz[10][10], int n, int m){
    int i,j;
    for(i=0; i<n; i++){
        printf("\n |\t");
        for(j=0; j<m; j++){
            printf(" %.2f ", matriz[i][j]);
        }
        printf("\t|");
    }
}