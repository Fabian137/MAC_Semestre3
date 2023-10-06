#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int info;
    struct Nodo *liga; 
}; 

void creacion_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q); 

/*---------""Genericas""---------*/
bool lista_vacia(struct Nodo **P);
int menu();
struct Nodo *busqueda_nodo(struct Nodo **P, struct Nodo **Q, struct Nodo **F, int dato, int posicion_nodo);
void mensaje_lista_vacia();
void impresion(struct Nodo **P, struct Nodo **Q);
/*-------------------------------*/


/*---------Nuevos---------*/
void insercion_principio(struct Nodo **P, struct Nodo **Q, struct Nodo **F);
void insertar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **F);
void borrar_nodo_final(struct Nodo **P, struct Nodo **Q, struct Nodo **F);
void borrar_despues(struct Nodo **P, struct Nodo **Q, struct Nodo **F);

/*------------------------*/

int main(){
    struct Nodo *P = NULL;
    struct Nodo *F = NULL;
    struct Nodo *Q = NULL;

    int res;

    do{
        res = menu();

        switch(res){
            case 1:  
                /*--Operador ternario ò IF TERNARIO--*/ 
                // lista vacia? si, mensaje de error, si no, ejecutar función
                lista_vacia(&P) ? mensaje_lista_vacia() : insertar_antes(&P, &Q, &F);
                break;
            case 2: 
                lista_vacia(&P) ? mensaje_lista_vacia() : insercion_principio(&P, &Q, &F);
                
                break;
            case 3:
                lista_vacia(&P) ? mensaje_lista_vacia() : borrar_nodo_final(&P, &Q, &F);
                break;
            
            case 4:
                lista_vacia(&P) ? mensaje_lista_vacia() : borrar_despues(&P, &Q, &F);
                break;
            
            case 5:
                creacion_final(&P, &F, &Q);
                break;

            case 6:
                lista_vacia(&P) ?  mensaje_lista_vacia() : impresion(&P, &Q);
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
    printf("1. Inserción antes de un nodo dado\n");
    printf("2. Inserción al principio\n");
    printf("3. Eliminación elemento final\n");
    printf("4. Eliminación después de un nodo dado\n");
    printf("5. Creación\n");
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
    impresion(&(*P), &(*Q));
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

    printf("\n\nValor de P: %d\n", (*P)->info);
}

void insercion_principio(struct Nodo **P, struct Nodo **Q, struct Nodo **F){
    int dato;
    *Q =(struct Nodo *) malloc(sizeof(struct Nodo));
    printf("Dame el valor a ingresar de P: ");
    scanf("%d", &dato);
    (*Q)->info = dato;
    (*F)->liga = *Q;
    (*Q)->liga = *P;
    *P=*Q;
    impresion(&(*P), &(*Q));
}

void borrar_nodo_final(struct Nodo **P, struct Nodo **Q, struct Nodo **F){
    if((*P)->liga == *P){
        free(*P);
        *P = NULL;
        printf("\nSe borro con exito\n Pero ahora no tienes lista\n\n");
    }
    else{
        *Q=*P;
        while((*Q)->liga != *F){
            *Q = (*Q)->liga;
        }
        (*Q)->liga = *P;
        free(*F);
        *F = *Q;
        printf("\nSe borro con exito");
        impresion(&(*P), &(*Q));
    }

}


void mensaje_lista_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}

struct Nodo *busqueda_nodo(struct Nodo **P, struct Nodo **Q, struct Nodo **F, int dato, int posicion_nodo){
    /*
    Creo que hay dos formas de lograr que me mande el nodo anterior, el dado, o el siguiente al dado segun la variable posicion_nodo, que toma valores -1, 0, 1 respectivamente. Y me parece que el caso que más atención requiere es el de posicion_nodo = -1 ya que para 0 solo retornamos el nodo Q actual. Y para posicion_nodo = 1, retornamos el nodo siguiente a Q, al cual podemos acceder como Q->liga
    Asi que

    -- Una forma es con un nodo auxiliar que vaya desfasado, entonces si queremos el anterior a dado, o sea con posicion_nodo = -1
    nos retornara este nodo desfasado --- se necesitan más nodos

    -- Otra forma que se me ocurre es ajustar las condiciones y que para -1 vaya adelantado, es decir
        si posicion_nodo == -1
            (*Q)->liga->info == dato
                return Q
    
    Asi tendría 3 condiciones "principales" o incluso intervalos, posicion_nodo<0, >0 y el caso =0 se resuelve por el else. Y dentro de las condiciones estarían otras condiciones con los ifs ajustados dependiendo del nodo que quiera.
    Si lo manejo asi podría reducirlo a 3 ifs, agregando con la compuerta AND los ifs anidados a los "principales"
    

    para nodo_posicion=-1
        Si el nodo dado es el primero, no va a entrar al if y regresará un NULL por dafault, independientemente de si el nodo está o no

    Gracias a que es circular los otros casos digamos se ignoran porque no pasan, el único elemento que no tiene antescesor es el primero
    A pesar de que el final apunte a  . . . 
    */

    *Q = *P;
    do{
        if (posicion_nodo == -1){ //----posicion_nodo = -1
        //Estos dos se pueden hacer en uno
        //nodo anterior
            if ((*Q)->liga->info == dato){
                return *Q;
            }
        }
        if (posicion_nodo == 1){ //----posicion_nodo = 1, retorna nodo siguiente
            if ((*Q)->info == dato){
                return (*Q)->liga;
            }else if ((*F)->info==dato){
                return (*F)->liga;
            }
        }else if(posicion_nodo == 0){ //---- posicion_nodo =0, nodo actual o pedido
            if ((*Q)->info == dato){
                return *Q;
            }else if ((*F)->info==dato){
                return *F;
            }
        }
        
        *Q = (*Q)->liga;
    
    // }while ((*Q)->liga != *P); //Condición de paro anterior (no sirvio en este contexto)
    }while (*Q!= *P);
    /*
    Si es el primer elemento que quiere buscar el anterior es F, el último, pero debido al ciclo nuestra condición no alcanza a llegar 
    A menooos, que cambiemos la condición, y por asi decirlo tendríamos una iteración extra
    */
    
    return NULL;
}

void insertar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **F){
    int dato;
    struct Nodo *Aux;

    impresion(&(*P), &(*Q));
    printf("\n\n¿Antes de qué nodo deseas insertar?: ");
    scanf("%d", &dato);
    Aux = (struct Nodo *) malloc(sizeof(struct Nodo));
    
    *Q = busqueda_nodo(P, Q, F, dato,-1);
    /*busqueda previa para ver si si está el nodo y que entre en las demás condiciones
    Nos devuelve el nodo anterior, y trato el algoritmo como el de insertar despues 
    */
    if (!*Q){ //No está el elemento -- *Q == NULL
        printf("\n--No se encontro el elemento dado: %d, en la lista\n", dato);
        free(Aux); // Si no está, no tiene sentido tener Aux
        return;
    }
    // ya que sabemos que sí está porque verifico el if anterior. Es "seguro" interactura con el nodo sin preocupacion de que sea NULL
    printf("Dame el valor a ingresar del nuevo nodo: ");
    scanf("%d", &dato);
    Aux->info = dato;
    Aux->liga = (*Q)->liga;

    if((*Q)->liga == *P){ //Si es el primero
        *P = Aux;
    }
    (*Q)->liga = Aux;
    impresion(&(*P), &(*Q));
}

