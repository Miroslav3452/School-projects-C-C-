#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*algoritmus gcd podla vyvojoveho diagramu
    vstup: a,b
    vystup: gcd(a,b)*/
   int a,b;
   scanf("%d %d",&a,&b);

   while (a!=b){
    if (a>b)
        a = a - b;

    else
        b = b - a;

   }
   printf("%d",a);

    return 0;
}

