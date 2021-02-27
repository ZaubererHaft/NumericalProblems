#include "SimpsonSum.h"

#include <iostream>
#include <vector>
using namespace std;

namespace quadrature
{
    double SimpsonSum::integrate()
    {
        double sum = 0;
        for(int k = 0; k <= getN(); k++)
        {
            double val = 0.0;

            if(k <= 0 || k >= getN())
            {
                val = getY(k);
            }
            else
            {
                if(k % 2 == 0)
                {
                    val = 2 * getY(k);
                }
                else
                {
                    val = 4 * getY(k);
                }
            }

            std::cout << "k=" << k << " -> val=" << val << "\n";
            sum += val;
        }

        sum *= (getH() / 3.0);
        return sum;
    }

}    // namespace quadrature