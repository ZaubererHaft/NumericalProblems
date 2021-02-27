#ifndef _SIMPSON_SUM_
#define _SIMPSON_SUM_

#include "Quadrature.h"

#include <vector>
using namespace std;

namespace quadrature
{
    class SimpsonSum : public Quadrature
    {
    public:
        using Quadrature::Quadrature;
        double integrate() override;
    };

}    // namespace quadrature

#endif