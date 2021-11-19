#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void stats(const double arr[], uint32_t n, double &mean) // Option 1
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    mean = sum / n;
}

void stats(const double arr[], uint32_t n, double *mean) // Option 2
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    *mean = sum / n;
}

int main()
{
    double mean, vairance;
    double x[] = {1, 2, 3, 4};

    stats(x, 4, mean); // Option 1
    stats(x, 4, &mean); // Option 2
}