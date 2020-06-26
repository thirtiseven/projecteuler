#include <iostream>
#include <algorithm>

using ll = long long;
ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

ll upper = 12000;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll ans = 0;
	for (ll i = 2; i <= upper; i++) {
		for (ll j = std::max(1LL, i/3ll-1); j*2 < i; j++) {
			if (gcd(i, j) == 1 && j*3ll > i) {
//				std::cout << i << ' ' << j << '\n';
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}