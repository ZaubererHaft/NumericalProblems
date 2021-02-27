#include "TrapecoidalSum.h"

#include <vector>
using namespace std;

namespace quadrature
{
    double TrapecoidalSum::integrate()
    {
        double sum = 0;
        for(int k = 0; k <= getN(); k++)
        {
            if(k <= 0 || k >= getN())
            {
                sum += 0.5 * getY(k);
            }
            else
            {
                sum += getY(k);
            }
        }
        sum *= getH();
        return sum;
    }

}    // namespace quadrature