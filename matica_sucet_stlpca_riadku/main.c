#include <stdio.h>
#include <stdlib.h>
void nacitajMaticu(int X[20][20], int r, int s) {
    for(int i=0; i<r;i++) {
        for(int j=0; j<s; j++) {
            scanf("%d", &X[i][j]);
        }
    }
}
int scitajRiadok(int M[20][20], int stlpce, int m) {
    int suma = 0;
    for (int i=0;i<stlpce;i++)
        suma+= M[m][i];

    return suma;
}
int scitajStlpec(int M[20][20], int riadky, int n) {
    int suma = 0;
    for (int j=0;j<riadky;j++)
        suma+= M[j][n];

    return suma;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int A[20][20];
    nacitajMaticu(A, m, n);
    int i, j;
    scanf("%d %d", &i, &j);
    int sr, ss;
    sr = scitajRiadok(A, n, i);
    ss = scitajStlpec(A, m, j);
    printf("%d %d", sr, ss);
    return 0;
}
