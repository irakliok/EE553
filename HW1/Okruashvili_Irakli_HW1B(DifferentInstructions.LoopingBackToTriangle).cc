#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

long double ngons(uint32_t n){
	long double r = 1;
	if(n == 1)
		return 1;
	for(int i = 2; i <= n; i++){
		if(i % 3 == 2)
			r = r/sin(30*M_PI/180);
		if(i % 3 == 0)
			r = (r/cos(45*M_PI/180);
		if(i % 3 == 1)
			r = r/cos(36*M_PI/180);
	}
	return r;
}

int main(){
	/*
	uint32_t x = 0;
	cout << "Enter n for nth circle: ";
	cin >> x; 
	cout << '\n' << "The radius of number " << x << " circle is: " << ngons(x) << ".";
	*/
	cout << '\n' << "n = 10" << '\t' << '\t' << "Radius = " << ngons(12);
	cout << '\n' << "n = 100" << '\t' << '\t' << "Radius = " << ngons(102);
	cout << '\n' << "n = 1000" << '\t' << "Radius = " << ngons(1002);
	cout << '\n' << "n = 10000" << '\t' << "Radius = " << ngons(10002);
	cout << '\n' << "n = 100000" << '\t' << "Radius = " << ngons(100002);
	cout << '\n' << "n = 1000000" << '\t' << "Radius = " << ngons(1000002);
	return 0;
}