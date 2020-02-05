#include <iostream>
#include <vector>

const int maxn = 1e8+7;
short flag[maxn];
std::vector<int> primes;


void euler_sieve(int n) {
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes.push_back(i);
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int check (int x) {
	bool res = 1;
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0 && flag[i+x/i]) {
			res = 0;
			break;
		}
	}
	return res;
}

int main(int argc, char *argv[]) {  
	euler_sieve(100000000);
	long long ans = 1;
//	std::cout << ".";
	for (auto it: primes) {
		int x = it-1;
		if (x % 4 == 2) {
			if (check(x)) {
//				std::cout << x << '\n';
				ans += (long long)x;
			}
		}
	}
	std::cout << ans << '\n';
}