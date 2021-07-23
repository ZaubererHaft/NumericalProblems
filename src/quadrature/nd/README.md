# Visualizer for 2D hierarchical quadrature including sparse grid
Build with `make`
Call with
* `./hier_quad_2d.out` default call with a level of 3 (means a height of 2^(-3) or 2^3 + 1 intervals) and a sparsity of 1 -> full grid
* `./hier_quad_2d.out <level>` call with variable level
* `./hier_quad_2d.out <level> <sparsity>` call with variable level and sparsity; typical sparsities: 1(full grid) or 2(regular sparse grid)