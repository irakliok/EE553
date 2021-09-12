#include <iostream>
using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

int main(){
	uint32_t x = 0;
	
	
	cout << "Please enter a positive integer: ";
	cin >> x;
	cout << endl;
	
	while(x != 1){
		if(x % 2 == 1){
			x *= 3;
			x++;
			cout << "Odd (3x+1): " << x << endl;
		}
		else{
			x/=2;
			cout << "Even (x/2): " << x << endl;
		}
	}
	
	if(x == 1)
		cout << "Final Result: " << x << endl;
	else
		cout << "Error. Value = " << x << endl;
	
	return 0;
}