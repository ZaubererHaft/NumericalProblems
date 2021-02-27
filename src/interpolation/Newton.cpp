#include "Newton.h"

#include <iostream>

using namespace std;

namespace interpolation
{
    double Newton::interpolate(double val)
    {
        vector<vector<double>> c(this->getCountSupportPoints(), vector<double>(this->getCountSupportPoints()));

        for(int i = 0; i < this->getCountSupportPoints(); i++)
        {
            c[i][0] = getY(i);
        }

        for(int k = 1; k < this->getCountSupportPoints(); k++)
        {
            for(int i = 0; i < this->getCountSupportPoints() - k; i++)
            {
                c[i][k] = (c[i + 1][k - 1] - c[i][k - 1]) / (getX(i + k) - getX(i));
                cout << "c[" << i << "][" << k << "] = " << c[i][k] << "\n";
            }
            cout << "-----\n";
        }

        double eval = 0.0;
        for(int i = 0; i < c.size(); i++)
        {
            double prod = 1.0;
            for(int j = 0; j < i; j++)
            {
                prod *= (val - getX(j));
            }
            eval += c[0][i] * prod;
        }

        cout << "Interpolation mit Newton an x=" << val << " ist " << eval << "\n";
        return eval;
    }

}    // namespace interpolation
