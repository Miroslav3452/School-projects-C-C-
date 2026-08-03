#include <iostream>
#include <math.h>
using namespace std;

typedef struct
{
    int x,y;
} Bod_t;

double porovnaj(Bod_t a, Bod_t b)
{

    double da = sqrt( a.x*a.x + a.y*a.y);
    double db = sqrt( b.x*b.x + b.y*b.y);
    return da - db;
}

int hladaj(Bod_t *pole, int lavy, int pravy, Bod_t x)
{

    if(lavy>pravy)
        return -1;
    else
    {
        int stred =(lavy+pravy)/2;
        if(porovnaj(pole[stred], x) == 0)
            return stred;
        else
        {
            if (porovnaj(x, pole[stred]) < 0 )
                return hladaj(pole,lavy,stred-1,x);
            else
                return hladaj(pole,stred+1,pravy,x);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    Bod_t *body = new Bod_t[n];

    for(int i=0; i<n; i++)
    {
        cin>>body[i].x>>body[i].y;
    }

    Bod_t Q;
    cin>>Q.x>>Q.y;

    int index = hladaj(body, 0, n-1, Q);
    if(index<0)
        cout<<'X';
    else
        cout<<index;

    return 0;
}
