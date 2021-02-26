#ifndef _SOLVER_
#define _SOLVER_

#include "SLE.h"

namespace sle
{
    class SLESolver
    {
    public:
        virtual void solve(SLE &equation) = 0;
    };

}    // namespace SLESolver

#endif