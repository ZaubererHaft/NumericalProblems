#ifndef _AITKEN_
#define _AITKEN_

#include "Interpolation.h"

#include <vector>
using namespace std;

namespace interpolation
{
    class Aitken : public Interpolation
    {
    public:
        using Interpolation::Interpolation;
        double interpolate(double curr_x);
    };

}    // namespace interpolation

#endif