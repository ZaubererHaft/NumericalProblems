#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

double function(double x)
{
    return pow(x, 2) - 5;
}

int main(int argc, char *argv[])
{
    int    iter = 100;
    double c    = 1;
    double d    = 4;

    for(int i = 0; i < iter; i++)
    {
        double f_c = function(c);

        double half   = (c + d) / 2.0;
        double f_half = function(half);

        cout << "suche in c=" << c << ", d=" << d << "\n";
        cout << "      f(" << c << ") = " << f_c << ", f(" << half << ")=" << f_half << "\n";

        if(f_c > 0 && f_half >= 0 || f_c < 0 && f_half <= 0)
        {
            c = half;
        }
        else
        {
            d = half;
        }
    }

    return 0;
}