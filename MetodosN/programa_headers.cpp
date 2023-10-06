#include <iostream>
#include <stdlib.h>
#include <complex>
#include <math.h>

using namespace std;

//[Se define la macro como el valor donde se paran las iteraciones]
#define ERROR_TOLE 0.00005

//[FUNCIONES DE LAS ECUACIONES]
float primeraFunc(float valInput){
    return (pow(valInput, 2) * cos(valInput)) - (2 * valInput);
}

float segundoFunc(float valInput){
    return ((6 - (2 / pow(valInput, 2))) * ((exp(2 + valInput)) / 4)) + 1;
}

float tercerFunc(float valInput){
    return (pow(valInput, 3)) - (3 * sin(pow(valInput, 2))) + 1;
}

float cuartaFunc(float valInput){
    return (pow(valInput, 3)) + (6 * pow(valInput, 2)) + (9.4 * valInput) + 2.5;
}

//[FUNCIONES PARA LAS DERIVADAS]
float primeraDer(float valInput){
    return (-pow(valInput, 2) * sin(valInput)) + ((2 * valInput) * (cos(valInput))) - 2;
}

float segundoDer(float valInput){
    return ((1 / 4) * exp(2 + valInput)) * ((6 - (2 / pow(valInput, 2))) + (4 / pow(valInput, 3)));
}

float tercerDer(float valInput)
{
    return (3 * pow(valInput, 2)) - (6 * valInput * cos(pow(valInput, 2)));
}

float cuartaDer(float valInput)
{
    return (3 * pow(valInput, 2)) + (12 * valInput) + 9.4;
}

/*[FUNCION PARA EL METODO DE LA SECANTE]
cotaI es el valor del intervalo por el lado izquierdo
cotaD es el valor del intervalo por el lado derecho
opc determina a que funcion se le buscara raices*/

void raizSecante(float cotaI, float cotaD, int opc)
{
    float x_0 = cotaI, x_1 = cotaD, x_2 = 0, f_0 = 0, f_1 = 0, f_2 = 0, errorA = 0, errorR = 0;
    bool flagExit = false;

    if (opc == 1)
    {
        cout << "\t\n[PRIMERA FUNCION POR SECANTE: x^2 cos(x) - 2x]\n";
        f_0 = primeraFunc(x_0);
        f_1 = primeraFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = primeraFunc(x_2);
    }

    if (opc == 2)
    {

        cout << "\t\n[SEGUNDA FUNCION POR SECANTE: (6 - 2/x^2) (e^2+x /4) + 1]\n";

        while (x_1 == 0 || x_0 == 0)
        {
            cout << "\n\t[EL VALOR NO ESTA DEFINIDO EN LA FUNCION, INTRODUCE UNO NUEVO]\n";
            if(x_1 == 0)
                cin >> x_1;
            if(x_0 == 0)
                cin >> x_0;
        }

        f_0 = segundoFunc(x_0);
        f_1 = segundoFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = segundoFunc(x_2);
    }

    if (opc == 3)
    {
        cout << "\t\n[TERCERA FUNCION POR SECANTE: x^3 - 3sen(x^2) + 1]\n";
        f_0 = tercerFunc(x_0);
        f_1 = tercerFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = tercerFunc(x_2);
    }

    if (opc == 4)
    {
        cout << "\t\n[CUARTA FUNCION POR SECANTE: x^3 + 6x^2 + 9.4x]\n";
        f_0 = cuartaFunc(x_0);
        f_1 = cuartaFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = cuartaFunc(x_2);
    }

    if (opc < 1 || opc > 4)
        flagExit = true;
    else
        printf("\n\t[   x_0   ] [   x_1  ] [   f_0   ] [   f_1  ] [   x_2  ] [   f_2   ] [   Ea   ] [   Er   ]\n");

    do
    {
        if (flagExit == false)
            printf("\t[%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f]\n", x_0, x_1, f_0, f_1, x_2, f_2, errorA, errorR);

        x_0 = x_1;
        f_0 = f_1;

        x_1 = x_2;
        f_1 = f_2;

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));

        if (opc == 1)
            f_2 = primeraFunc(x_2);

        if (opc == 2)
            f_2 = segundoFunc(x_2);

        if (opc == 3)
            f_2 = tercerFunc(x_2);

        if (opc == 4)
            f_2 = cuartaFunc(x_2);

        errorA = fabs(x_2 - x_1);
        errorR = fabs(errorA / x_2);

    } while (errorA > ERROR_TOLE && flagExit != true);

    if (flagExit == true)
        cout << endl
             << "\t[Opcion no valida]" << endl;
    else
    {
        printf("\t[%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f]\n", x_0, x_1, f_0, f_1, x_2, f_2, errorA, errorR);
        printf("\t[LA RAIZ ES: %4.6f]\n\n", x_1);
    }
}

