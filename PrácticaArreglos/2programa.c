#include <stdio.h>
#include <stdlib.h>

void escribirMatriz(int matriz[10][10], int n, int m);
void imprimirMatriz(int matriz[10][10], int n, int m, char typeNum, int colRow);
int identifyRowCol(int a[10][10], int n, int m, char typeNum);

int main(){
    int numMenor /*fila*/, numMayor/*col*/;
    int matrix[10][10];


    printf("\n Ingrese la matriz de 4x4");
    escribirMatriz(matrix, 4, 4);
/*
Use s para maximo e i para minimo*/
    numMenor = identifyRowCol(matrix, 4, 4, 'i'); 
    numMayor = identifyRowCol(matrix, 4, 4, 's');

    printf("\n\n la fila es: %d", numMenor+1);
    imprimirMatriz(matrix, 4,4,'i',numMenor);
    
    printf("\n\n la columna es: %d", numMayor+1);
    printf("\n");
    imprimirMatriz(matrix, 4,4,'s',numMayor);

    printf("\n");
    return 0;
}

void escribirMatriz(int matriz[10][10], int n, int m){
    int i,j;
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf(" a%d%d: ", i+1, j+1);
            // matriz[i][j] = i*;
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    //Imprimo la matriz escrita
    imprimirMatriz(matriz, n, m, 'n', 0);
}

int identifyRowCol(int a[10][10], int n, int m, char typeNum){
    int i, j, col, row, cota = 10000, cota2 = -10000;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (a[i][j] < cota && typeNum == 'i'){
                cota = a[i][j];
                row = i;
            }
            else if (a[i][j] > cota2 && typeNum == 's'){
                cota2 = a[i][j];
                col = j;
            }
        }
    }
    if (typeNum == 'i'){
        
        return row;
    }
    else if (typeNum == 's'){
        
    }
        return col;
}

void imprimirMatriz(int matriz[10][10], int n, int m, char typeNum, int colRow){
    int i,j;
    for(i=0; i<n; i++){
        printf("\n |\t ");
        for(j=0; j<m; j++){
            if(typeNum != 'i' && typeNum != 's'){
            printf("\t%d", matriz[i][j]);
            }        
        }
        
        if(typeNum == 'i'){
            printf("\t%d ", matriz[colRow][i]);
        }
        else if (typeNum == 's'){
            printf("\t%d ", matriz[i][colRow]);
            /* code */
        }
         printf("\t\t|");
    }
}