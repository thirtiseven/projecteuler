#include <iostream>
#include <string>

const int maxn = 1e7+10;
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

bool check(int a, int b, int c, int d, int e) {
	bool yes = 1;
	if (!flag[std::stoi(std::to_string(a)+std::to_string(a))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(a)+std::to_string(b))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(a)+std::to_string(c))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(a)+std::to_string(d))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(a)+std::to_string(e))]) {
		yes = 0;
	}
	
	if (!flag[std::stoi(std::to_string(b)+std::to_string(a))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(b)+std::to_string(b))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(b)+std::to_string(c))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(b)+std::to_string(d))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(b)+std::to_string(e))]) {
		yes = 0;
	}
	
	if (!flag[std::stoi(std::to_string(c)+std::to_string(a))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(c)+std::to_string(b))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(c)+std::to_string(c))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(c)+std::to_string(d))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(c)+std::to_string(e))]) {
		yes = 0;
	}
	
	if (!flag[std::stoi(std::to_string(d)+std::to_string(a))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(d)+std::to_string(b))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(d)+std::to_string(c))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(d)+std::to_string(d))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(d)+std::to_string(e))]) {
		yes = 0;
	}
	
	if (!flag[std::stoi(std::to_string(e)+std::to_string(a))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(e)+std::to_string(b))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(e)+std::to_string(c))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(e)+std::to_string(d))]) {
		yes = 0;
	}
	if (!flag[std::stoi(std::to_string(e)+std::to_string(e))]) {
		yes = 0;
	}
	return yes;
}

int main(int argc, char *argv[]) {  
	euler_sieve(100000);
	int ans = 100000000;
	for (int i0 = 0; i0 < totPrimes-4; i0++) {
		for (int i1 = i0+1; i1 < totPrimes-3; i1++) {
			for (int i2 = i1+1; i2 < totPrimes-2; i2++) {
				for (int i3 = i2+1; i3 < totPrimes-1; i3++) {
					for (int i4 = i3+1; i4 < totPrimes; i4++) {
						std::cerr << primes[i0] << ' ' << primes[i1] << ' ' << primes[i2] << ' ' << primes[i3] << ' ' << primes[i4] << '\n';
						if (check(primes[i0], primes[i1], primes[i2], primes[i3], primes[i4])) {
							ans = std::min(ans, primes[i0]+primes[i1]+primes[i2]+primes[i3]+primes[i4]);
						}
					}
				}
			}
		}
	}
}