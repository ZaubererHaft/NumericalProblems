#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

double function(double x)
{
    return -pow(x, 2) + 4; //+ 4 * pow(x, 2) + 1;
}

int main(int argc, char *argv[])
{
    double a = -2;
    double b = 2;
    int    n = 8;
    double h = (b - a) / n;

    vector<double> y(n + 1);

    for(int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        y[i]     = function(x);
        cout << "x=" << x << " -> f(" << x << ")=" << y[i] << "\n";
    }

    double sum = 0;
    for(int k = 0; k <= n; k++)
    {
        if(k <= 0 || k >= n)
        {
            sum += 0.5 * y[k];
        }
        else
        {
            sum += y[k];
        }
    }
    sum *= h;

    cout << "Integration von a=" << a << " bis b=" << b << " mit n=" << n << " (-> Stützstellen 0,..," << n << ") ist " << sum << "\n";

    return 0;
}