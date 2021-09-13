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

	for(int i = 3; i <= n; i++){
			r = r/cos((360.00/(i*2))*M_PI/180.00);
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
	cout << setprecision(12);
	cout << '\n' << "n = 10" << '\t' << '\t' << "Radius = " << ngons(10);
	cout << '\n' << "n = 100" << '\t' << '\t' << "Radius = " << ngons(100);
	cout << '\n' << "n = 1000" << '\t' << "Radius = " << ngons(1000);
	cout << '\n' << "n = 10000" << '\t' << "Radius = " << ngons(10000);
	cout << '\n' << "n = 100000" << '\t' << "Radius = " << ngons(100000);
	cout << '\n' << "n = 1000000" << '\t' << "Radius = " << ngons(1000000);
	return 0;
}