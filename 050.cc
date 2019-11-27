#include <iostream>

const int maxn = 1000007;
using ll = long long;

ll flag[maxn], primes[maxn], totPrimes;
ll pre[maxn];

void euler_sieve(ll n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (ll i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (ll j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int main(int argc, char *argv[]) {  
	euler_sieve(1000000);
	pre[0] = primes[0];
	for (int i = 1; i <= totPrimes; i++) {
		pre[i] = pre[i-1] + primes[i];
	}
	int ans = 0, num = 0;
	for (int i = 2; i < totPrimes-1; i++) {
		for (int j = i+1; j < totPrimes; j++) {
			if (pre[j]-pre[i-1] >= 1000000) {
				break;
			} else {
				if (!flag[pre[j]-pre[i-1]]) {
					if (j-i > num) {
						num = j-i;
						ans = pre[j]-pre[i-1];
					}
				}
			}
		}
	}
	std::cout << ans << '\n';
}