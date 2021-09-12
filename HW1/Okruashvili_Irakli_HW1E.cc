#include <iostream>
using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

int main(){
	double x = -1.1;
	uint32_t fact = 1;
	while(x < 0  || (x - int(x)) != 0){
	cout << "Please enter a positive integer: ";
	cin >> x;
	cout << endl;
	if(x < 0)
		cout << "Enter Positive integer" << endl;
	if((x - int(x)) != 0)
		cout << "Enter a whole number" << endl;
	}
	
	for(int i = x; i > 0; i--)
		fact *= i;
	
	cout << "Your factorial for " << x << " is " << fact;
	
	return 0;
}