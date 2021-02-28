#ifndef _EXPL_NEWTON_
#define _EXPL_NEWTON_

#include "ODE.h"

#include <vector>
using namespace std;

namespace ode
{
    class ExplicitNewton : public ODE
    {
    public:
        using ODE::ODE;
        void step(int k) override;
    };

}    // namespace ode

#endif