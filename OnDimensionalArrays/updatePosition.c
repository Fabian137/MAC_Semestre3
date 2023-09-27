#include <stdio.h>

void lecturaArray(int array[], int leng){
    int i;
    printf("\n\nIngrese los elementos del arrreglo\n");
    for (i = 0; i < leng; i++){
	    printf("%dº: ", i);
	    scanf("%d", &array[i]);
    }
}

void impresionArray(int array[], int leng){
    int i;
    for (i = 0; i < leng; i++){
        printf("\n");
	    printf("%dº: %d", i, array[i]);
	}
}

int main(){
    int leng = 7, i, j;
    int array[leng+1];
    int pos, value, indice;

    lecturaArray(array, leng);
    
    printf("\n De tu arreglo que posición gustas modificar: ");
    scanf("%d", &pos);
    
    printf("\n Ingresa el valor nuevo: ");
    scanf("%d", &value);

    for ( i = 0; i < leng+1; i++){
        if (pos == i){
            for (j = pos; j < leng+1; j++){
                indice = leng - (j-pos);                                                         
                array[indice] = array[indice-1];
            }
            array[pos] = value;
        }
    }
    impresionArray(array, leng+1);
    
    printf("\n");
    return 0;
}