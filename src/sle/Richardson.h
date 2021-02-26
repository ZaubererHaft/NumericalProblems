#ifndef _RICHARDSON_
#define _RICHARDSON_

#include "IterativeSLESolver.h"
#include "SLE.h"

using namespace std;

namespace sle
{
    class Richardson : public IterativeSLESolver
    {
    public:
        // inherits all constructors
        using IterativeSLESolver::IterativeSLESolver;

    private:
        void doSolve(SLE &equation) override;
    };

}    // namespace sle

#endif