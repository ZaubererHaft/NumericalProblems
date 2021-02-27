#include "IterativeSLESolver.h"

#include <iostream>
#include <stdlib.h>

namespace sle
{
    void print(SLE &equation)
    {
        for(int i = 0; i < equation.getSize(); i++)
        {
            std::cout << "[" << equation.getX(i) << "]";

            if(i < equation.getSize() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    IterativeSLESolver::IterativeSLESolver(unsigned int iterations) : iterations(iterations)
    {
    }

    void IterativeSLESolver::solve(SLE &equation)
    {
        y = vector<double>(equation.getSize(), 0.0);

        for(int i = 0; i < this->getIterations(); i++)
        {
            doSolve(equation);
            cout << "x after at k=" << i << ":\n";
            print(equation);
        }
    }

    int IterativeSLESolver::getIterations()
    {
        return this->iterations;
    }

}    // namespace sle
