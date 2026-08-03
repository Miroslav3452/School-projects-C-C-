#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
typedef struct{
    double x,y;
}Bod_t;

typedef enum{
    LIN,LOG,MOC,EXP
}TypKrivky_t;

typedef struct{
    double a,b;
    TypKrivky_t typ;
}Krivka_t;


Krivka_t MinSq(Bod_t *points, int n, TypKrivky_t tk){
    Krivka_t krivka;
    double sx=0, sy=0, sxx=0, sxy=0;
    double slx=0, slxx=0, slxy=0;
    double sly=0, sxly=0;
    double slxly=0;
    for(int i=0; i<n; i++){
        sx += points[i].x;
        slx += log(points[i].x);
        sy += points[i].y;
        sly += log(points[i].y);
        sxx += points[i].x * points[i].x;
        sxy += points[i].x * points[i].y;
        slxx += log(points[i].x) * log(points[i].x);
        slxy += log(points[i].x) * points[i].y;
        sxly += points[i].x * log(points[i].y);
        slxly += log(points[i].x) * log(points[i].y);

    }
    switch(tk){
    case LIN:
        krivka.a = (n * sxy - sx * sy) / (n * sxx - sx * sx);
        krivka.b = (sy - krivka.a * sx) / n;
        break;
    case LOG:
        krivka.a = (n * slxy - slx * sy) / (n * slxx - slx * slx);
        krivka.b = (sy - krivka.a * slx) / n;
        break;
    case EXP:
        krivka.a = (n * sxly - sx * sly) / (n * sxx - sx * sx);
        krivka.b = (sly - krivka.a * sx) / n;
        krivka.b = exp(krivka.b);
        break;
    case MOC:
        krivka.a = (n * slxly - slx * sly) / (n * slxx - slx * slx);
        krivka.b = (sly - krivka.a * slx) / n;
        krivka.b = exp(krivka.b);
        break;
    default:
        break;
    }
    return krivka;
}


int main()
{
    int n;
    cin>>n;
    char typ[4];
    cin>>typ;
    Bod_t *body = new Bod_t[n];
    for(int i=0; i<n; i++){
        cin>>body[i].x>>body[i].y;
    }
    TypKrivky_t typKrivky;
    if(strcmp(typ,"LIN")==0) typKrivky = LIN;
    if(strcmp(typ,"LOG")==0) typKrivky = LOG;
    if(strcmp(typ,"MOC")==0) typKrivky = MOC;
    if(strcmp(typ,"EXP")==0) typKrivky = EXP;

    Krivka_t p;
    p = MinSq(body, n, typKrivky);
    cout<<fixed;
    cout<<setprecision(2);
    cout<<p.a<<" "<<p.b;

    return 0;
}
