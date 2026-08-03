#include <stdio.h>
#include <stdlib.h>

char diagonaly(int X[][100], int a){
    int hlavna = 0, vedlajsia = 0;
    for (int i = 0; i < a; i++){
        hlavna += X[i][i];
    }

    for (int i = 0; i < a; i++){
        vedlajsia += X[i][a - 1 - i];
    }

    if (hlavna > vedlajsia){
        return 'H';
    } else if (hlavna < vedlajsia){
        return 'V';
    } else {
        return 'E';
    }
}

int main()
{
    int n;
    int M[100][100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &M[i][j]);
        }
    }
    printf ("%c", diagonaly(M, n));
    return 0;
}
