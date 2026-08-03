#include <iostream>
#include <cstring>
using namespace std;

void vyhladaj(const char word[],const char text[], int poz[], int &pocet)
{
    int i=0, j=0, m, n;
    pocet = 0;
    m = strlen(word); // dåžka vzoru
    n = strlen(text); // dåžka textu
    while ( i<m && j<n )
    {
        if (word[i] != text[j])
        {
            j = j-i; // index textu
            i = -1; // index vzoru
        }
        i++;
        j++;
        if (i==m)
        {
            poz[pocet] = j - m;
            pocet++;
            i = 0;
        }

    }
}

int main()
{
    //string veta, slovo;
    //getline(cin, veta);
    //cin>>slovo;
    char veta[1000];
    char slovo[16];
    int pozicia[5];
    int pocet = 0;

    cin.getline(veta, 999);
    cin>>slovo;
    vyhladaj(slovo, veta, pozicia, pocet);

    if(pocet == 0)
    {
        cout<<"-1";
    }
    for(int i = 0; i < pocet; i++)
    {
        cout<<pozicia[i]<<" ";
    }

    return 0;
}
