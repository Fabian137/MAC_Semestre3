#include <stdio.h>
#include <stdlib.h>

void multiplicacionMatrices(int a[20][20], int b[20][20], int fil1, int col2);
void escribirMatriz(int matriz[20][20], int n, int m, char matrizNombre);
void imprimirMatriz(int matriz[20][20], int n, int m);

int main(){
    int fil1, col1, col2, fil2, i, j;
    
    printf("\n");
    printf("Ingresa los valores de la primera matriz");
    printf("\nFilas: ");
    scanf("%d", &fil1);
    printf("Columnas: ");
    scanf("%d", &col1);

    printf("\nIngresa los valores de la segunda matriz");
    printf("\nFilas: ");
    scanf("%d", &fil2);
    printf("Columnas: ");
    scanf("%d", &col2);

    if(col1 != fil2){
        printf("\nNo se pueden multiplicar las matrices\n  %d x %d != %d x %d \n", fil1, col1, fil2, col2);
        printf("\nDeben coincidir las columnas de la primera matriz con las filas de la segunda\n");
        exit(0); // Se detiene el programa
    }
    else{
        int a[fil1][col1], b[fil2][col2]; // Declaracion de las matrices a partir de los datos
        escribirMatriz(a, fil1, col1, 'a');
        printf("\nSiguiente matriz\n");

        escribirMatriz(b, fil2, col2, 'b');
        multiplicacionMatrices(a, b, fil1, col2);
    }
    printf("\n");
    return 0;
}


void multiplicacionMatrices(int a[20][20], int b[20][20], int fil1, int col2){
    int i, j, k, matrizRes[fil1][col2];

    printf("\n La matriz resultante de la multiplicación es: \n");
    for ( i = 0; i < fil1; i++){
        for ( j = 0; j < col2; j++){
            matrizRes[i][j] = 0;
            for (k = 0; k <= col2; k++){
                matrizRes[i][j] += a[i][k] * b[k][j]; //Aqui se ejecuta la multiplicación y se suma
            }
        }
        printf("\n");
    }
    //Imprimo la matriz resultante
    for(i=0; i<fil1; i++){
        printf("\n |\t");
        for(j=0; j<col2; j++){
            printf(" %d ", matrizRes[i][j]);
        }
        printf("\t|");
    }   
}

void escribirMatriz(int matriz[20][20], int n, int m, char matrizNombre){
    int i,j;
        printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf(" %c%d%d: ", matrizNombre, i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    //Imprimo la matriz escrita
    imprimirMatriz(matriz, n, m);
}

void imprimirMatriz(int matriz[20][20], int n, int m){
    int i,j;
    for(i=0; i<n; i++){
        printf("\n |\t");
        for(j=0; j<m; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\t|");
    }
}