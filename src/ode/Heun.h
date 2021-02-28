#ifndef _HEUN_
#define _HEUN_

#include "ODE.h"

#include <vector>
using namespace std;

namespace ode
{
    class Heun : public ODE
    {
    public:
        using ODE::ODE;
        void step(int k) override;
    };

}    // namespace ode

#endif