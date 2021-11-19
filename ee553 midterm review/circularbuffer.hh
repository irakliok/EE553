#pragma once;
#ifndef CIRCULARBUFFER_HH_
#define CIRCULARBUFFER_HH_ //Same

#include <iostream>

class circularbuffer
{
private:
    uint32_t *p;
    uint32_t capacity, head, tail;

public:
    circularbuffer(uint32_t cap);               // constructor
    ~circularbuffer() {}                        // destructor
    circularbuffer(const circularbuffer &orig); // copy constructor
    circularbuffer(circularbuffer &&orig);      // move constructor

#if (0)                                         //Old way of = operator
    circularbuffer &operator=(const circularbuffer &orig); // = operator
#endif

    circularbuffer &operator=(circularbuffer copy);
    void grow();
    void enqueue(uint32_t v);
    uint32_t dequeue();

    bool isEmpty() const;
}