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

void check(int x) {
	std::string s = std::to_string(x);
	std::string ans;
	int len = s.length();
	int upper = (1<<(s.length()))-1;
	for (int i = 0; i <= upper; i++) {
//		std::cerr << x << ' ' << i << ' ';
		s = std::to_string(x);
		int cnt = 0;
		for (char r = '0'; r <= '9'; r++) {
			for (int j = 0; j < len; j++) {
				if (i >> (len-j-1) & 1) {
					s[j] = r;
				}
			}
//			std::cerr << ' ' << s;
			if (flag[std::stoi(s)] == 0) {
				if (cnt == 0) {
					ans = s;
				}
				cnt++;
			}
		}
//		std::cerr << '\n';
		if (cnt == 8 && ans[0] != '0') {
			std::cout << ans << '\n';
			exit(0);
		}
	}
}

int main(int argc, char *argv[]) {  
	euler_sieve(1000000);
	for (int i = 0; i < totPrimes; i++) {
		check(primes[i]);
	}
}