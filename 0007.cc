#include <iostream>

bool is_prime(long long n) {
	if(n < 2) return false;
	for(long long i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {  
	long long cnt = 0;
	long long num = 1;
	while(1) {
		num++;
		if(is_prime(num)) {
			cnt++;
		}
		if(cnt == 10001) {
			break;
		}
	}
	std::cout << num;
	return 0;
}