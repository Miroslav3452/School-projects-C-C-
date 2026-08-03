#include <iostream>
#include <string.h>

using namespace std;

#define N 26

void sifruj(char *vstup, char *vystup, int k){
    vystup[0] = (vstup[0] + k) % N;
    for(int i = 1, i < strlen(vstup), i++){

    }
}

int main()
{
    int k;

    char plaintext[100];
    char ciphertext[100];

    cin>>k;
    cin>>plaintext;



    return 0;
}
