#include <iostream>

using namespace std;

int nsd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return nsd(b,a%b);
}

int main()
{
    int a, b;
    cin>>a;
    do{
        cin>>b;
        if(b!=0){
            a = nsd(a,b);
        }
    }while(b!=0);
    cout<<a;


    return 0;
}
