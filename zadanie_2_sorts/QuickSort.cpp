#include <iostream>

using namespace std;


void QuickSort(int data[],int lavy, int pravy)
{
    if(lavy<pravy)
    {
        int i = lavy, j = pravy, p = data[(lavy + pravy)/2 ];
        do
        {
            while (data[i] < p) i++;
            while (p < data[j]) j--;
            if (i <= j)
            {
                swap(data[i], data[j]);
                i++;
                j--;
            }
        }
        while (i <= j);
        QuickSort(data, lavy, j);
        QuickSort(data, i, pravy);
    }
}
