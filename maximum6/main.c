#include <stdio.h>
#include <stdlib.h>

int max3(int a, int b, int c) {
    int m;
    if (a > b) {
        m = a;
    }
    else {
        m = b;
    }
    if (c > m) {
        m = c;
    }
    return m;
}

int max2(int a, int b) {
    int m;
    if (a > b) {
        m = a;
    }
    else {
        m = b;
    }
    return m;
}


int main() {
    int x1, x2, x3, x4, x5, x6;
    scanf("%d %d %d %d %d %d",&x1, &x2, &x3, &x4, &x5, &x6);
    int m1 = max3(x1, x2, x3);
    int m2 = max3(x4, x5, x6);
    printf ("%d", max2(m1, m2));
    return 0;
}
