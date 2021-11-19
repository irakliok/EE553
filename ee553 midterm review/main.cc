#include "circularbuffer.hh"
using namespace std;

int main()
{
    circularbuffer b(32);
    b.enqueue(3);
    for (int i = 0; i < 10; i++)
        b.enqueue(i);

    while (!b.isEmpty())
    {
        cout << b.dequeue() << ' ';
    }
}