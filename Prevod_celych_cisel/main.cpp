#include <iostream>

using namespace std;

void prevod(int N, int z){
    if(N == 0){
        return;
    }
    prevod(N / z, z);
    int cislo = N % z;
    cout<<cislo;
}



int main()
{
    int N, z;
    cin>>N>>z;

    prevod(N, z);

    return 0;
}
