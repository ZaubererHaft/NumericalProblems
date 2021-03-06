#include "TrapecoidalSum.h"

#include <iostream>
#include <vector>
using namespace std;

namespace quadrature
{
    double TrapecoidalSum::integrate()
    {
        double sum = 0;
        for(int k = 0; k <= getN(); k++)
        {
            double val = 0.0;
            if(k <= 0 || k >= getN())
            {
                val = 0.5 * getY(k);
            }
            else
            {
                val = getY(k);
            }

            std::cout << "k=" << k << " -> val=" << val << "\n";
            sum += val;
        }
        sum *= getH();
        return sum;
    }

}    // namespace quadrature