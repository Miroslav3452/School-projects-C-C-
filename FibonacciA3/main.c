/*  Name: Fibonacci - d'Ocagne identity
    version: 1.0
    date: 23.11.2022
    created by Miroslav Vasarab STUMTF*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double fibonacci(int n)                      // funkcia pre vypocet n-teho fibonacciho cisla
{
    double f1 = 1, f2 = 1, dalsiecislo;
    if (n <= 2 && n > 0)
    {
        dalsiecislo = 1;
    }
    else
    {
        dalsiecislo = f1 + f2;
        for(int i = 3; i < n; i++)
        {
            f1 = f2;
            f2 = dalsiecislo;
            dalsiecislo = f1 + f2;
        }
    }
    return dalsiecislo;
}

double porovnaj (int m, int n)              // funkcia pre overenie d'Ocagneho identity
{
    bool ocagne = true;
    int a = (fibonacci(m) * fibonacci(n + 1)) - (fibonacci(m + 1) * fibonacci(n));
    int b = (pow(-1, n) * fibonacci(m - n));
    if ( a == b)
    {
        ocagne = true;
    }
    else
    {
        ocagne = false;
    }
    return ocagne;
}

int main()
{
    int m, n;
    printf("Zadaj hodnoty m-teho a n-teho Fibonacciho cisla:");
    scanf("%d %d", &m, &n);
    if (m - n < 10)
    {
        printf("Hodnota m musi byt aspon o 10 vacsia ako n.");
    }
    else
    {
        for(int i = m; i < m + 10; i++)             // cyklus pre 100 nasobne overenie d'Ocagneho identity
        {
            for(int j = n; j < n + 10; j++)
            {
                if (porovnaj(i, j) != true)
                {
                    printf("!!!d'Ocagne-ho identita neplati!!!");
                    return 0;
                }
            }
        }
        printf("d'Ocagne-ho identita pre Fibonacciho cisla plati.");
    }
    return 0;
}
