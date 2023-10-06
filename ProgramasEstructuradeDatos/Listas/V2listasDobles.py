class NodoDoble:
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None

class ListaDoble:
    def __init__(self):
        self.principio = None
        self.final = None

    def agregar_al_final(self, dato):
        nuevo_nodo = NodoDoble(dato) #Q
        if self.principio is None:
            self.principio = nuevo_nodo
            self.final = nuevo_nodo
        else:
            actual = self.final
            while actual.der:
                actual = actual.der
            actual.der = nuevo_nodo
            nuevo_nodo.izq = self.final
            # print(f'---{self.final.dato} ---- {actual.dato} -- {actual.der.dato}')
            self.final = actual.der

    def eliminar(self, dato):
        actual = self.principio  # Comenzamos desde el principio de la lista
        while actual:
            if actual.dato == dato:  # Comparamos el dato del nodo actual con el dato a eliminar
                if actual.izq is None:
                    # Si actual es el primer nodo, actualizamos self.principio
                    self.principio = actual.der
                    actual.der.izq = None  # Actualizamos el enlace izquierdo del nuevo primer nodo
                    # self.principio.izq
                    # print(f'{self.principio.izq}')
                else:
                    if actual.der:
                        actual.der.izq = actual.izq
                        actual.izq.der = actual.der  
                        
                    else:
                        self.final = actual.izq
                        self.final.der = None
                return  # Terminamos después de eliminar el dato
            
            else:
                if actual.der is None:
                    print('No se encuentra el dato en la lista')
            actual = actual.der  # Avanzamos al siguiente nodo
        print("\nNo hay  lista")
    
    def eliminar_ultimo_elemento(self):
        if self.principio is None:
            print('No hay lista')
        else:
            if self.principio.der is None:
                self.principio = None
            else:
                aux = self.principio
                while aux.der is not None:
                    aux.der = aux.der.der
                aux.der = None


    def imprimirF(self):
        actual = self.principio
        # indice = 0
        # print("None<-")
        while actual:
            # print(f' {indice}: {actual.dato}', end=' <-> ')
            print(f'{actual.dato}', end=' <-> ')
            actual = actual.der
            # indice += 1
        print("None")


def main():
    # Crear una instancia de ListaDoble
    mi_lista = ListaDoble()
    i = 0

    # Agregar nodos a la lista (ejemplo)
    # cantidad = int(input('¿Cuántos elementos tendrá la lista? '))
    cantidad=5
    print("Ingresa los elementos \n")
    while i < cantidad and i>=0:
        # dato = int(input(' : '))
        dato = i+1
        mi_lista.agregar_al_final(dato)
        i+=1

    # Imprimir la lista antes de eliminar un nodo
    print("\nLista antes de eliminar:")
    mi_lista.imprimirF()

    nodo_a_eliminar = 2
    mi_lista.eliminar_uno_delante(nodo_a_eliminar)

    print("\nLista después de eliminar:")
    mi_lista.imprimirF()

if __name__ == "__main__":
    main()