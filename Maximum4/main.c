#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,max;
    int maxab, maxcd;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (a>b){
        maxab=a;
    }
    else {
        maxab=b;
    }
    if (c>d) {
        maxcd=c;
    }
    else {
        maxcd=d;
    }
    if (maxab>maxcd) {
        max=maxab;
    }
    else {
        max=maxcd;
    }
    printf("%d",max);

    return 0;
}
