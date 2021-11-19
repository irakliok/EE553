#include <iostream>

using namespace std;

//bubble sort - 
void bubbleSort(int x[], uint32_t n)
{
    double temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
}


int main()
{
    int x[12] = {2, 3, 4, 5, 3, 6, 7, 3, 9, 1, 8, 0};

    for (int i = 0; i < 12; i++)
        cout << x[i] << ' ';
    cout << '\n';
    bubbleSort(x, 12);
    for (int i = 0; i < 12; i++)
        cout << x[i] << ' ';
    return 0;
}