void borrar_despues(struct Nodo **P, struct Nodo **Q, struct Nodo **F){
    int dato;
    struct Nodo *Aux;

    impresion(&(*P), &(*Q));
    printf("\n\n¿Después de qué nodo deseas eliminar?: ");
    scanf("%d", &dato);
    *Q = busqueda_nodo(P, Q, F, dato, 0); //devuelve el nodo dado

    if (!*Q){ //No está el elemento -- *Q == NULL
        printf("\n--No se encontro el elemento dado: %d, en la lista\n", dato);
        return;
    }


    if (*Q == *P && (*Q)->liga == *P){
        printf("\n--Solo hay un nodo en la lista\n");
        return;
    }    
    else if((*Q)->liga == *P){ //Borrar el primero
        *P = (*P)->liga;
        free((*Q)->liga);
        (*F)->liga = *P;
        impresion(&(*P), &(*Q));
        return;
    }
    else if ((*Q)->liga == *F){//Borrar el ultimo
        free((*Q)->liga); //
        (*Q)->liga = *P;
        *F = *Q;
        (*F)->liga = *P;
        impresion(&(*P), &(*Q));
        return;
    }
    Aux = (*Q)->liga;
    (*Q)->liga = Aux->liga; 
    free(Aux);
    impresion(&(*P), &(*Q));
}