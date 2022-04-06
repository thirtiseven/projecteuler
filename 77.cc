#include <iostream>
#include <algorithm>

const int maxn = 1e8+7;
int flag[maxn], primes[maxn], totPrimes;

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

int dp[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	euler_sieve(100000000);
	std::cout << "sieve!\n";
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 100; i++) {
		for (int j = 0; primes[j] <= i; j++) {
			dp[i] += dp[i - primes[j]];
		}
		std::cerr << dp[i] << ", ";
		if (dp[i] == 5) {
			std::cout << i << '\n';
		}
	}
}