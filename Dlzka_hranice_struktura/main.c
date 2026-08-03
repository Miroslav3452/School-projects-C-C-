#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} TypBod;

int nacitajBody(TypBod body[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       scanf("%f %f", &body[i].x, &body[i].y);
    }
    return n;
}
float vypocitajDlzku(TypBod bod1, TypBod bod2) {
    float vzdialenost = 0;
    float X, Y;
    X = bod2.x - bod1.x;
    Y = bod2.y - bod1.y;
    vzdialenost = sqrt(pow(X, 2) + pow(Y, 2));
    return vzdialenost;
}
int main()
{
    TypBod suradnice[100];
    int n = nacitajBody(suradnice);
    float dlzkaplota = 0;
    for (int i = 0; i < n - 1; i++) {
        dlzkaplota += vypocitajDlzku(suradnice[i], suradnice[i+1]);
    }
    printf("%.2f", dlzkaplota);

    return 0;
}
