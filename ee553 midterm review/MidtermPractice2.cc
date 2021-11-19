#include <iostream>

using namespace std;

class kidney
{
private:
    double health;
public:
    //kideny health 0% to 100%
    kidney(double health) : health(health)
    {
    }
    friend ostream &operator<<(ostream &s, const kidney &k)
    {
        return s << health;
    }
};

class heart
{
private:
    uint16_t beat_per_minute;
    uint16_t systolic;
    uint16_t diastolic;

public:
    heart(uint16_t bpm, uint16_t sys, uint16_t dia) : beat_per_minute(bpm), systolic(sys), diastolic(dia) {}

    friend ostream &operator<<(ostream &s, const kidney &k)
    {
        return s << " bpm = " << k.beats_per_minute << ", blood pressure = " << k.systolic << "/" << k.diastolic;
    }
};

class person
{
private:
    kidney k1, k2;
    heart h;

public:
    person(uint16_t bpm, uint16_t systolic, uint16_t diastolic, uint16_t left_kidney_health, uint16_t right_kidney_health)
        : k1(left_kidney_health), k2(right_kidney_health), h(bpm, systolic, diastolic) {}
    friend ostream &operator<<(ostream &s, const person &p)
    {
        return s << "person " << p.h << " Left kidney = " << p.k1 << " Right kidney = " << p.k2;
    }
};

int main()
{
    person p(60, 125, 75, 100, 100);
    cout << "Output:\n";
    cout << p << '\n'; //person bpm = 60, blood pressure = 125/75, left kidney = 100%, right kidney = 100
    return 0;
}