#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double function(double x1, double x2)
{
    return 16 * x1 * (x1 - 1) * x2 * (x2 - 1);
}

void discretize(double *grid, int size, double step)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i * size + j] = function(i * step, j * step);
        }
    }
}

void printGrid(double *grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            double val = grid[i * size + j];
         
            if(fabs(val) > 0.00000001)
            {
                printf("%.4f ", val);
            }
            else
            {
                printf("       ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void computeSurpluses1(double *surpluses, double *grid, int size, int a, int b, int step, int sparsity)
{
    int half = (a + b) / 2;

    for (int l = 0; l < size; l += step)
    {
        surpluses[half + l * size] = grid[half + l * size] - 0.5 * (grid[a + l * size] + grid[b + l * size]);
    }

    if(b - a > 2)
    {
        computeSurpluses1(surpluses, grid, size, a, half, step * sparsity, sparsity);
        computeSurpluses1(surpluses, grid, size, half, b, step * sparsity, sparsity);
    }
}

void computeSurpluses2(double *surpluses, double *grid, int size, int a, int b, int step, int sparsity)
{
    int half = (a + b) / 2;

    for (int l = 0; l < size; l += step) 
    {
        surpluses[half * size + l] = grid[half * size + l] - 0.5 * (grid[a * size + l] + grid[b * size + l]);
    }

    if(b - a > 2)
    {
        computeSurpluses2(surpluses, grid, size, a, half, step * sparsity, sparsity);
        computeSurpluses2(surpluses, grid, size, half, b, step * sparsity, sparsity);
    }
}


double *computeSurpluses(double *surpluses1, double *surpluses2, double *grid, int size, int a, int b, int sparsity)
{
    computeSurpluses1(surpluses1, grid, size, a, b, 1, sparsity);
    computeSurpluses2(surpluses2, surpluses1, size, a, b, 1, sparsity);
    return surpluses2;
}

void initHeights1(double *grid, int size, double value, int a, int b)
{
    int half = (a + b) / 2;
    for (int i = 0; i < size; i++)
    {
        if (i > 0 && i < size -1)
        {
            grid[half + i * size] = value;
        }
        
    }


    if(b - a > 2)
    {
        initHeights1(grid, size, value / 2.0, a, half);
        initHeights1(grid, size, value / 2.0, half, b);
    }
}

void initHeights2(double *grid, int size, double value, int a, int b)
{
    int half = (a + b) / 2;
    for (int i = 0; i < size; i++)
    {
        grid[half * size + i] *= value;        
    }


    if(b - a > 2)
    {
        initHeights2(grid, size, value / 2.0, a, half);
        initHeights2(grid, size, value / 2.0, half, b);
    }
}

void initHeights(double *grid, int size, double value, int a, int b)
{
    initHeights1(&grid[0], size, 0.5, a, b);
    initHeights2(&grid[0], size, 0.5, a, b);
}


void computeVolumes(double *volumes, double *surpluses, double *heights, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            volumes[i * size + j] = surpluses[i * size + j] * heights[i * size + j];
        }
    }
}

double sumUp(double *grid, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += grid[i * size + j];
        }
    }
    return sum;
}

#define DEBUG 1

int main(int argc, char* argv[])
{
    int maxLevel = 3;
    if(argc > 1)
        maxLevel = atoi(argv[1]);

    int intervals = (2 << (maxLevel - 1)) + 1;
    double step = pow(2, -maxLevel);


    int sparsity = 1; //1 -> full grid; 2-> sparse grid; 4-> even sparser grid
    if(argc > 2)
        sparsity = atoi(argv[2]);

    double grid[intervals * intervals];
    double surpluses1[intervals * intervals];
    double surpluses2[intervals * intervals];
    double heights[intervals * intervals];
    
    double volumes[intervals * intervals];

    for (int i = 0; i < intervals; i++)
    {
        for (int j = 0; j < intervals; j++)
        {
            surpluses1[i * intervals + j] = 0.0;
            surpluses2[i * intervals + j] = 0.0;
            heights[i * intervals + j] = 0.0;
        }
    }
    

    discretize(&grid[0], intervals, step);
    if (DEBUG)
    {
        printf("discretized function on [0,1]x[0,1]:\n");
        printGrid(&grid[0], intervals);
    }
    
    double *surpluses = computeSurpluses(&surpluses1[0], &surpluses2[0], &grid[0], intervals, 0, intervals - 1, sparsity);
    if (DEBUG)
    {
        printf("hierarchization on [0,1]x[0,1]:\n");
        printGrid(&surpluses[0], intervals);
    }

    initHeights(&heights[0], intervals, 0.5, 0, intervals - 1);
    computeVolumes(&volumes[0], &surpluses[0], &heights[0], intervals);
    if (DEBUG)
    {
        printf("volumes on [0,1]x[0,1]:\n");
        printGrid(&volumes[0], intervals);
    }

    double result = sumUp(&volumes[0], intervals);
    printf("volume is %f\n", result);


    return 0;
}