#include <iostream>
#include <cstdlib>
#include <time.h>
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;


int main()
{
    int n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            n = j * 1000000;
            int *arrguick = new int[n];
            int *arrheap = new int[n];

            srand(time(0));
            for(int k=0; k < n; k++)
            {
                *(arrguick+j) = rand();
                *(arrheap+j) = *(arrguick+j);
            }

            clock_t t;
            t = clock();
            QuickSort(arrguick, 0, n-1);
            t = clock() - t;
            double cas_celkom = ((double)t)/CLOCKS_PER_SEC;
            //    for(int i = 0; i < n; i++){
            //        cout<<arrguick[i]<<" ";
            //    }

            cout<<i+1<<". meranie guicksort pre velkost pola "<<n<<": "<<cas_celkom<<" sekund"<<endl;

            t = clock();
            HeapSort(arrheap, n);
            t = clock() - t;
            cas_celkom = ((double)t)/CLOCKS_PER_SEC;
            //    for(int i = 0; i < n; i++){
            //        cout<<arrheap[i]<<" ";
            //    }
            cout<<i+1<<". meranie heapsort pre velkost pola "<<n<<": "<<cas_celkom<<" sekund"<<endl;
            cout<<endl;
            delete[]arrguick;
            delete[]arrheap;
        }
    }

    return 0;
}