void raizNewton(float valX, int opc){
    float x_0 = valX, x_1 = 0, f_0 = 0, f_1 = 0, errorA = 0, errorR = 0;
    bool flagExit = false;

    if (opc < 1 || opc > 4)
        flagExit = true;
    else
    {
        do
        {
            if (opc == 1)
            {
                cout << "\t\n[PRIMERA FUNCION POR NEWTON: x^2 cos(x) - 2x]\n";
                f_0 = primeraFunc(x_0);
                f_1 = primeraDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 2)
            {

                cout << "\t\n[SEGUNDA FUNCION POR NEWTON: (6 - 2/x^2) (e^2+x /4) + 1]\n";
                f_0 = segundoFunc(x_0);
                f_1 = segundoDer(x_0);
                cout << f_1;

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 3)
            {
                cout << "\t\n[TERCERA FUNCION POR NEWTON: x^3 - 3sen(x^2) + 1]\n";
                f_0 = tercerFunc(x_0);
                f_1 = tercerDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 4)
            {
                cout << "\t\n[CUARTA FUNCION POR NEWTON: x^3 + 6x^2 + 9.4x]\n";
                f_0 = cuartaFunc(x_0);
                f_1 = cuartaDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (f_1 == 0)
            {
                printf("\t[LA DERIVADA EVALUADA EN EL PUNTO %4.2f ES IGUAL A %4.2f, INTENTAR OTRO INTERVALOR]\n", x_0, f_1);
                cin >> x_0;
            }

        } while (f_1 == 0);
    }

    if (0 < opc && opc < 5)
        printf("\n\t[   x_0   ] [   f_x   ] [   f'_x  ] [   x_1  ] [   Ea   ] [   Er   ]\n");

    do
    {
        if (flagExit == false)
            printf("\t[%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f]\n", x_0, f_0, f_1, x_1, errorA, errorR);

        x_0 = x_1;

        if (opc == 1)
        {
            f_0 = primeraFunc(x_0);
            f_1 = primeraDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 2)
        {
            f_0 = segundoFunc(x_0);
            f_1 = segundoDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 3)
        {
            f_0 = tercerFunc(x_0);
            f_1 = tercerDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 4)
        {
            f_0 = cuartaFunc(x_0);
            f_1 = cuartaDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        errorA = fabs(x_1 - x_0);
        errorR = fabs(errorA / x_1);

    } while (errorA > ERROR_TOLE && flagExit != true);

    if (flagExit == true)
        cout << endl
             << "\t[Opcion no valida]" << endl;
    else
    {
        printf("\t[%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f] [%4.6f]\n", x_0, f_0, f_1, x_1, errorA, errorR);
        printf("\t[LA RAIZ ES: %4.6f]\n\n", x_1);
    }
}

int main()
{
    raizSecante(-3, -2, 0);
    raizNewton(-3, 10);
    raizSecante(-3, -2, 1);
    raizNewton(-3, 1);

    raizSecante(-0, -0.5, 2);
    raizNewton(-1, 2);

    raizSecante(-0.6, -0.5, 3);
    raizNewton(-0.6, 3);

    raizSecante(-0.4, -0.3, 4);
    raizNewton(-0.4, 4);

    return 0;
}