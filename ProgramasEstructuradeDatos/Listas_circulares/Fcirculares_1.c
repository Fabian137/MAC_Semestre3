#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int info;
    struct Nodo *liga; 
}; 

int menu();
bool lista_vacia(struct Nodo **P);
void creacion_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q); 
void impresion(struct Nodo **P, struct Nodo **Q);
void borra_principio(struct Nodo **P, struct Nodo **Q);


int main(){
    struct Nodo *P = NULL;
    struct Nodo *F = NULL;
    struct Nodo *Q = NULL;

    int dato, res;

    do{
        res = menu();

        switch(res){
            case 1: 
                printf("caso 1");
                creacion_final(&P, &F, &Q); 
                break;
            case 2: 
                if(!lista_vacia(&P)){
                    impresion(&P, &Q); 
                }
                break;
            case 3:
                printf("Borar el principo");
                if(!lista_vacia(&P)){
                    borra_principio(&P, &Q); 
                }
                break;
            case 4:
                if(!lista_vacia(&P)){
                }
                break;
            case 5: 
                break;

            case 6: 
                if(!lista_vacia(&P)){
        
                }

                break;
        }

    }while(res!=0);
    
    free(P);
    free(F);
 
    
    return 0; 
}


int menu(){
    int res;
    printf("\n\n");
    printf("1. ALGORITMO QUE CREA UNA LISTA CIRCULAR POR EL FINAL (5,3,19,7)\n");
    printf("2. ALGORITMO QUE IMPRIMA EL CONTENIDO DE UNA LISTA CIRCULAR\n");
    printf("3. ALGORITMO QUE ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR\n");
    printf("4. ALGORITMO QUE BUSCA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE (BUSCAR EL 4, BUSCAR EL 3)\n");
    printf("5. Creacion de la lista\n");
    printf("6. Impresión\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

bool lista_vacia(struct Nodo **P){
    if (*P != NULL){
        return false;
    }
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
    return true;
}

void creacion_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q){
    int n,i; 
    printf("\n\nDame el numero de valores a ingresar: ");
    scanf("%d", &n);

    for(i=0; i < n ; i++){
        if(*P == NULL){
            *P =(struct Nodo *) malloc(sizeof(struct Nodo));
            printf("Dame el valor a ingresar de P: ");
            scanf("%d", &(*P)->info);
            (*P)->liga = *P;
            *Q = *P;
        }else{
            ((*Q)->liga) =(struct Nodo *) malloc(sizeof(struct Nodo));
            *Q = (*Q)->liga;
            printf("Dame el valor a ingresar: ");
            scanf("%d", &(*Q)->info);
            (*Q)->liga = *P;  
        }
    }
}

void impresion(struct Nodo **P, struct Nodo **Q){ 
    *Q = *P;
    while((*Q)->liga != *P){
        printf(" %d -> ", (*Q)->info);
        *Q = (*Q)->liga; 
    }
    printf(" %d --> ", (*Q)->info);  
    *Q = (*Q)->liga;
    printf(" %d", (*Q)->info);

    printf("\n\nValor de P: %d", (*P)->info);
}

void borra_principio(struct Nodo **P, struct Nodo **Q){
    if((*P)->liga == *P){
        free(*P);
        *P = NULL;
        printf("Se borro con exito");
    }else{
        *Q=*P;
        while((*Q)->liga != *P){
            *Q = (*Q)->liga;
        }
        *P = (*P)->liga;
        free((*Q)->liga);
        (*Q)->liga = *P;
    }
}