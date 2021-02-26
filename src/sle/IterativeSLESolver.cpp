#include "IterativeSLESolver.h"

namespace sle
{
    IterativeSLESolver::IterativeSLESolver(unsigned int iterations) : iterations(iterations)
    {
    }

    void IterativeSLESolver::solve(SLE &equation)
    {
        y = vector<double>(equation.getSize(), 0.0);

        for(int i = 0; i < this->getIterations(); i++)
        {
            doSolve(equation);
        }
    }

    int IterativeSLESolver::getIterations()
    {
        return this->iterations;
    }

}    // namespace sle
