#include <stdio.h>
#include <stdlib.h>

int nacitaj_udaje(int n){
    int histogram[10] = {0};
    int cislo;

    for (int i = 0; i < n; i++){
        scanf("%d", &cislo);
        for (int j = 1; j <= 10; j++){
            if (cislo == j){
                histogram[j-1]++;
            }
        }
    }
    int naj_cislo = 0;
    int najviac = 0;
    for (int i = 0; i < 10; i++){
        if (histogram[i] > naj_cislo){
            naj_cislo = histogram[i];
            najviac = i + 1;
        }
    }
    return najviac;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", nacitaj_udaje(n));
    return 0;
}
