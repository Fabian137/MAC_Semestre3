Los compiladores (o lenguajes de programación) trabajan con las matrices como vectores.  Trabajan en una ordenación por renglón - Elementos x rengolón => (C, Java, Python).
																	- Elementos x Columna => Fortran


$$
A_{5*4} = \begin{pmatrix} 
a_{11} & a_{12} & a_{13} & a_{14}\\
a_{21} & a_{22} & a_{23} & a_{22}\\ 
a_{31} & a_{32} & a_{33} & a_{34}\\ 
a_{41} & a_{42} & a_{43} & a_{44}\\
a_{51} & a_{52} & a_{53} & a_{54}
\end{pmatrix}
$$


Representación por renglón

|a11 |a12 | a13 | a14 | a21| . . .  | a53 | a54 |
|---|---|--|--|--|--|--|--|
| 1| 2 |3 |4 |5 | 6|7| 8|


#### Localización de un elemento al almacenar por renglones
```
POS[i,j] = InitPosition + (i-1) * N + (j-1)
```

|a11 |a12 | a13 | a14 | a21| a22|a23|a24|a31|a32|a33|a34|a41|a42|**a43**|
|---|---|--|--|--|--|--|--|--|--|--|--|--|--|--|
| 80| 81 |82 |83 |84 | 85|86| 87| 88| 89| 90| 91 | 92 | 93 | **94** |

```
POS[4,3] = 80 + (4-1) * 4 + (3-1)
		 = 80 + 12 +2 
		 = 94
```


#### Localización de un elemento al almacenar por columna
```
POS[i,j] = InitPosition + (j-1) * M + (i-1)

%%EJEMPLO%%
POS[4,3] = 80 + (3-1) * 5 + (4-1)
		 = 80 + 10 +3
		 = 93
```

|a11 |a21 | a31 | a41 | a51| a12|a22|a32|a42|a52|a13|a23|a33|**a43**|a53|
|---|---|--|--|--|--|--|--|--|--|--|--|--|--|--|
| 80| 81 |82 |83 |84 | 85|86| 87| 88| 89| 90| 91 | 92 | **93** | 94 |


**Una matriz poco densa es aquella que tiene valores repetidos y donde no existe la completa necesidad de almacenar estos valores repetidos**
#### Ejemplo

$$
\begin{pmatrix} 
a_{11} & 0 & 0 & 0\\
a_{21} & a_{22} & 0 & 0\\ 
a_{31} & a_{32} & a_{32} & 0\\ 
a_{41} & a_{42} & a_{43} & a_{44}
\end{pmatrix}
$$

|a11 |a21 | a22 | a31 | a32| a33|a41|a42|...|an1|an2|...|**ann**|
|---|---|--|--|--|--|--|--|--|--|--|--|--|
| 80| 81 |82 |83 |84 | 85|86| 87| ...||| |

1 + 2+ 3 +4 + . . . + (i - 1) = (i - 1)(i) / 2

1 + 2 + 3 + 4 + . . . + n = (n-1)(n) / 2

S i > j => 0

Asi que para ubicar elementos en una matriz triangular 

```
POS(i,j) = InitPosition + (i-1)(i) / 2 + (j-1)

POS(4,1) = 1 + (4-1)(4) / 2 + (1-1)
POS(4,1) = 1 + 12 / 2 +0
POS(4,1) = 1 + 6 = 7
```


Acomodandolo como columnas y para una matriz triangular superior los ceros se comportan como inducción