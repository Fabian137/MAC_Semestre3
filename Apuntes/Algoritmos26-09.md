# Algoritmos


## Algoritmo que elimina un elmeneto que coincide con cierta información
Pueden ocurrir los siguientes casos:
1. No hay lista
2. Si hay elementos
    2.1 No encontramos el elemento
    2.2 Seal el segundo en adelante


´´´pseudocode

Si P=NULL
    Escribir('No hay lista creada')
Si no
    Leer(Dato)
    Si P^.info = dato
        Q=P
        P=P^.liga
        Quitar(Q)
    
        Si no
            Q=P
            Mientras(Q^.info != dato) Y (Q != NULL)
                T=Q
                Q=Q^.liga
            FinMientras

        Si Q^.info != dato
            Escribir('No se encontró el elemento')
        Si no
            T^.liga = Q^.liga
            Quitar(Q)
        FinSi
    FinSi
FinSi
´´´


## Insertar antes del que coincide
1. No hay lista
2. Sí hay lista
    2.1 Sí hay elemento
    - Primer elemento
    - Cualquier elemento

    2.2 No hay elemento. No inserto

Ocupamos tres apuntadores

## Insetar despu{es del que coincide
1. No coincide
2. Si hay lista
    2.1 No encontré el elemento
    2.2 Sí encontre el elemento

## Borrar antes del que coincide
1. No hay lista
2. Sí hay lista
    2.1 No existe elemento que coincide
        - no se borra nada
    2.2 Sí existe el elemento
    - Es el primero -> no borro nada
    - Es el segundo elemento -> Borro el primer elemento 
    - Es del tercero en adelante
        - Dirección del penúltimo elemento anterior. O sea que necesitamos las dos direcciones anteriores

## Borra después del que coincide
1. No hay lista
2. Sí hay lista
    2.1 No existe -> No borro nada
    2.2 Sí existe
    - Es el último -> no se borra
    - No es el último (penúltimo)