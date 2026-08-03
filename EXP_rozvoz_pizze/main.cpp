#include <iostream>

using namespace std;

void InsertSort(int *data, int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        j = i;
        temp = data[j];
        while((j > 0) && (data[j-1] > temp))
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = temp;
    }
}

int main()
{
    int N;
    cin>>N;
    int p = 0;
    int pizza = 6;
    int i = 0;
    int *ci = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin>>ci[i];
    }
    InsertSort(ci, N);

    while (i < N)
    {
        p++;
        for(int j = i; j < N; j++)
        {
            pizza -= ci[j];
            while(ci[j] - 6 > 0)
            {
                p++;
                ci[j] -= 6;
            }
            if(pizza < 0)
            {
                p++;
                pizza = 6;
                j--;
            }
            else
            {
                i = j + 1;
            }
        }
    }

    cout<<p;
    delete[] ci;
    return 0;
}
