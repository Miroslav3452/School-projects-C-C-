#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    int citatel, menovatel;
}TZlomok;

int nsd(int a, int b){
    if (b == 0){
        return a;
    }
    return nsd(b, a%b);
}

void zjednodus(TZlomok &zlomok){
    int delitel = nsd(abs(zlomok.citatel), zlomok.menovatel);
    zlomok.citatel /= delitel;
    zlomok.menovatel /= delitel;
}

int main()
{
    TZlomok zlomok;
    TZlomok pole[100];
    int n = 0;
    do{
        cin>>zlomok.citatel>>zlomok.menovatel;

        zjednodus(zlomok);

        if (zlomok.citatel != 0 && abs(zlomok.citatel) < zlomok.menovatel){
            pole[n].citatel = zlomok.citatel;
            pole[n].menovatel = zlomok.menovatel;
            n++;
        }
    } while (zlomok.citatel != 0);

    for (int i = 0; i < n; i++){
        cout<<pole[i].citatel<<"/"<<pole[i].menovatel<<" ";
    }

    return 0;
}
