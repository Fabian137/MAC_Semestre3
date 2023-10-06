#include "ProgramaUnoHeader.h"

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