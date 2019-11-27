#include <iostream>

const int maxn = 1e8+7;
int flag[maxn], primes[maxn], totPrimes;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int main(int argc, char *argv[]) {  
	euler_sieve(100000000);
	for (int i = 9; i <= 100000000; i+=2) {
		if (flag[i]) {
			bool yes = 0;
			for (int j = 1; 2 * j * j <= i; j++) {
				if (!flag[i-2 * j * j]) {
					yes = 1;
				}
			}
			if (yes == 0) {
				std::cout << i;
				break;
			}
		}
	}
}