#ifndef _ARCHIMEDES_
#define _ARCHIMEDES_

#include "Quadrature.h"

#include <vector>
using namespace std;

namespace quadrature
{
    class Archimedes : public Quadrature
    {
    public:
        using Quadrature::Quadrature;
        double integrate() override;
        void setLevels(int value);

    private:
        double doIntegrate(double i1, double, int cur);
        int levels;

        double function(double x);
    };

}    // namespace quadrature

#endif