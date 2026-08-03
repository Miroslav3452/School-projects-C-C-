#include<iostream>

using namespace std;

void sucinLU(int **XL, int **XU, int **XA, int n)
{
    int i,j,k;
    //XA =XL*XU
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            XA[i][j] = 0;
            for(k=0; k < min(i+1, j+1); k++)
            {
                XA[i][j] += XL[i][k]*XU[k][j-k];
            }
        }
    }
}

void vypis(int **XA, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<XA[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n,i,j;
    cin>>n;
    int **L=new int*[n];
    int **U=new int*[n];
    int **A=new int*[n];

    // alokacia matice A
    for (i=0; i < n; i++)
    {
        A[i] = new int[n];
    }
    // alokacie matice L
    for (i=0; i < n; i++)
    {
        L[i] = new int[i+1];
    }
    // alokacie matice U
    for (i=0; i < n; i++)
    {
        U[i] = new int[n-i];
    }

    // nacitanie matice L
    for (i=0; i < n; i++)
    {
        for (j=0; j < i+1; j++)
            cin>>L[i][j];
    }

    // nacitanie matice U, napr: 2 4 3 5 4 6 5 7 6 9
    //2 4 3 5                       2 4 3 5
    //  4 6 5   => skutocny tvar    4 6 5
    //    7 6                       7 6
    //      9                       9
    for (i=0; i < n; i++)
    {
        for (j=0; j < n-i; j++)
            cin>>U[i][j];
    }

    sucinLU(L,U,A,n);
    vypis(A,n);
}
