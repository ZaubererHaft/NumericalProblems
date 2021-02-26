#include "SLE.h"

#include <stdexcept>
#include <vector>

using namespace std;

namespace sle
{
    SLE::SLE(vector<vector<double>> &A, vector<double> &x, vector<double> &b) : A(A), x(x), b(b)
    {
        // ToDo: Sanity check for vectors
    }

    double SLE::getA(int i, int j)
    {
        return this->A[i][j];
    }

    double SLE::getB(int i)
    {
        return this->b[i];
    }

    void SLE::setX(int i, double value)
    {
        this->x[i] = value;
    }

    double SLE::getX(int i)
    {
        return this->x[i];
    }

    int SLE::getSize()
    {
        return this->x.size();
    }

}    // namespace sle