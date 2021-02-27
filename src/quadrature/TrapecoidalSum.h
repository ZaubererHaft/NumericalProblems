#ifndef _TRAPECOIDAL_SUM_
#define _TRAPECOIDAL_SUM_

#include "Quadrature.h"

#include <vector>
using namespace std;

namespace quadrature
{
    class TrapecoidalSum : public Quadrature
    {
    public:
        using Quadrature::Quadrature;
        double integrate() override;
    };

}    // namespace quadrature

#endif