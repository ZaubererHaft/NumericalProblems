#ifndef _INTERPOLATION_
#define _INTERPOLATION_

#include <vector>
using namespace std;

namespace interpolation
{
    class Interpolation
    {
    public:
        Interpolation(vector<double> &x, vector<double> &y) : x(x), y(y)
        {
        }
        double getX(int i)
        {
            return this->x[i];
        }
        double getY(int i)
        {
            return this->y[i];
        }
        int getCountSupportPoints()
        {
            return this->y.size();
        }

    private:
        vector<double> &x;
        vector<double> &y;
    };

}    // namespace interpolation

#endif