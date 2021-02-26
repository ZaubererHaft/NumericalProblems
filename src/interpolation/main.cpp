#include "Aitken.h"
#include "Interpolation.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace interpolation;

int main(int argc, char *argv[])
{
    double         val = 0.5;
    vector<double> x { 0, 1, 2, 1.5 };
    vector<double> y { 3, 0, 1, 0 };

    Aitken interpol { x, y };
    double point = interpol.interpolate(val);

    cout << "interpolation at x=" << val << " is " << point << "\n";

    return 0;
}