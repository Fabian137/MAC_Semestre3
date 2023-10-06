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
struct Nodo *busqueda_nodo(struct Nodo **P, struct Nodo **Q, int dato);
void mensaje_lista_vacia();
void busqueda(struct Nodo **P, struct Nodo **Q, struct Nodo **F,int dato);

int main(){
    struct Nodo *P = NULL;
    struct Nodo *F = NULL;
    struct Nodo *Q = NULL;

    int dato, res;

    do{
        res = menu();

        switch(res){
            case 1: 
                creacion_final(&P, &F, &Q); 
                break;
            case 2: 
                /*--Operador ternario ò IF TERNARIO--*/
                !lista_vacia(&P) ? impresion(&P, &Q) : mensaje_lista_vacia();
                
                break;
            case 3:
                printf("\nBorar el principo\n");
                !lista_vacia(&P) ? borra_principio(&P, &Q) : mensaje_lista_vacia();
                break;
            
            case 4:
                if(!lista_vacia(&P)){
                    printf("\nnodo buscado: ");
                    scanf("%d", &dato);
                    busqueda(&P, &Q, &F, dato);
                }
                else{
                    mensaje_lista_vacia();
                }
                break;
        }

    }while(res!=0);
    
    free(P);
    // free(Q);
    free(F);
 
    
    return 0; 
}


int menu(){
    int res;
    printf("\n\n");
    printf("1. ALGORITMO QUE CREA UNA LISTA CIRCULAR POR EL FINAL\n");
    printf("2. ALGORITMO QUE IMPRIMA EL CONTENIDO DE UNA LISTA CIRCULAR\n");
    printf("3. ALGORITMO QUE ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR\n");
    printf("4. ALGORITMO QUE BUSCA UN ELEMENTO CON INFORMACIÓN DADA Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

bool lista_vacia(struct Nodo **P){
    if (*P != NULL){
        return false;
    }
    return true;
}

void creacion_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q){
    int n,i; 
    printf("\n\nDame el numero de valores a ingresar: ");
    scanf("%d", &n);

    for(i=0; i < n ; i++){
        if(lista_vacia(P)){
            *P =(struct Nodo *) malloc(sizeof(struct Nodo));
            printf("Dame el valor a ingresar de P: ");
            scanf("%d", &(*P)->info);
            (*P)->liga = *P;
            *Q = *P;
            *F = *Q;
        }else{
            ((*Q)->liga) =(struct Nodo *) malloc(sizeof(struct Nodo));
            *Q = (*Q)->liga;
            printf("Dame el valor a ingresar: ");
            scanf("%d", &(*Q)->info);
            (*Q)->liga = *P;  
            *F = *Q;
        }
    }
}

void impresion(struct Nodo **P, struct Nodo **Q){ 
    *Q = *P;

    printf("\n\n");
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

void mensaje_lista_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}

struct Nodo *busqueda_nodo(struct Nodo **P, struct Nodo **Q, int dato){

    *Q = *P;
    do{
        if ((*Q)->info == dato){
        return *Q;
    }
            *Q = (*Q)->liga;
    }while ((*Q)->liga != *P);
    
    return NULL;
}

void busqueda(struct Nodo **P, struct Nodo **Q, struct Nodo **F,int dato){
    *Q = *P;
    struct Nodo *S=*F;

    if ((*Q)->info == dato){
        printf("\n%p - %d\n", S, S->info);
        printf("\n%p - %d\n", (*Q)->liga, (*Q)->liga->info);
        return;
    }
    
    if (S->info == dato){
        S = S->liga;
        while (S->liga != *F){
            S = S->liga;
        }
        printf("\n%p - %d\n", S, S->info);
        printf("\n%p - %d\n", (*P)->liga, (*P)->info);
        return;
    }
    
    while ((*Q)->liga != *P){

        if ((*Q)->info == dato){
            
            while (S->liga!= *Q){
                S = S->liga;
            }
            printf("\n%p - %d\n", S, S->info);
            printf("\n%p - %d\n", (*Q)->liga, (*Q)->liga->info);
            return;
        }
        Q = &((*Q)->liga);
    }
    printf("\n El nodo proporcionado no se encuentra en la lista\n");
    // free(S);
}