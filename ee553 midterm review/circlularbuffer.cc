#include "circularbuffer.hh"
#include <utility>

using namespace std;

circularbuffer::circularbuffer(uint32_t cap)
    : p(new uint32_t[cap]), capacity(cap), head(0), tail(0) {}
circularbuffer::~circularbuffer() { delete[] p; }
circularbuffer::circularbuffer(const circularbuffer &orig)
    : p(new uint32_t[orig.capacity]), capacity(orig.capacity), head(orig.head), tail(orig.tail)
{
    if (head < tail)
    {
        for (uint32_t i = head; i < tail; i++)
            p[i] = orig.p[i];
    }
    else if (head == tail)
    {
        //copy nothing, the queue is empty
    }
    else
    {
        for (uint32_t i = head; i < capacity; i++)
            p[i] = orig.p[i];
        for (uint32_t i = 0; i < tail; i++)
            p[i] = orig.p[i];
    }
}

void circularbuffer::grow()
{
    capacity *= 2;
}

void circularbuffer::enqueue(uint32_t v)
{
    p[tail] = v;
    tail = (tail + 1) & (capacity - 1);
    if (tail >= capacity)
        tail = 0;
    if (tail == head)
    {
        grow();
    }
}

#if (0) //Old way of = operator
circularbuffer &circularbuffer::operator=(const circularbuffer &orig)
{
    if (this != &orig)
        delete[] p;
    capacity = orig.capacity;
    head = orig.head;
    tail = orig.tail;
    p = new uint32_t(capacity);
    for (int i = 0; i < capacity; i++)
    {
        p[i] = orig.p[i];
    }
    return *this;
}
#endif

circularbuffer &circularbuffer::operator=(circularbuffer copy)
{ //New way
    capacity = copy.capacity;
    head = copy.head;
    tail = copy.tail;
    swap(p, copy.p);
    return *this;
}

circularbuffer::circularbuffer(circularbuffer &&orig)
    : p(orig.p), capacity(orig.capacity), head(orig.head), tail(orig.tail)
{
    orig.p = nullptr;
}
