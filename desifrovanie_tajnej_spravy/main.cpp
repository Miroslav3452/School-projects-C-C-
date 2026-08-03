#include <iostream>
#include <string.h>

using namespace std;
#define N 26

void sifruj_posuvna(char *x, char *y, int k){
    int i;
    for(i=0; i<strlen(x); i++){
        y[i] = (x[i] - 'a' + k) % N + 'a';
    }
    y[i] = 0;
}
void desifruj_posuvna(char *y, char *x, int k){
    int i;
    int z;
    for(i=0; i<strlen(y); i++){
        z = y[i] - 'a' - k;
        if(z<0){
            x[i] = (z + N) + 'a';
        }else{
            x[i] = z + 'a';
        }
    }
    x[i] = 0;
}

void desifruj_vigenere(char *y, char *x, char *k){
    int cipher_len = strlen(y);
    int key_len = strlen(k);
    int i, znak, kluc;
    for(i=0; i<cipher_len; i++){
        znak = y[i] - 'a';
        kluc = k[i%key_len] - 'a';
        if(znak - kluc < 0){
            x[i] = znak - kluc + N + 'a';
        }else {
            x[i] = znak - kluc + 'a';
        }
    }
    x[i] = 0;
}

int main()
{
    char cipher[500];
    char key[500];
    char plain[500];
   // cin>>cipher>>key;
    cin>>cipher>>key;
    desifruj_vigenere(cipher, plain, key);
    cout<<plain;

    //char znak = key[0];
    //int k = znak - 'a';
    //sifruj_posuvna(plain, cipher, k);
    //desifruj_posuvna(cipher, plain, k);
    //cout<<plain;
    return 0;
}
