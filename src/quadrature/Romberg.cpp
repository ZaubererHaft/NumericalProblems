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
        int                    n = getN();
        vector<vector<double>> Q(n + 1, vector<double>(n + 1));

        for(int i = 0; i < n; i++)
        {
            int    p = pow(2, i);
            double h = (getB() - getA()) / p;
            std::cout << "Trapecoidal Sum with 2^" << i << " = h = " << h << "\n";
            vector<double> y(p + 1);

            // init y
            for(int j = 0; j < y.size(); j++)
            {
                y[j] = getY(j * h);
            }

            TrapecoidalSum sum { getA(), getB(), y };
            Q[i][0] = sum.integrate();
            cout << "sum is " << Q[i][0] << "\n";
            cout << "----\n";
        }

        cout << "n=" << n << "\n";

        for(int k = 1; k <= n; k++)
        {
            for(int i = k; i < n; i++)
            {
                double q = Q[i][k - 1] - Q[i - 1][k - 1];
                double w = (getB() - getA()) / pow(2, i - k);
                double e = (getB() - getA()) / pow(2, i);
                double r = ((w * w) / (e * e)) - 1;

                double val = Q[i][k - 1] + (q / r);
                cout << "Q[" << i << "][" << k << "] = " << val << "\n";
                Q[i][k] = val;
            }
        }

        return Q[n - 1][n - 1];
    }

}    // namespace quadrature