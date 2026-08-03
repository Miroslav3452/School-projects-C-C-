#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double real, imag;
} komplexne;

komplexne nasobenie(komplexne a, komplexne b){
    komplexne vystup;
    vystup.real = a.real * b.real - a.imag * b.imag;
    vystup.imag = a.real * b.imag + a.imag * b.real;
    return vystup;
}

komplexne delenie(komplexne a, komplexne b) {
    komplexne vystup;
    vystup.real = (a.real * b.real + a.imag * b.imag) / (pow(b.real,2) + pow(b.imag,2));
    vystup.imag = (a.imag * b.real - a.real * b.imag) / (pow(b.real,2) + pow(b.imag,2));
    return vystup;
}
int main()
{
    int n;
    char op;
    komplexne vysledok, dalsie;
    scanf("%d %c %lf %lf", &n, &op, &vysledok.real, &vysledok.imag);


    for(int i = 1; i < n; i++) {
        scanf("%lf %lf", &dalsie.real, &dalsie.imag);
        switch (op) {
            case '+':
                vysledok.real = vysledok.real + dalsie.real;
                vysledok.imag = vysledok.imag + dalsie.imag;
                break;
            case '-':
                vysledok.real = vysledok.real - dalsie.real;
                vysledok.imag = vysledok.imag - dalsie.imag;
                break;
            case '*':
                vysledok = nasobenie(vysledok, dalsie);
                break;
            case '/':
                vysledok = delenie(vysledok, dalsie);
                break;
        }
    }
    printf("%.2lf", vysledok.real);
    if (vysledok.imag >= 0){
        printf("+i");
    } else {
        printf("-i");
    }
    printf("%.2lf\n", fabs(vysledok.imag));
    return 0;
}
