#include "Aitken.h"

#include <iostream>

using namespace std;

namespace interpolation
{
    double Aitken::interpolate(double val)
    {
        vector<vector<double>> p(this->getCountSupportPoints(), vector<double>(this->getCountSupportPoints()));

        for(int i = 0; i < this->getCountSupportPoints(); i++)
        {
            p[i][0] = getY(i);
        }

        for(int k = 1; k < this->getCountSupportPoints(); k++)
        {
            for(int i = 0; i < this->getCountSupportPoints() - k; i++)
            {
                p[i][k] = p[i][k - 1] + (val - getX(i)) / (getX(i + k) - getX(i)) * (p[i + 1][k - 1] - p[i][k - 1]);
                cout << "p[" << i << "][" << k << "] = " << p[i][k] << "\n";
            }
            cout << "-----\n";
        }

        cout << "Interpolation mit Aitken an x=" << val << " ist " << p[0][p.size() - 1] << "\n";
        return p[0][p.size() - 1];
    }

}    // namespace interpolation
