#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // M_PI

using namespace std;

class Shape
{ // ABSTRACT CLASS
public:
    virtual double area() const = 0; // pure virtual
    virtual double volume() const = 0;
};

class ParallelPiped : public Shape
{
private:
    double L, W, H;

public:
    ParallelPiped(double L, double W, double H) : L(L), W(W), H(H) {}
    double area() const override
    {
    }
};

class CircularShape : public Shape
{
public:
    double r;
    CircularShape(double r) : r(r) {}
};

class Sphere : public Shape
{
private:
    const double r;

public:
    Sphere(double r) : r(r) {}
    double area() const override
    {
        return 4 * M_PI * r * r;
    }
    double volume() const override
    {
        return (4.0 / 3) * M_PI * r * r * r;
    }
};

#if (0)
class Cylinder : public Shape
{
private:
    double r, h;

public:
};
#endif

int main()
{
    Shape *s; // s is pointer to Shape
    // Shape shape; // cannot instantiate Shape because it is an ABSTRACT CLASS
    // Sphere sphere(2.0); // cannnot instantiate because abstact memer area is not overriden
    vector<const Shape *> shapes;
    shapes.push_back(new Sphere(2.0));
    shapes.push_back(new Cylinder(3.0, 4.5));
    shapes.push_back(ParallelPiped(4.0, 5.0, 9.0));

    //all of these are legal
    for (int i = 0; i < shapes.size(); i++)
        cout << shapes[i]->area();
    for (auto s : shapes)
        cout << s->area();
    for (const auto &s : shapes)
        cout << s->area();
    for (auto &s : shapes)
    { //NOT ON MIDTERM
        s = new Cylinder(2.0, 4.0);
        cout << s->area();
    }
}