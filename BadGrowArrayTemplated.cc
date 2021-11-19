#include <iostream>
#include <utility>
//#include <memory.h>

using namespace std;

class BadGrowArray
{
private:
    int *data;
    uint32_t size;

public:
    //Constructor
    BadGrowArray() : size(0), data(nullptr) {}
    //Destructor
    ~BadGrowArray() { delete[] data; }
    //copy constructor
    BadGrowArray(const BadGrowArray &orig) : size(orig.size), data(new int[size])
    {
        //memcpy(data, orig.data, size * sizeof(int)); //Memory library
        for (uint32_t i = 0; i < size; i++)
            data[i] = orig.data[i];
    }
    //Operator =
    BadGrowArray &operator=(BadGrowArray copy)
    {
        size = copy.size;
        swap(data, copy.data);
        return *this;
    }
    //operator <<
    friend ostream &operator<<(ostream &s, const BadGrowArray &array)
    {
        for (uint32_t i = 0; i < array.size; i++)
            s << array.data[i] << ' ';
        return s;
    }
    //Move constructor
    BadGrowArray(BadGrowArray &&orig) : size(orig.size), data(orig.data)
    {
        orig.data = nullptr;
    }

    void addEnd(uint32_t val)
    {
        const int *old = data;
        data = new int[size];
        for (uint32_t i = 0; i < size - 1; size++)
            data[i] = old[i];
        data[size] = val;
        size++;
        delete[] old;
    }
};

int main()
{
    BadGrowArray a;
    a.addEnd(3);
    a.addEnd(1);
    a.addEnd(4);
}