#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Elephant
{
private:
    string name;
    int age;

public:
    // Automatically loads const char s[] to string
    Elephant(const char s[], int age) : name(name), age(age){};
    void setName(const char n[]){
        name = n;
    }
}

int main()
{
    Elephant e("Fred", 3);
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(4);
    a.push_back(1);
    a.push_back(5);

    for (auto x : a)
    {
        cout << x;
    }
    for (auto x : a)
    {
        cout << x;
        x++; // DOESN'T WORK - x is a copy
    }
    cout << '\n';

    for (auto &x : a)
    {
        x *= 2; // WORKS - x is passed by reference
    }

    vector<Elephant> elep;
    elep.push_back(Elephant("Bob", 3));
    elep[0].setName("Alice");
    elep[0].setName("Eve");

    vector<const Elephant> elep2;
    elep2.push_back(Elephant("Betty", 18));
    elep2.push_back(Elephant("Joe", 41));
    //elep2[0].setName("Fred"); // DOESN'T WORK - const
    return 0;
}