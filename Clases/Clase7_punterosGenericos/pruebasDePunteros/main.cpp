#include <iostream>

int main() {
    int *ptI = new int;
    *ptI = 10;

    double *ptD = new double;
    *ptD = 3.14;
    *ptI = *ptD;

    return 0;
}