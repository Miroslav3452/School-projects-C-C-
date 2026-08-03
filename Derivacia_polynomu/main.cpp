#include<iostream>
#include <iomanip>
using namespace std;

typedef struct{
    double x, y;
}Bod_t;

double LagrangePolynome(Bod_t *data, int n, double x){
    double lag, lag_pol = 0;
	int j,i;
	for(j=0; j<n; j++)
	{	lag = 1.0;
		for(i=0; i<n ;i++)
		{   if(i==j) continue;
		    lag *= (x-data[i].x) / (data[j].x-data[i].x) ;
		}
		lag_pol += data[j].y*lag;
	}
	return lag_pol;
}

double derivacia(Bod_t *data, int n, double x0, double h){
    double diferencie[5];
    double der_x = 0; // hodnota vysledku

    for(int i = -2; i <= 2; i++){
       diferencie[i+2] = LagrangePolynome(data, n, x0 + i*h);

    }
    //vypocet delta y
    for(int i = 0; i < 4; i++){
    diferencie[i] = diferencie[i+1] - diferencie[i];

    }

    der_x = (diferencie[1] + diferencie[2])/2;

    //vypocet delta^2
    for(int i = 0; i < 3; i++){
    diferencie[i] = diferencie[i+1] - diferencie[i];
    }
    // vypocet delta^3
    for(int i = 0; i < 2; i++){
    diferencie[i] = diferencie[i+1] - diferencie[i];
    }
    der_x -= (diferencie[0] + diferencie[1])/12;
     return der_x / h;
}



int main()
{
    int n;
    cin>>n;
    Bod_t *body = new Bod_t[n];
    for(int i=0; i<n; i++){
        cin>>body[i].x>>body[i].y;
    }
    double h;
    cin>>h;
    cout<<fixed;
    cout<<setprecision(2);
   // for(double i = body[0].x; i <= body[n-1].x+h; i += h){
     //   cout<<i<<" ";
       // cout<<LagrangePolynome(body, n, i)<<endl;
   // }
    cout<<derivacia(body, n, body[0].x, h)<<" "<<derivacia(body, n, body[n-1].x, h);
    delete[] body;
    return 0;
}
