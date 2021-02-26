#ifndef _GAUSS_SEIDEL_
#define _GAUSS_SEIDEL_

#include "IterativeSLESolver.h"
#include "SLE.h"

using namespace std;

namespace sle
{
    class GaussSeidel : public IterativeSLESolver
    {
    public:
        // inherits all constructors
        using IterativeSLESolver::IterativeSLESolver;

    private:
        void doSolve(SLE &equation) override;
    };

}    // namespace sle

#endif