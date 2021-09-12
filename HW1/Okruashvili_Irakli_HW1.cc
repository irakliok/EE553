#include <iostream>
using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

int sumSquaresUpTo(int n) {
	// write your loop in terms of n
	uint64_t y = 0;
	for(int i = 1; i <= n; i++)
		y += i*i;
	return y;
}

int main() {
	// Write a for loop that prints 100, 50, 25, 12, 6, 3, 1 (keep dividing by 2)
	for(int i = 100; i > 0; i /= 2)
		cout << i << " ";
	cout << '\n';
	// Write a for loop that counts 10 9 8 7 6 5 4 3 2 1 0
	for(int i = 10; i >= 0; i--)
		cout << i << " ";
	cout << '\n';
	
	cout << sumSquaresUpTo(5) << '\n'; // 1*1 + 2*2 + 3*3 + 4*4 + 5*5 = ???
	cout << sumSquaresUpTo(7) << '\n';


}