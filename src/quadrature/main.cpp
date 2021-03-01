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
    // return -pow(x + 4, 2) + 1;
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

void execute(Quadrature *quadrature)
{
    double val = quadrature->integrate();
    cout << "Integration from a=" << quadrature->getA() << " to b=" << quadrature->getB() << " with n=" << quadrature->getN()
         << " (-> max. nodes 0,..," << quadrature->getN() << ") with h=" << quadrature->getH() << " is " << val << "\n";
}

int main(int argc, char *argv[])
{
    int variant = argc > 1 ? atoi(argv[1]) : 1;
    int n       = argc > 2 ? atoi(argv[2]) : 2;

    double a = -2;
    double b = 2;
    double h = (b - a) / n;

    vector<double> y(n + 1);
    initDefault(y, n, a, h);

    if(variant == 1)
    {
        cout << "integrate with trapecoidal sum\n";
        TrapecoidalSum sum { a, b, y };
        execute(&sum);
    }
    else if(variant == 2)
    {
        cout << "integrate with archimedes; (total levels = n = " << n << ")\n";
        vector<double> y(0);
        Archimedes     sum { a, b, y, n, function };
        execute(&sum);
    }
    else if(variant == 3)
    {
        double log2OfN = log(n) / log(2);
        if(round(log2OfN) - log2OfN >= 0.001)
        {
            throw std::invalid_argument("romberg quadrature needs n that is power of 2");
        }

        cout << "integrate with romberg; 0,..,n is maximum count of points within a trapecoidal sum\n";
        Romberg sum { a, b, y };
        execute(&sum);
    }
    else
    {
        if(n % 2 != 0)
            throw std::invalid_argument("simpson sum only with odd count of support points (0,1,..,n)");

        cout << "integrate with simpson\n";
        SimpsonSum sum { a, b, y };
        execute(&sum);
    }

    return 0;
}
