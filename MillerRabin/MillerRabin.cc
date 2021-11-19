#include <iostream>
#include <random>


using namespace std;

uint64_t powermod(uint64_t x, uint64_t p, uint64_t m){
	uint64_t prod = 1;
	while(p > 0){ // p == 17    10001
		if(p % 2 != 0){ // (p&1) != 0
			prod = prod * x % m;
		}
		p /= 2; // p>>=1
		x = x * x % m; // m can't be larger than 32bit
	}
	return prod;
}
	default_random_engine generator;
bool MillerRabin(uint64_t n, uint32_t k){

	uniform_int_distribution<int> distribution(2,n-2);

	
	uint64_t d = n - 1; //n == 221, d = 220, 11011100
	int r = 0;
	while(d&1 == 0){
		r++;
		d>>=1; //55
	}
	for(int i = 0; i < k; i++){
		uint64_t a = distribution(generator); //between 2 and n-2
		uint64_t x = powermod(a, d, n);
		if(x == 1 || x == n-1)
			continue;
		for(int j = 0; j < r-1; j++){
			x = x * x % n;
			if(x == n - 1)
				goto testPass;
		}
		return false;
	testPass:;
	}
	return true;
	
}

int main(){
	uint64_t x = 17;
	cout << "Miller rabin of " << x << " is " << MillerRabin(x, 3) << endl;
	return 0;
}

