#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct
{
    char code[9];
    double fi, ro;
} TPlane;

// porovnanie podla vzdialenosti od radaru
int compare1(const void*p1, const void*p2)
{
    TPlane *aero1 = (TPlane*)p1;
    TPlane *aero2 = (TPlane*)p2;
    if (aero1->ro == aero2->ro)
    {
        return 0;
    }
    return aero1->ro > aero2->ro ? 1 : -1;
}

int compare2(const void*p1, const void*p2)
{
    TPlane *aero1 = (TPlane*)p1;
    TPlane *aero2 = (TPlane*)p2;
    return strcmp(aero1->code, aero2->code);
}

int main()
{
    int n;
    cin>>n;
    TPlane *planes = new TPlane[n];
    for(int i=0; i<n; i++)
    {
        cin>>planes[i].fi>>planes[i].ro>>planes[i].code;
    }
    int mode;  // rezim usporiadania podla kodu alebo vzdialenosti
    cin>>mode;
    int (*compare)(const void*, const void*);
    if(mode==0)
    {
        compare = &compare1;
    }
    else
    {
        compare = &compare2;
    }
    qsort(planes, n, sizeof(TPlane), compare);
    for(int i=0; i<n; i++)
    {
        cout<<planes[i].code<<" "<<planes[i].fi<<","<<planes[i].ro<<endl;
    }
    return 0;
}
