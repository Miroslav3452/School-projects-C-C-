#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double poly_value(double *poly, int n, double x0){
    double result = poly[n];

    for(int i=n-1; i>=0; i--){
        result = result*x0 + poly[i];
    }
    return result;
}



double newton(double *poly, double *dpoly, int stup, double x0, double epsilon = 0.001){
    if( fabs(poly_value(poly,stup,x0)) < fabs(epsilon)){
        return x0;
    }
    return newton(poly, dpoly, stup, x0 - poly_value(poly, stup, x0)/poly_value(dpoly, stup-1, x0));

}


void vypis(double d){
    cout<<fixed;
    cout<<setprecision(3);
    cout<<d;
}
int main()
{
    int stupen;
    cin>>stupen;
    stupen++;

    double *polynom = new double[stupen];
    double *polynom_d = new double[stupen];

    for(int i = stupen-1; i >= 0; i--){
        cin>>polynom[i];
    }
    double x0;
    cin>>x0;

    polynom_d[stupen-1]=0;
    for(int i = stupen-2; i >= 0; i--){
        polynom_d[i] = polynom[i+1]*(i+1);
    }

    vypis(newton(polynom, polynom_d, stupen, x0));
    return 0;
}
