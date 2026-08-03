#include <stdio.h>
#include <stdlib.h>

int main()
{
    float polozka = 0, zostatok = 100;
    int sucet = 0;

    while (zostatok > 0) {
        scanf ("%f", &polozka);

        if ((zostatok - polozka) >= 0) {
            zostatok -= polozka;
            sucet++;
        }
        else break;
    }
    printf ("%d %.1f", sucet, zostatok);

    return 0;
}
