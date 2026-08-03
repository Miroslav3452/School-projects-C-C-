#include <iostream>
#include <iomanip>
using namespace std;

double prevod(double N, int z, int d, double vysledok = 0){
    if(N == 0){
        return vysledok;
    }

    int cislo = N % z;
    vysledok = vysledok * 10 + cislo;
    return prevod(N / z, z, vysledok);
}
int main()
{
    double n;
    int z, d;

    cin>>n>>z>>d;

    cout<<setprecision(d);
    cout<<fixed;

    cout<<prevod(N, z, d);

    return 0;
}
