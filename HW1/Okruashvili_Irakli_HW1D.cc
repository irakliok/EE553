#include <iostream>
#include <iomanip>

using namespace std;

/* 
	Irakli Okruashvili
	I pledge my honor that I have abided by the Stevens Honor System - I.O.
*/

int main(){
	float  sum1F = 0, sum2F = 0;
	double sum1D = 0, sum2D = 0;
	
	cout << setprecision(8);
	
	for(float i = 1; i <= 100; i++){
		sum1F += 1/i;
	}
	cout << "sum1F = " << sum1F << ", ";
	for(float i = 100; i >= 1; i--){
		sum2F += 1/i;
	}
	cout << "sum2F = " << sum2F << "\n";
	
	for(double i = 1; i < 100; i++){
		sum1F += 1/i;
	}
	cout << "sum1D = " << sum1F << ", ";
	for(double i = 100; i >= 1; i--){
		sum2F += 1/i;
	}
	cout << "sum2D = " << sum2F << "\n";
	
	cout << "sum1F - sum2F = " << sum1F - sum2F << "\n";
	cout << "sum1D - sum2D = " << sum1D - sum2D << "\n";
	
	return 0;
}