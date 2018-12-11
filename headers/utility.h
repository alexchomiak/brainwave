#ifndef utility_h
#define utility_h 
#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <vector>
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


#endif
