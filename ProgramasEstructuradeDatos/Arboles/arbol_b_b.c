#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo{
    struct Nodo *izq;
    char info;
    struct Nodo *der;
};

void insercion(struct Nodo **elemento, int dato);
void buscar_elemento(struct Nodo **elemento, int dato);
void eliminar_nodo(struct Nodo **elemento, struct Nodo **nodoS, int dato);


int menu();

void preorden(struct Nodo **raiz);
void inorden(struct Nodo **raiz);
void posorden(struct Nodo **raiz); 
bool arbol_vacio(struct Nodo **raiz);
void mensaje_arbol_vacio();

int main(){
    struct Nodo *raiz;
    // struct Nodo *aux;
    // struct Nodo *Q;
    struct Nodo *nodoS; //sucesor

    int respuesta, dato, i;
    // int *arr;  

    raiz    =(struct Nodo *) malloc(sizeof(struct Nodo));
    // aux     =(struct Nodo *) malloc(sizeof(struct Nodo));
    // Q       =(struct Nodo *) malloc(sizeof(struct Nodo));
    nodoS =(struct Nodo *) malloc(sizeof(struct Nodo));
    raiz = NULL;


    do{
        respuesta = menu();
        
        switch(respuesta){
            case 1:
                printf("\n\n Indique el dato a insertar en el ABB: ");
                scanf("%d", &dato);
                    if(raiz == NULL){
                        raiz = (struct Nodo *) malloc(sizeof(struct Nodo));
                        raiz->info = dato;
                        raiz->izq = NULL;
                        raiz->der = NULL;
                    }else{
                        insercion(&raiz, dato); 
                    }
            break;

            case 2:
                printf("\n\n Indique el dato a BUSCAR en el ABB: ");
                scanf("%d", &dato);
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : buscar_elemento(&raiz, dato);
            break;

            case 3:
                printf("\n\n Indique el dato a BORRAR en el ABB: ");
                scanf("%d", &dato);
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : eliminar_nodo(&raiz, &nodoS, dato);

            break;

            case 4:
                printf("Impresión del árbol en distintos ordenes\n\n");
                if (arbol_vacio(&raiz)){
                    mensaje_arbol_vacio();
                }else{
                    printf("\n\n");
                    preorden(&raiz);
                    printf("\n\n\n");
                    inorden(&raiz);
                    
                    printf("\n\n\n");
                    posorden(&raiz);
                    printf("\n\n");
                }
            break;

            case 0:
                printf("Saliendo del programa\n\n");
            break;
            default:
                printf("Digite una opcion valida\n\n"); 
            break; 
        }
        
    }while(respuesta!=0);

    return 0;
}

int menu(){
    int res;
    printf("\n\n");
    printf("ALGORITMO QUE CARGA UN ARBOL BINARIO DE BÚSQUEDA\n\n");
    printf("1. Inserción de elementos en el Árbol Binario de Búsqueda\n\n");
    printf("2. Búsqueda de un elemento en el ABB \n\n");
    printf("3. Eliminación de un elemento en el ABB\n\n");
    printf("4. Impresiones en PreOrden, InOrden y PosOrden\n\n");
    printf("0. Salida\n\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}


void insercion(struct Nodo **elemento, int info){
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));

    if (info <= (*elemento)->info){
        
        if ((*elemento)->izq == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->izq = aux;
        
        }else{
            insercion(&((*elemento)->izq), info);
        }
           
    }else{

        if ((*elemento)->der == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->der = aux;
        
        }else{
            insercion(&((*elemento)->der), info);
        }
    }
}

void buscar_elemento(struct Nodo **elemento, int dato){
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{

            buscar_elemento(&((*elemento)->izq), dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                buscar_elemento(&((*elemento)->der), dato);
            }
        }else{
            printf("\n El nodo SE encuentra en el árbol\n");
        }    
    }
}


void preorden(struct Nodo **raiz){
    if(*raiz != NULL){
        printf("\n\n Valor: %d", (*raiz)->info);
        preorden(&(*raiz)->izq);
        preorden(&(*raiz)->der);
    }
}

void inorden(struct Nodo **raiz){
     
    if(*raiz != NULL){
        inorden(&(*raiz)->izq);
        printf("\n\n Valor: %d", (*raiz)->info);
        inorden(&(*raiz)->der);
    }
}

void eliminar_nodo(struct Nodo **elemento, struct Nodo **nodoS, int dato){
    
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));
    
    
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            eliminar_nodo(&((*elemento)->izq), nodoS, dato);
        }
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                eliminar_nodo(&((*elemento)->der), nodoS, dato);
            }
        }else{// ------------   DATO A ELIMINAR     -----------

            printf("\n El nodo SE encuentra en el árbol\n");
            printf("\n %d\n", (*elemento)->info);

            if (((*elemento)->izq || (*elemento)->der) && !((*elemento)->izq && (*elemento)->der)){ // SI TIENE UN SOLO HIJO. Compuerta XOR

                if ((*elemento)->izq != NULL){
                    (*elemento)->info = (*elemento)->izq->info;
                    (*elemento)->izq = NULL;

                }else if ((*elemento)->der != NULL){
                    (*elemento)->info = (*elemento)->der->info;
                    (*elemento)->der = NULL;
                }
                else{
                    printf("\n ERROR??? \t --------- QUE \n");
                }
            }
            else if ((*elemento)->izq && (*elemento)->der){ //TIENE DOS HIJOS
                aux = *elemento;
                // -------- Sucesor de una forma rudimentaria
                    aux = aux->der;
                    if (aux->izq == NULL){
                        (*elemento)->info = aux->info;
                        if (aux->der != NULL){
                            (*elemento)->der = aux->der;

                        }
                        else{
                            (*elemento)->der = NULL;
                            aux->der = NULL;
                        }
                        
                    }else{
                        (*elemento)->der = NULL;
                        while (aux->izq != NULL){
                            *nodoS = aux; //desfazado
                            aux = aux->izq;
                        }
                        (*elemento)->info = aux->info;
                        
                        if ((*nodoS)->izq != NULL){
                            (*nodoS)->izq = NULL;
                        }
                    }
            
            }
            else{ // ES UNA HOJA (no tiene hijos)
                *elemento = NULL;   
            }
            printf("\n Se borro correctamente (esperamos)\n");
        }    
    }
}

void posorden(struct Nodo **raiz){
    if(*raiz != NULL){
        posorden(&(*raiz)->izq);
        posorden(&(*raiz)->der);
        printf("\n\n Valor: %d", (*raiz)->info);
    }
}

bool arbol_vacio(struct Nodo **raiz){
    if (*raiz != NULL){
        return false;
    }
    return true;
}
void mensaje_arbol_vacio(){
    printf("\n-----------------------------------\n");
    printf("\nEl árbol no tiene elementos\n\nInserte al ABB con la opción 1\n");
    printf("\n-----------------------------------\n");
}