#ifndef _NEWTON_
#define _NEWTON_

#include "Interpolation.h"

#include <vector>
using namespace std;

namespace interpolation
{
    class Newton : public Interpolation
    {
    public:
        using Interpolation::Interpolation;
        double interpolate(double curr_x) override;
    };

}    // namespace interpolation

#endif