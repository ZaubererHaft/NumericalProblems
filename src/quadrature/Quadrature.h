#ifndef _QUADRATURE_
#define _QUADRATURE_

#include <vector>
using namespace std;

namespace quadrature
{
    class Quadrature
    {
    public:
        Quadrature(double a, double b, vector<double> &y) : a(a), b(b), y(y)
        {
        }

        virtual double integrate() = 0;

        double getY(int i)
        {
            return this->y[i];
        }
        double getA()
        {
            return a;
        }
        double getB()
        {
            return b;
        }
        double getH()
        {
            return (b - a) / getN();
        }

        int getN()
        {
            //we defined all operations from 0,..,n
            return y.size() - 1;
        }

    private:
        double          a;
        double          b;
        vector<double> &y;
    };

}    // namespace quadrature

#endif