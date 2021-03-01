#include "Archimedes.h"

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

namespace quadrature
{
    double Archimedes::integrate()
    {
        double symm = (getB() + getA()) / 2.0;
        double h    = func(symm);
        double g    = getB() - symm;

        double A = 0.5 * h * g;
        cout << "A on level 0: " << A << "\n";
        return 2 * (A += doIntegrate(symm, getB(), 1));
    }

    double Archimedes::doIntegrate(double a, double b, int cur)
    {
        double h = (b - a) / 2.0;
        double g = func((b + a) / 2.0) - (func(a) + func(b)) / 2.0;

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
}    // namespace quadrature