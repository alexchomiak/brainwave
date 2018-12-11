#include <stdio.h>
#include "headers/matrix.h"
#include "headers/utility.h"



using namespace std;
int main() {
    printf("Testing!!!\n");
    Matrix<double> a(10,10);

    for(int i = 0; i < a.numRows(); i++) {
        for(int j = 0; j < a.numCols(); j++) {
            a.at(i,j) = fRand(0,1);
        }
    }
    
    Matrix<double> b = a;
    (a*b).printMatrix(6);
    a.clear();
    return 0;

}
