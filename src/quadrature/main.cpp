#include "Quadrature.h"
#include "TrapecoidalSum.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace quadrature;

double function(double x)
{
    return -pow(x, 2) + 4;    //+ 4 * pow(x, 2) + 1;
}

int main(int argc, char *argv[])
{
    int    n = 8;
    double a = -2;
    double b = 2;
    double h = (b - a) / n;

    vector<double> y(n + 1);

    //init y with function values of equidistant x values
    for(int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        y[i]     = function(x);
        cout << "x=" << x << " -> f(" << x << ")=" << y[i] << "\n";
    }

    TrapecoidalSum sum { a, b, y };
    double         val = sum.integrate();
    cout << "Integration von a=" << a << " bis b=" << b << " mit n=" << n << " (-> Stützstellen 0,..," << n << ") ist " << val << "\n";

    return 0;
}
