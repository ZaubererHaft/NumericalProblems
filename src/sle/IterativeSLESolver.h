#ifndef _ITERATIVE_SOLVER_
#define _ITERATIVE_SOLVER_

#include "SLE.h"
#include "SLESolver.h"

namespace sle
{
    class IterativeSLESolver : public SLESolver
    {
    public:
        explicit IterativeSLESolver(unsigned int iterations = 10);
        int  getIterations();
        void solve(SLE &equation) override;

    private:
        unsigned int iterations;
        virtual void doSolve(SLE &equation) = 0;

    protected:
        vector<double> y;
    };

}    // namespace sle

#endif