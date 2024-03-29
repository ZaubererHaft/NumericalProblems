# Collection of fundamental numerical problems

This repository contains a collection of implementations to common numerical problems. Note that the code is not yet optimized or very sophisticated. It is rather a direct implementation of the procedures to control calculations by hand and to have a starting point for further work.

## Content

* Eigenvalues: At the time only with power iteration, but already extended to compute all available eigenvalues; Note that A has to be a symmetric matrix
* interpolation: Global interpolation with Aitken-Neville and Newton; cubical splines on schedule
* Ordinary Differential Equations: Explicit Newton and Heun; Runge-Kutta and Adam-Bashforth scheduled
* Quadrature: Quadrature with Simpson, Trapecoidal sum, Archimedes (only for quadratic functions), and Romberg Extrapolation (should be fine now)
* Quadrature of 2D functions on [0,1]x[0,1] and boundary = 0 with hierarchical bases and sparse grids
* Systems of linear equations: At the time only iterative solvers; LR decomposition and Gauss scheduled
* Roots: Bisection method; scheduled: Regula falsi, Secant, Newton
* A German overview of all introduced algorithms (see explanation_de.pdf)
  
## License
