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
        Archimedes(double a, double b, vector<double> y, int levels, double (*func)(double x)) : Quadrature(a, b, y), levels(levels), func(func)
        {
        }

        double integrate() override;

    private:
        double doIntegrate(double a, double b, int cur);
        int    levels;

        double function(double x);
        double (*func)(double x);
    };

}    // namespace quadrature

#endif