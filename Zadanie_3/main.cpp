#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

typedef struct
{
    int x;
    double y;
} Points_p;

// vypocet hodnoty interpolacneho polynomu v Lagrangeovom tvare v bode x
double LagrangeInterpol(int *data_x, double *data_y, int n, double x)
{
    double lag,lag_pol=0;
    int j,i;
    for(j=0; j<n; j++)
    {
        lag=1.0;
        for(i=0; i<n; i++)
        {
            if(i == j) continue;
            lag *= (x - data_x[i]) / (data_x[j] - data_x[i]) ; // vypocet Lagrangeoveho bazoveho polynomu
        }
        lag_pol += data_y[j] * lag; // vysledna suma bazovych polynomov
    }
    return lag_pol;
}

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
// funkcia na overenie zoradenia pola
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
    const int m = 10;
    // vstupne hodnoty pre vypocet interpolovanych bodov
    int x_inp[] = {1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000};
    double y_inp[] = {0.016, 0.031, 0.048, 0.064, 0.08, 0.099, 0.149, 0.157, 0.184, 0.202};

    cout<<fixed<<setprecision(3);

    for(int i=0; i<m; i++)
    {
        cout<<x_inp[i]<<" "<<y_inp[i]<<endl;
    }
    // nastavenie kroku
    int step = (x_inp[m-1] - x_inp[0]) / (6*m);
    int n = 6*m + 20;
    int f = x_inp[0] - (10*step);


    cout<<endl<<"Interpolated points"<<endl;

    Points_p *lag_data = new Points_p[n];

    for(int i=0; i<n; i++)
    {
        lag_data[i].x = f + (i*step);
        lag_data[i].y = LagrangeInterpol(x_inp, y_inp, m, lag_data[i].x);
        cout<<lag_data[i].x<<" "<<lag_data[i].y<<endl;
    }
    //Overenie presnosti interpolacie pokusnym meranim casov pomocou algoritmu treiedenia Heap sort
    const int test = 5;
    int wide_of_arr[test] = {875000, 1180000, 4852000, 9875000, 11250000};
    for(int i=0; i<test; i++)
    {
        int *arr_Heap = new int[wide_of_arr[i]];

        srand(time(NULL));
        double time_heap = 0;
        for(int j=0; j<3; j++)
        {
            for(int k=0; k < wide_of_arr[i]; k++)
            {
                arr_Heap[i] = rand();

            }

            clock_t t;
            t = clock();
            HeapSort(arr_Heap, wide_of_arr[i]);
            t = clock() - t;
            double tot_time = ((double)t)/CLOCKS_PER_SEC;
            time_heap += tot_time;

            bool check_Heap = Check(arr_Heap, n);

            cout<<i+1<<". meranie HEAPSORT pre velkost pola "<<wide_of_arr[i]<<": "<<tot_time<<" s"<<endl;

            if(check_Heap == false)
            {
                cout<<"ERORR";
                cout<<endl;
            }
            else continue;
        }
        cout<<"Priemerny cas HEAPSORT: "<<time_heap/3<<endl;
    delete[] arr_Heap;
    }
    delete[] lag_data;

    return 0;
}
