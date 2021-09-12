#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

int main(){
	
	cout << setprecision(2);
	cout << '\t' << '\t';
	
	for(int i = 40; i >= -45; i -= 5){
		cout << i << '\t';
	}
	cout << '\n' << '\n' << '\n';

	for(double j = 5; j <= 60; j += 5){ /* Wind */
		for(double i = 40; i >= -45; i -= 5){ /* Temperature */
			if(i == 40)
				cout << j << '\t' << '\t';
			cout << round(35.74 + 0.6215 * i - 35.75 * pow(j, 0.16) + 0.4275 * i * pow(j, 0.16)) << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}