#include <iostream>
#include <string>

const int maxn = 1e6+7;
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
	int ans = 0;
	euler_sieve(1000000);
	flag[1] = 1;
	for (int i = 4; i < totPrimes; i++) {
//		std::cout << primes[i] << '\n';
		std::string s = std::to_string(primes[i]);
		bool yes = 1;
		for (int j = 1; j < s.length(); j++) {
//			std::cout << s.substr(0, j) << ' ' << j << '\n';
			if (flag[std::stoi(s.substr(0, j))]) {
				yes = 0;
				break;
			}
		}
//		std::cout << '\n';
		if (yes) {
			for (int j = 1; j < s.length(); j++) {
//				std::cout << s.substr(j) << ' ' << j << '\n';
				if (flag[std::stoi(s.substr(j))]) {
					yes = 0;
					break;
				}
			}
		}
		if (yes) {
			ans += primes[i];
			std::cout << primes[i] << '\n';
		}
	}
	std::cout << ans << '\n';
}