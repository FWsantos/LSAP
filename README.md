# LSAP - (Linear Sum Assigment Problem)

Hungarian Algorithm for Linear Sum Assignment problems, implemented in C++. The algorithms in this part follow the algorithms presented in [chapter 4][2] of [Bukard][1].

<!-- Linearization of the Quadratic Assignment Problem for Linear Assignment Problem. -->

## This repository has:
- Preprocessing phase to determine a feasible dual solution and a partial primal solution
- Hungarian algorithm $O(n^4)$
- :exclamation: Hungarian algorithm $O(n^3)$
- :exclamation: Hungarian algorithm $O(n^3)$ using shortest path

**_NOTE:_**
Items marked with :exclamation: have bugs or are not running correctly for larger instances.

<!-- ## Repository structure -->

## How to build
This is a CMAKE project.

Example of how to build and run the project:

    git clone git@github.com:FWsantos/LSAP.git
    cd LSAP
    mkdir build
    cd build
    cmake -DBUILD_DIR=custom_build ..
    make
    ./LSAP



## How to test

The LSAP.h methods that are "Hungarian algorithms" all have the same parameters: 

    std::vector<std::vector<int>> C //matrix,
    int n //matrix size

The Tests class has examples for each Hungarian implementation.
main.cpp has the Tests class method calls, uncomment to test the function of your choice.

If you want to change the instance, the input files are in the file_inputs folder. Currently each test function tests only one instance of the problem. the path needs to be defined inline in Tests.h as the value of the `const std::string file_path`.


<!-- - Linearization of the Quadratic Assignment Problem for Linear Assignment Problem -->

<!-- ## The Linear Assignment Problem -->

<!-- ## References -->
[1]: https://epubs.siam.org/doi/book/10.1137/1.9781611972238
[2]: https://epubs.siam.org/doi/10.1137/1.9781611972238.ch4

