#include <iostream>

const int maxn = 10000+7;
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
	euler_sieve(10000);
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; i <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int h = 1; h <= 9; h++) {
					//fuck
				}
			}
		}
	}
}