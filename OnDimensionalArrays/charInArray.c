#include <stdio.h>

int CharInArray(char a[], char b){
    int i = 0;
     
    for (i = 0; i < 15; i++){
        if (a[i] == b){
            return i+1;
            break;
        }
    }
    
}

int main(){
    char arrayOChar[15];
    char caracter; 
    int val;

    // printf("\n");
    printf("\nPalabra (14 caracteres): ");
	fflush(stdin);
	fgets(arrayOChar, 15, stdin);
	//HASTA QUE suceda:
	//- Hay un ENTER

	printf("Palabra: %s\n", arrayOChar);   
	printf("\nIngrese el caracter que gustes buscar: ");
    scanf(" %c", &caracter);
	//Si se pasa de la cantidad de caracteres el siguiente scanf lee ese dato

    val = CharInArray(arrayOChar, caracter);
    
    if (val != 0 ){
        printf("\n -- Dato localizado en la posicion: %d", val);
        printf("\n\t Caracter: %c", caracter);
    }
    else{
        printf("\n Dato no localizado");
    }
    
    
    printf("\n");
    return 0;
}