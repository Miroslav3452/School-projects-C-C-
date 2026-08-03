#include <iostream>

using namespace std;



void heapfy(int data[], int N, int i)
{
    int naj = i;
    int lavy = 2*i + 1;
    int pravy = 2*i + 2;

    if(lavy < N && data[lavy] > data[naj])
    {
        naj = lavy;
    }
    if(pravy < N && data[pravy] > data[naj])
    {
        naj = pravy;
    }
    if(naj != i)
    {
        swap(data[i], data[naj]);
        heapfy(data, N, naj);
    }
}

void HeapSort(int data[], int N)
{
    for(int i = N/2 - 1; i >= 0; i--)
    {
        heapfy(data, N, i);
    }
    for(int i = N - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        heapfy(data, i, 0);
    }
}
