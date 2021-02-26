#include "GaussSeidel.h"
#include "Jacobi.h"
#include "Richardson.h"
#include "SLE.h"
#include "SLESolver.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace sle;

void print(sle::SLE &equation)
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

void execute(sle::IterativeSLESolver *solver, sle::SLE &equation)
{
    solver->solve(equation);
    std::cout << "Solution:\n";
    print(equation);
}

int main(int argc, char *argv[])
{
    vector<std::vector<double>> A { { 2, -1, 1 }, { -1, 2, -1 }, { 1, -1, -2 } };
    vector<double>              x { 0, 0, 0 };
    vector<double>              b { -1, -1, 0 };

    int          variant = argc > 1 ? atoi(argv[1]) : 0;
    unsigned int iter    = (unsigned int)argc > 2 ? atoi(argv[2]) : 10;
    sle::SLE     equation { A, x, b };

    if(variant == 1)
    {
        cout << "using Jacobi iteration \n";
        sle::Jacobi jacobi { iter };
        execute(&jacobi, equation);
    }
    else if(variant == 2)
    {
        cout << "using Gauss-Seidel iteration \n";
        sle::GaussSeidel gauss { iter };
        execute(&gauss, equation);
    }
    else
    {
        cout << "using Richardson iteration \n";
        sle::Richardson richardson { iter };
        execute(&richardson, equation);
    }

    return 0;
}