#ifndef _JACOBI_
#define _JACOBI_

#include "IterativeSLESolver.h"
#include "SLE.h"

using namespace std;

namespace sle
{
    class Jacobi : public IterativeSLESolver
    {
    public:
        // inherits all constructors
        using IterativeSLESolver::IterativeSLESolver;

    private:
        void doSolve(SLE &equation) override;
    };

}    // namespace sle

#endif