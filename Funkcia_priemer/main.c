#include <stdio.h>
#include <stdlib.h>


float priemer(int poleCisel[], int pocet){
    float y, x;
    for (int i = 0; i < pocet; i++){
        x += poleCisel[i];
    }
    y = x/pocet;
    return y;
}

int main()
{
   int n;
   scanf("%d", &n);
   int poleCisel[n];

   for (int i = 0; i < n; i++){
        scanf("%d", &poleCisel[i]);
   }
   printf("%.2f", priemer(poleCisel, n));

    return 0;
}
