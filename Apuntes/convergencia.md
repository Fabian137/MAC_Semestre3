$$O(h^n)$$
Orden de convergencia (aproximación)

$g(x)$ = Denota la formula iterativa de cada método
Sé que el método es convergente cuando tomo a $g(x)$ y sl derivarla y evaluarla es menor que 1, o sea
$$|g'(x)| < 1$$
***Pd: IMPORTANTE***

| **Método** | **Convergencia** | |
|-|-|-|
|Bisección   | Lineal | $$|e_n|=\frac{|b-a|}{2^n}$$ |
| Newton-Raphson| Cuadrática | $\frac{g''(\epsilon)}{2}(e_n)^2 \Rightarrow O(h^2)$| 
| Posición falsa| Lineal | $g'(x)=\frac{f(x)F(x-X)-F[f(x)-F]}{[f(x)-F]^2}$| 
| Secante| SuperLineal | $e_{n+1}=\frac{g''(\epsilon_1, \epsilon_2)}{2}(e_n)(e_{n-1})$| 


## Método de Bisección
Ya que el intervalo que se elige y sobre el que se trabaja en el método encierra a la raíz, una mitad del interbalo 
en cuestión es una frontera superior del error.
**Tiene una convergencia lineal**
$$|e_n|=\frac{|b-a|}{2^n}$$

En el caso del método de bisección ...
$$g(x) = \frac{a+b}{2}$$

## Método de Newton
El método de newton tiene el siguiente esquema iterativo
$$x_{n+1}=$$

- $f(x)$ no debe ser cero en el intervalo, sino la derivada no nos llevará a ningun lado
- Es cuadráticamente convergente dado que r es una raíz de
  $$f(x) = 0$$
  $$r = g(x)$$
  $$x_{n+1} = g(x_n)$$
  $$x_{n+1} -r = g(x_n)-g(r)$$

. . .
  $$g_{n} = g(r)+g'(r)(x_n-r)+\frac{g''(\epsilon)}{2}(x_n-r)^2$$

. . .
Tiene una convergencia de orden 2, $O(h^2)$, cuadráticamente convergente

## Métodos de la secante y de la posición falsa
$$g(x) =$$

- En cada iteración remplazamos uno de los valores de x previos con la nueva estimación
- El mismo proceso encierra la raíz
- Usualmente uno de los extremos no cambia
- Podemos pensar a $x_{n-1}$ se puede pensar como una fórmula y reescribir $g(x)$
- ...

- Es linealmente convergente

## Método de Bairstow
Para polinomios caracteristicos




  
