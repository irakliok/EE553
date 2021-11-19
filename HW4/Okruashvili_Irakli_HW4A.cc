#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

class vec_3d {
private:
	double x,y,z;
public:
	vec_3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
	vec_3d() :	x(0), y(0), z(0) {}
	double dot(const vec_3d& b) const  {     //a.dot(b)
		return x*b.x + y*b.y + z*b.z;
	}
	friend vec_3d operator +(vec_3d a, vec_3d b) {
		return vec_3d(a.x+b.x, a.y+b.y, a.z+b.z);
	}
	vec_3d operator -(const vec_3d& b) const {
		return vec_3d(this->x-b.x, this->y-b.y, this->z-b.z);
	}
	vec_3d operator -() const {
		return vec_3d(-x,-y,-z);
	}
	friend ostream& operator <<(ostream& s, const vec_3d& v) {
		s << v.x << ',' << v.y << ',' << v.z;
	}

	friend istream& operator >>(istream& s, vec_3d& v){
		s >> v.x;
		s >> v.y;
		s >> v.z;
	}
	double mag(const vec_3d& a, const vec_3d& b){
		return sqrt(a.x*b.x + a.y*b.y + a.z*b.z);
	}
	double magsq(const vec_3d& a, const vec_3d& b){
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
};

int main() {
	const vec_3d v1(1.5, 2.2, -3.1); // x=1.5 y=2.2 z-3.1
	const vec_3d v2(-2.2, 1.2); // z = 0
	const vec_3d v3(5.6); // y = z = 0
	//const vec_3d v4; // x = y = z = 0

	vec_3d v5 = v1 + v2;
	vec_3d v6 = v1 - v3;
	vec_3d v7 = -v2;// negation
	double d = v1.dot(v5); // dot product
	cout << "v1 =			" << v1 << '\n';
	cout << "v2 =			"  << v2 << '\n';
	cout << "v3 =			"  << v3 << '\n';
	//cout << "v4 = "  << v4 << '\n';
	cout << "v5 = v1 + v2 =		"  << v5 << '\n';
	cout << "v6 = v1 - v2 =		"  << v6 << '\n';
	cout << "v7 = -v2 =		"  << v7 << '\n';
	//cin >> v1; // read in x, y, z from keyboard
	cout << v1.mag() << '\n'; // magnitude (abs)
	cout << v1.magsq() << '\n'; // magnitude squared  x*x+y*y+z*z
}