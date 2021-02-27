#include "Quadrature.h"
#include "SimpsonSum.h"
#include "TrapecoidalSum.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace quadrature;

double function(double x)
{
    return pow(x, 4);
}

int main(int argc, char *argv[])
{
    int variant = argc > 1 ? atoi(argv[1]) : 1;

    int    n = 4;
    double a = 0;
    double b = 4;
    double h = (b - a) / n;

    vector<double> y(n + 1);

    // init y with function values of equidistant x values
    for(int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        y[i]     = function(x);
        cout << "x=" << x << " -> f(" << x << ")=" << y[i] << "\n";
    }

    double val = 0.0;
    if(variant == 1)
    {
        cout << "integrate with trapecoidal\n";
        TrapecoidalSum sum { a, b, y };
        val = sum.integrate();
    }
    else
    {
        cout << "integrate with simpson\n";
        SimpsonSum sum { a, b, y };
        val = sum.integrate();
    }

    cout << "Integration von a=" << a << " bis b=" << b << " mit n=" << n << " (-> Stützstellen 0,..," << n << ") ist " << val << "\n";

    return 0;
}
