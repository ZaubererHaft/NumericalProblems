#ifndef _SLE_
#define _SLE_

#include <vector>
using namespace std;

namespace sle
{
    class SLE
    {
    public:
        SLE(vector<vector<double>> &A, vector<double> &x, vector<double> &b);
        double getA(int i, int j);
        double getB(int i);

        void setX(int i, double value);
        double getX(int i);

        int getSize();

    private:
        vector<vector<double>> &A;
        vector<double> &x;
        vector<double> &b;
    };

}    // namespace sle

#endif