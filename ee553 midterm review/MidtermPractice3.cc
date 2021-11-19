#include <iostream>
#include <algorithm>

using namespace std;

class world
{
private:
    uint32_t n;
    world *map;

public:
    world(uint32_t size) : n(size), map(new int32_t[size * size] {//According to order of declarations above
        for(uint32_t i = 0; i < n * n; i++)
            map[i] = 0;
    }
    ~world() {
        delete[] map;
    }
    world(const world &orig) :  n(orig.n), map(new int32_t[orig.n*orig.n]) {
        for (uint32_t i = 0; i < n * n; i++)
            map[i] = orig.map[i];
    }
    /*
    world& operator =(const world &orig) :{ //Old way
        if (this != &orig) //comparing address of this object to original address
        {
            delete[] map;
            n = orig.n;
            map = new int32_t[n * n];
            for (uint32_t i = 0; i < n * n; i++)
                map[i] = orig.map[i];
        }
        return *this;
    }*/
    
    world& operator =(world copy) { //New way - copy and swap
        n = copy.n;
        swap(map, copy.map);
        return *this;
    }
};

void f()
{
    world w(100);
}

int main()
{
    for (int i = 0; i < 10000; i++)
        f();
    world a(100);
    world b(20);
    a = b;
    return 0;
}