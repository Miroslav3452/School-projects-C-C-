#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
    double x, y;
}TBod;

double LagrangeInterpol(TBod *data, int n,double x)
{  double lag,lag_pol=0;
	int j,i;
	for(j=0;j<n;j++)
	{	lag=1.0;
		for(i=0;i<n;i++)
		{   if(i==j) continue;
		    lag*=(x-data[i].x) / (data[j].x-data[i].x) ;
		}
		lag_pol+= data[j].y*lag;
	}
	return lag_pol;
}

double integralLich(TBod *pole, int n){
    double vysledok = 0;
    double a, b, h;
    a = pole[0].x;
    b = pole[2].x;
    h = (b - a) / n;

    for(double i = a+h; i < b-h; i += h){
        vysledok += LagrangeInterpol(pole, 3, i);
    }
    vysledok += (LagrangeInterpol(pole, 3, a) + LagrangeInterpol(pole, 3, b)) /  2;

    return vysledok * h;
}
int main()
{
    TBod bod[3];

    for(int i=0; i<3; i++){
        cin>>bod[i].x>>bod[i].y;
    }

    int n;
    cin>>n;

    cout<<fixed;
    cout<<setprecision(3);

    cout<<integralLich(bod, n);
    return 0;
}
