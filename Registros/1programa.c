#include <stdio.h>

const int n = 6;

struct JugadoresBas{
    char nombreCompleto[40];
    int edad;
    char sexo;
    float altura;
};

void leerDatos(struct JugadoresBas player[n], int n);
float promedioAltura(struct JugadoresBas player[n], int n);

int main() {
    struct JugadoresBas jugador[6];
    float promedio;
    int i;

    leerDatos(jugador, n);

    promedio = promedioAltura(jugador, n);
    printf("\n\t El promedio de las alturas de los jugadores es %.2f\n\n", promedio);
    

    for (i=0; i<n; i++) {
        printf("\n\t-----------------------------"); 
        printf("\n\tJugador %d:\n", i+1);
        printf("\t%s\t--\t%c\n",jugador[i].nombreCompleto, jugador[i].sexo);
    }

    return 0;
}

void leerDatos(struct JugadoresBas player[n], int n){
    int i;
    for (i=0; i<n; i++) {
        printf("\n-------------------------------------------"); 
        printf("\n\tJugador %d:", i+1);
        printf("\nNombre y apellido: ");
        fflush(stdin);
	    fgets(player[i].nombreCompleto, 40, stdin);

        // printf("\n\t\t %s \n", player[i].nombreCompleto);
        printf("Edad: ");
        scanf("%d", &player[i].edad);
        printf("Sexo (M/F): ");
        scanf(" %c", &player[i].sexo);
        printf("Altura (en metros): ");
        scanf("%f", &player[i].altura);

        // Limpiar el búfer de entrada después de scanf
        while (getchar() != '\n');
    }
}

float promedioAltura(struct JugadoresBas player[n], int n){
    float suma = 0;
    int i;
    for (i=0; i<n; i++){
        suma += player[i].altura;
    }
    return (suma/n);
}
