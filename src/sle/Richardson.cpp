#include "Richardson.h"

using namespace std;

namespace sle
{
    void Richardson::doSolve(SLE &equation)
    {
        int n = equation.getSize();
        for(int k = 1; k <= n; k++)
        {
            double r = 0.0;
            for(int j = 1; j <= n; j++)
            {
                r += equation.getA(k - 1, j - 1) * equation.getX(j - 1);
            }
            this->y[k - 1] = equation.getB(k - 1) - r;
        }

        for(int k = 1; k <= n; k++)
        {
            double val = equation.getX(k - 1) + this->y[k - 1];
            equation.setX(k - 1, val);
        }
    }

}    // namespace sle
