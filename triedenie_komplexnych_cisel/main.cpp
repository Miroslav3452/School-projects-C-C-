#include <iostream>
#include <math.h>
using namespace std;
typedef struct
{
    double re, im;
} Complex_t;

double porovnaj(Complex_t a, Complex_t b)
{

    double da = sqrt(a.re*a.re + a.im*a.im);
    double db = sqrt(b.re*b.re + b.im*b.im);
    return da - db;
}
void zotried(Complex_t *A,int pocet)
{
    int m = pocet;
    while (m /= 2) // krok pri triedeni
    {
        for (int d=pocet-m, i=0; i<d; i++)
            for (int j=i; (j>=0)&& (porovnaj(A[j],A[j+m]) > 0); j-=m )
                swap(A[j], A[j+m]);

    }
}
int main()
{
    int n;
    cin>>n;
    Complex_t *cisla = new Complex_t[n];

    for(int i=0; i<n; i++)
    {
        cin>>cisla[i].re;
        cin>>cisla[i].im;
    }

    zotried(cisla, n);

    // vypis zotriedene pola
    for(int i=0; i<n; i++)
    {
        cout<<cisla[i].re;
        if(cisla[i].im >= 0)
        {
            cout<<'+'<<cisla[i].im<<'i'<<endl;
        }
        else
            cout<<cisla[i].im<<'i';
    }

    return 0;
}
