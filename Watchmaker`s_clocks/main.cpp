#include <iostream>

using namespace std;

// Funkcia, ktorá vypoèíta gcd (najväèší spoloèný delite¾) dvoch celých èísel a a b
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Funkcia, ktorá vypoèíta lcm (najmenší spoloèný násobok) dvoch celých èísel a a b
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n;
    cin>>n;
    int clocks[n];
    for (int i = 0; i < n; i++)
    {
        cin>>clocks[i];
    }
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m = lcm(m, clocks[i]);
    }
    int t = 0;
    t += m;
    if (t <= 10000)
    {
        cout<<t<<" minutes"<<endl;
    }
    else
    {
        cout<<"It will be a long time."<<endl;
    }
    /*  while (t <= 10000) {
          int cnt = 0;
          for (int i = 0; i < n; i++) {
              if (t % clocks[i] == 0) {
                  cnt++;
              }
          }

          if (cnt == n) {
              std::cout << t << " minutes" << std::endl;
              return 0;
          }

      }*/

    return 0;
}
