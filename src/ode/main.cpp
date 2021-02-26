#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int    iter = argc > 0 ? atoi(argv[1]) : 10;
    double y_0  = 1;
    double y    = y_0;
    double h    = argc > 1 ? atof(argv[2]) : 0.125;

    for(int k = 0; k < iter; k++)
    {
        y = y * (1 - 4 * h + 8 * h * h);

        double x = (k + 1) * h;
        double analytic = exp(-4 * x);
        cout << "x = " << x << " -> analytic = " << analytic << " approx = " << y << " error " << abs(analytic - y) << "\n";
    }

    cout << "problem mit y_0 = " << y_0 << " und h = " << h << " in " << iter << " Schritten: " << y << "\n";

    return 0;
}