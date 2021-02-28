#include "ExplicitNewton.h"
#include "ODE.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace ode;

double difference_quotient(double t, double y)
{
    return t * y;
}

int main(int argc, char *argv[])
{
    double delta_t = 1;
    double y0      = 1;
    double t0      = 0;
    int    iter    = 10;

    vector<double> y(iter);
    ExplicitNewton newton { delta_t, y0, t0, y, difference_quotient, iter };
    newton.solve();

    return 0;
}