#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

void QuickSort(int data[],int left, int right) // funkcia QuickSort
{
    if(left < right)
    {
        int i = left, j = right;
        int pivot = data[(left + right)/2 ];
        do
        {
            while (data[i] < pivot) i++;
            while (pivot < data[j]) j--;
            if (i <= j)
            {
                swap(data[i], data[j]);
                i++;
                j--;
            }
        }
        while (i <= j);
        QuickSort(data, left, j);
        QuickSort(data, i, right);
    }
}

void Heapify(int data[], int N, int i)
{
    int maximum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < N && data[left] > data[maximum])
    {
        maximum = left;
    }
    if(right < N && data[right] > data[maximum])
    {
        maximum = right;
    }
    if(maximum != i)
    {
        swap(data[i], data[maximum]);
        Heapify(data, N, maximum);
    }
}

void HeapSort(int data[], int N)
{
    for(int i = N/2 - 1; i >= 0; i--)
    {
        Heapify(data, N, i);
    }
    for(int i = N - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        Heapify(data, i, 0);
    }
}

bool Check(int data[], int n)
{
    for(int i = 0; i < n - 2; i++)
    {
        if(data[i+1] < data[i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    for(int j = 1; j <= 10; j++)
    {
        n = j * 1000000;
        int *arr_Quick = new int[n];
        int *arr_Heap = new int[n];

        srand(time(NULL));
        double timeT_Quick = 0, timeT_Heap = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int k=0; k < n; k++)
            {
                *(arr_Quick+j) = rand();
                *(arr_Heap+j) = *(arr_Quick+j);
            }
            clock_t t;
            t = clock();
            QuickSort(arr_Quick, 0, n-1);
            t = clock() - t;
            double tot_time = ((double)t)/CLOCKS_PER_SEC;
            timeT_Quick += tot_time;

            bool check_Quick = Check(arr_Quick, n);

            cout<<i+1<<". meranie QUICKSORT pre velkost pola "<<n<<": "<<tot_time<<" s"<<endl;
            if(check_Quick)
            {
                cout<<"Zoradenie OK";
            }
            else
            {
                cout<<"ERORR";
            }
            cout<<endl;
            t = clock();
            HeapSort(arr_Heap, n);
            t = clock() - t;
            tot_time = ((double)t)/CLOCKS_PER_SEC;
            timeT_Heap += tot_time;

            bool check_Heap = Check(arr_Heap, n);

            cout<<i+1<<". meranie HEAPSORT pre velkost pola "<<n<<": "<<tot_time<<" s"<<endl;
            if(check_Heap)
            {
                cout<<"Zoradenie OK";
            }
            else
            {
                cout<<"ERORR";
            }
            cout<<endl;
        }
        cout<<"Priemerny cas QUICKSORT: "<<timeT_Quick/3<<endl;
        cout<<"Priemerny cas HEAPSORT: "<<timeT_Heap/3<<endl;
        cout<<endl;
        delete []arr_Quick;
        delete []arr_Heap;
    }

    return 0;
}
