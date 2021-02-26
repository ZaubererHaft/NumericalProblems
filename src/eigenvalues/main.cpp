#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

double line_column(vector<double> &x, vector<double> &y)
{
    double s = 0.0;

    for(unsigned long int i = 0; i < x.size(); i++)
    {
        s += x[i] * y[i];
    }

    return s;
}

void matrix_vector(vector<vector<double>> &A, vector<double> &x, vector<double> &w)
{
    for(unsigned long int i = 0; i < x.size(); i++)
    {
        vector<double> &line = A[i];
        w[i]                 = line_column(line, x);
    }
}

double norm(vector<double> &v)
{
    double s = 0.0;

    for(unsigned long int i = 0; i < v.size(); i++)
    {
        s += v[i] * v[i];
    }

    return sqrt(s);
}

void vector_scalar(vector<double> &v, double scalar)
{
    for(unsigned long int i = 0; i < v.size(); i++)
    {
        v[i] *= scalar;
    }
}

void sub(vector<vector<double>> &A, double shift)
{
    for(unsigned long int i = 0; i < A.size(); i++)
    {
        A[i][i] -= shift;
    }
}

void create_matrix(vector<vector<double>> &A, vector<double> &x, vector<double> &w)
{
    for(unsigned long int i = 0; i < x.size(); i++)
    {
        for(unsigned long int j = 0; j < x.size(); j++)
        {
            A[i][j] = x[i] * w[j];
        }
    }
}

void mult(vector<vector<double>> &A, double scalar)
{
    for(unsigned long int i = 0; i < A.size(); i++)
    {
        for(unsigned long int j = 0; j < A.size(); j++)
        {
            A[i][j] *= scalar;
        }
    }
}

void sub_matrices(vector<vector<double>> &A, vector<vector<double>> &B)
{
    for(unsigned long int i = 0; i < A.size(); i++)
    {
        for(unsigned long int j = 0; j < A.size(); j++)
        {
            A[i][j] -= B[i][j];
        }
    }
}

int main(int argc, char *argv[])
{
    //vector<vector<double>> A { { 3, 1 }, { 1, 3 } };
    vector<vector<double>> A { { 1, -1 }, { -1, 1 } };

    vector<double> x { 1, 0 };
    vector<double> w { 0, 0 };

    double lambda = 0;
    int    iter   = argc >= 2 ? atoi(argv[1]) : 2;
    double shift  = argc >= 3 ? atof(argv[2]) : 0;

    sub(A, shift);

    for(unsigned long k = 1; k <= x.size(); k++)
    {
        for(int i = 0; i < iter; i++)
        {
            matrix_vector(A, x, w);
            lambda = line_column(x, w);
            vector_scalar(w, 1.0 / norm(w));

            // swap references
            vector<double> &tmp = x;
            x                   = w;
            w                   = tmp;

            cout << "lambda_" << k << "_hat_" << i << " = " << (lambda) << "\n";
        }

        std::cout << "lambda_" << k << " after " << iter << " iterations is " << (lambda + shift) << "\n";

        double                 normed_eigenvector = norm(x);
        vector<vector<double>> matrix(x.size(), vector<double>(x.size()));

        create_matrix(matrix, x, x);
        mult(matrix, lambda / (normed_eigenvector * normed_eigenvector));
        sub_matrices(A, matrix);
    }

    return 0;
}
