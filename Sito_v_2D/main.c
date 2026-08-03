#include <stdio.h>
#include <stdlib.h>

const double pi = 3.14;

typedef struct{
    double x ,y;
} Bod_t;

typedef struct{
    Bod_t stred;
    double polomer;
} Kruh_t;

double obvod(double polomer){
    return 2 * pi * polomer;
}

int main()
{
    int n;
    double o;
    scanf("%d", &n);

    Kruh_t kruhy[50];
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &kruhy[i].stred.x, &kruhy[i].stred.y, &kruhy[i].polomer);
    }
    scanf("%lf", &o);

    for(int i = 0; i < n; i++){
        if (obvod(kruhy[i].polomer) > o) {
            printf("[%.2lf,%.2lf]->%.2lf\n", kruhy[i].stred.x, kruhy[i].stred.y, kruhy[i].polomer);
        }
    }
    return 0;
}
