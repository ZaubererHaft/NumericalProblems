#include "Heun.h"

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

namespace ode
{
    void Heun::step(int k)
    {
        double t   = getT0() + k * getDeltaT();
        double t_2 = getT0() + (k + 1) * getDeltaT();

        double grad = getGradient(t, getY(k));
        double val  = getGradient(t_2, getY(k) + getDeltaT() * grad);
        double val2 = getY(k) + 0.5 * getDeltaT() * (grad + val);

        setY(k + 1, val2);
        cout << "y[" << k + 1 << "]=" << getY(k + 1) << "\n";
    }

}    // namespace ode