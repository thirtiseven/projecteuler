#include <iostream>
#include <algorithm>
#include <set>

const int upper = 50000000;

const int maxn = 100004;
int flag[maxn], primes[maxn], totPrimes;
std::set<int> ans;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	euler_sieve(100000);
	for (int i = 0; primes[i] * primes[i] <= upper; i++) {
		int x = primes[i] * primes[i];
		for (int j = 0; primes[j] * primes[j] * primes[j] <= upper; j++) {
			int y = primes[j] * primes[j] * primes[j];
			for (int k = 0; primes[k] * primes[k] * primes[k] * primes[k] <= upper; k++) {
				int z = primes[k] * primes[k] * primes[k] * primes[k];
				if (x + y + z <= upper) {
					ans.insert(x + y + z);
				}
			}
		}
	}
	std::cout << ans.size();
}