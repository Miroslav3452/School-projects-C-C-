#include <stdio.h>
#include <stdlib.h>

void nasobky(int n, int a)  {
    for ( int i=0; i<n; i++) {
        printf("%d ",a*(i+1));
    }
}

int main()
{
    //Vytvorte funkciu nasobky(n,a), v ktorej vypíšte prvých n násobkov èísla a.

    int n,a;
    scanf("%d %d",&a, &n);
    nasobky(n, a);
    return 0;
}
