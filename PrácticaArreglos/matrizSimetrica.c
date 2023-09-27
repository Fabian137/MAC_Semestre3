#include <stdio.h>

    void ingresardatos(float A[10][10], int n);
    void matriztranspuesta(float T[10][10], float new[10][10], int n);
    void imprimirmatriz(float I[10][10], int n);
    void comparacion(float T[10][10], float new[10][10], int n);

int main(){
    float simetricam[10][10], new[10][10];
    int control;
    control=4;
        ingresardatos(simetricam, control);

        printf("\n\nLa matriz original deberia ser: \n\n");
        imprimirmatriz(simetricam, control);

        matriztranspuesta(simetricam, new, control);

        printf("\n\nLa matriz transpuesta deberia ser: \n\n");
        imprimirmatriz(new, control);

        comparacion(simetricam, new, control);
        

    return 0;
}

void ingresardatos(float A[10][10], int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            printf("\n\nDame el valor [%d] [%d]: ", i, j);
            scanf("%f", &A[i][j]); 

        }
    }
}

void matriztranspuesta(float T[10][10], float new[10][10], int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            new [i][j] = T[j][i];
        }
    }
}

void imprimirmatriz(float I[10][10], int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            printf("%0.2f", I[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void comparacion(float T[10][10], float new[10][10], int n){
    int i, j, control=1;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            if(new[i][j]!= T[i][j]){
                control=0;
            }
        }
    }
    if(control==0){
        printf("\n\nLa matriz no es simetrica\n");
    }else{
        printf("\n\nLa matriz si es simetrica\n");
    }
}