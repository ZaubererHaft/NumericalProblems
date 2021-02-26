.PHONY : all
all:
	g++ -g -std=c++17  -Isrc/sle src/sle/SLE.cpp src/sle/Richardson.cpp src/sle/Jacobi.cpp src/sle/GaussSeidel.cpp src/sle/IterativeSLESolver.cpp src/main.cpp -Wall -Wpedantic -o lgs.out