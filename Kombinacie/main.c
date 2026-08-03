#include <stdio.h>
#include <stdlib.h>

double kombinacie(int a, int b){
    double x = 1, y = 1, z = 1;
    for (int i=1; i<=a; i++){
        x *=i;
    }
    for (int i=1; i<=b; i++){
        y *=i;
    }
    for (int i=1; i<=(a-b); i++){
        z *=i;
    }
    int vysledok = 0;
    vysledok = x / (z * y);
    return vysledok;
}


int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    printf("%.0lf",kombinacie(n,k));
    return 0;
}
