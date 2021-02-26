#include "GaussSeidel.h"

using namespace std;

namespace sle
{
    void GaussSeidel::doSolve(SLE &equation)
    {
        int n = equation.getSize();

        for(int k = 1; k <= n; k++)
        {
            double s1 = 0.0;
            for(int j = 1; j <= n; j++)
            {
                // remember: new approximation values are already stored in x[0:k-1]
                s1 += equation.getA(k - 1, j - 1) * equation.getX(j - 1);
            }

            double r = equation.getB(k - 1) - s1;
            double y = (1.0 / equation.getA(k - 1, k - 1)) * r;
            equation.setX(k - 1, equation.getX(k - 1) + y);
        }
    }

}    // namespace sle
