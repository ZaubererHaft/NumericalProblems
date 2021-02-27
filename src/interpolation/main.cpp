#include "Aitken.h"
#include "Interpolation.h"
#include "Newton.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace interpolation;

int main(int argc, char *argv[])
{
    vector<double> x { 6, 4, 2, 3 };
    vector<double> y { 2, 2, 3, 2 };

    int    variant = argc > 1 ? atoi(argv[1]) : 0;
    double val     = argc > 2 ? atof(argv[2]) : 0;

    if(variant == 0)
    {
        Newton interpol { x, y };
        interpol.interpolate(val);
    }
    else
    {
        Aitken interpol { x, y };
        interpol.interpolate(val);
    }

    return 0;
}