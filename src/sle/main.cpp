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
        cout << "[" << equation.getX(i) << "]";

        if(i < equation.getSize() - 1)
        {
            cout << ", ";
        }
    }
    cout << "\n";
}

void execute(IterativeSLESolver *solver, SLE &equation)
{
    solver->solve(equation);
    cout << "Solution:\n";
    print(equation);
}

int main(int argc, char *argv[])
{
    vector<vector<double>> A { { 2, -1, 1 }, { -1, 2, -1 }, { 1, -1, -2 } };
    vector<double>         x { 0, 0, 0 };
    vector<double>         b { -1, -1, 0 };

    int          variant = argc > 1 ? atoi(argv[1]) : 0;
    unsigned int iter    = (unsigned int)argc > 2 ? atoi(argv[2]) : 10;
    SLE          equation { A, x, b };

    if(variant == 1)
    {
        cout << "using Jacobi iteration \n";
        Jacobi jacobi { iter };
        execute(&jacobi, equation);
    }
    else if(variant == 2)
    {
        cout << "using Gauss-Seidel iteration \n";
        GaussSeidel gauss { iter };
        execute(&gauss, equation);
    }
    else
    {
        cout << "using Richardson iteration \n";
        Richardson richardson { iter };
        execute(&richardson, equation);
    }

    return 0;
}