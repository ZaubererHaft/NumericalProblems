#ifndef _ODE_
#define _ODE_

#include <vector>
using namespace std;

namespace ode
{
    class ODE
    {
    public:
        ODE(double delta_t, double y0, double t0, vector<double> &y, double (*gradient)(double t, double y), int iterations) :
            delta_t(delta_t), y0(y0), t0(t0), y(y), gradient(gradient), iterations(iterations)
        {
        }

        void solve()
        {
            y[0] = y0;

            for(int i = 0; i < iterations; i++)
            {
                step(i);
            }
        }

        virtual void step(int k) = 0;

        int getIterations()
        {
            return iterations;
        }
        void setY(int i, double val)
        {
            y[i] = val;
        }
        double getY(int i)
        {
            return this->y[i];
        }
        double getGradient(double t, double y)
        {
            return gradient(t, y);
        }
        double getT0()
        {
            return t0;
        }
        double getY0()
        {
            return y0;
        }
        double getDeltaT()
        {
            return delta_t;
        }

    private:
        double          delta_t, y0, t0;
        vector<double> &y;
        double (*gradient)(double t, double y);
        int iterations;
    };

}    // namespace ode

#endif