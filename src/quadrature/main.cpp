#include "Archimedes.h"
#include "Quadrature.h"
#include "Romberg.h"
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
    //return -pow(x + 4, 2) + 1;
    return -pow(x, 2) + 4;
}

void initDefault(vector<double> &y, int n, double a, double h)
{
    // init y with function values of equidistant x values
    for(int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        y[i]     = function(x);
        cout << "x=" << x << " -> f(" << x << ")=" << y[i] << "\n";
    }
}

void initRomberg(vector<double> &y, int n, double a, double b)
{
    double min_h = (b - a) / pow(2, n);

    // init y with function values of equidistant x values, but here with the minimal distance later used in romberg
    for(int i = 0; i <= y.size(); i++)
    {
        double x = a + i * min_h;
        y[i]     = function(x);
        cout << "x=" << x << " -> f(" << x << ")=" << y[i] << "\n";
    }
}

int main(int argc, char *argv[])
{
    int variant = argc > 1 ? atoi(argv[1]) : 1;

    int    n = 2;
    double a = -2;
    double b = 2;
    double h = (b - a) / n;

    double val = 0.0;
    if(variant != 3 && variant != 2)
    {
        vector<double> y(n + 1);
        initDefault(y, n, a, h);

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
    }
    else if(variant == 2)
    {
        cout << "integrate with archimedes\n";
        vector<double> y(0);
        int            levels = 5;
        Archimedes sum { a, b, y, levels, function };

        val = sum.integrate();
    }
    else
    {
        cout << "integrate with romberg\n";
        double         max_y = pow(2, n);
        vector<double> y(max_y);

        initRomberg(y, n, a, b);
        Romberg sum { a, b, y };
        val = sum.integrate();
    }

    cout << "Integration von a=" << a << " bis b=" << b << " mit n=" << n << " (-> Stützstellen 0,..," << n << ") ist " << val << "\n";

    return 0;
}
