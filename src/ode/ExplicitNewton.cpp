#include "ExplicitNewton.h"

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

namespace ode
{
    void ExplicitNewton::step(int k)
    {
        double t = getT0() + k * getDeltaT();
        setY(k + 1, getY(k) + getDeltaT() * getGradient(t, getY(k)));

        cout << "y[" << k + 1 << "]=" << getY(k + 1) << "\n";
    }

}    // namespace ode