#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    double         val = -1;
    vector<double> x { 0, 1, 2 };
    vector<double> y { 0, 1, 4 };

    vector<vector<double>> p(x.size(), vector<double>(x.size()));

    for(int i = 0; i < x.size(); i++)
    {
        p[i][0] = y[i];
    }

    for(int k = 1; k < x.size(); k++)
    {
        for(int i = 0; i < x.size() - k; i++)
        {
            p[i][k] = p[i][k - 1] + (val - x[i]) / (x[i + k] - x[i]) * (p[i + 1][k - 1] - p[i][k - 1]);
            cout << "p[" << i << "][" << k << "] = " << p[i][k] << "\n";
        }
        cout << "-----\n";
    }

    cout << "Interpolation mit Aitken an x=" << val << " ist " << p[0][p.size() - 1] << "\n";

    return 0;
}