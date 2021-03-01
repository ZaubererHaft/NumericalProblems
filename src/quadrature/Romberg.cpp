#include "Romberg.h"

#include "TrapecoidalSum.h"
#include "math.h"

#include <iostream>
#include <vector>
using namespace std;

namespace quadrature
{
    double Romberg::integrate()
    {
        int n = getN();

        vector<vector<double>> Q(n, vector<double>(n));

        //steps between points
        int step = n;
        // current amount of points
        double p = 2;
        // current index
        int i = 0;

        while(p <= n + 1)
        {
            std::cout << "Trapecoidal Sum with " << p << " points\n";
            vector<double> y(p);

            // init y
            for(int j = 0; j < y.size(); j++)
            {
                y[j] = getY(j * step);
                cout << "  y[" << j << "] = " << y[j] << "\n";
            }

            TrapecoidalSum sum { getA(), getB(), y };
            double         result = sum.integrate();
            Q[i][0]               = result;

            cout << "Q[" << i << "][0] = " << Q[i][0] << "\n";
            cout << "----\n";

            step /= 2;
            p += p - 1;
            i++;
        }

        //amount of trapecoidal rules
        int iter = i - 1;

        for(int k = 1; k <= iter; k++)
        {
            for(int i = k; i <= iter; i++)
            {
                double q = Q[i][k - 1] - Q[i - 1][k - 1];
                double w = (getB() - getA()) / pow(2, i - k);
                double e = (getB() - getA()) / pow(2, i);
                double r = ((w * w) / (e * e)) - 1;

                double val = Q[i][k - 1] + (q / r);
                Q[i][k] = val;
                cout << "Q[" << i << "][" << k << "] = " << val << "\n";

            }
        }

        return Q[iter][iter];
    }

}    // namespace quadrature