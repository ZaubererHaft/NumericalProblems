#ifndef _ROMBERG_
#define _ROMBERG_

#include "Quadrature.h"

#include <vector>
using namespace std;

namespace quadrature
{
    class Romberg : public Quadrature
    {
    public:
        using Quadrature::Quadrature;
        double integrate() override;
    };

}    // namespace quadrature

#endif