#include "Archimedes.h"

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

namespace quadrature
{
    double Archimedes::function(double x)
    {
        return -pow(x, 2) + 4;
    }

    double Archimedes::integrate()
    {
        double A = 0.5 * getB() * function(0);
        cout << "A on level 0: " << A << "\n";
        return 2 * (A += doIntegrate(0, getB(), 1));
    }

    double Archimedes::doIntegrate(double a, double b, int cur)
    {
        double h = (b - a) / 2.0;
        double g = function((b + a) / 2.0) - (function(a) + function(b)) / 2.0;

        double A = 2.0 * 0.5 * g * h;
        cout << "A on level " << cur << ": " << A << " with a=" << a << ", b=" << b << ", h=" << h << ", g=" << g << "\n";

        if(cur < this->levels - 1)
        {
            cur++;
            return A += doIntegrate(a, a + h, cur) + doIntegrate(a + h, b, cur);
        }
        else
        {
            return A;
        }
    }

    void Archimedes::setLevels(int levels)
    {
        this->levels = levels;
    }

}    // namespace quadrature