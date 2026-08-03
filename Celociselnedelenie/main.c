#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int delenec, delitel;
    int podiel = 0, zvysok = 0;
    bool zapornypodiel = false, zapornyzvysok = false;

    scanf("%d%d", &delenec, &delitel);
    if (delitel == 0) {
        printf ("!Delenie nulou!");
    }
    else {
        if ((delenec < 0) && (delitel < 0)) {
            delenec *= -1;
            delitel *= -1;
            zapornyzvysok = true;
        }
        else {
            if (delenec < 0) {
                delenec *= -1;
                zapornypodiel = true;
                zapornyzvysok = true;
            }
            if (delitel < 0) {
                delitel *= -1;
                zapornypodiel = true;
            }
        }

        while (delenec - delitel >= 0) {
            podiel ++;
            delenec -= delitel;
        }
        if (zapornyzvysok) {
            zvysok = -delenec;
        }
        else {
        zvysok = delenec;
        }
        if (zapornypodiel) {
            podiel *= -1;
        }

        printf ("celociselny podiel je: %d\n", podiel);
        printf ("zvysok po deleni je: %d", zvysok);
    }

    return 0;
}
