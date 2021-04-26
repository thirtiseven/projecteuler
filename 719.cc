#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

const ll maxn = 1e12;

ll split(ll x, ll y) {
//	std::cerr << "---------::" << x << "\n";
	std::string s = std::to_string(x);
	int inv = s.length()-1;
	for (int i = 0; i < (1<<inv); i++) {
//		std::cout << i << ":\n";
		ll tem = 0, cur = ll(s[0]-'0'), ni = i;
		for (int j = 0; j < inv; j++) {
			if (ni % 2 == 1) {
//				std::cout << cur << ' ';
				tem += cur;
				cur = 0;
			}
			cur *= 10;
			cur += ll(s[j+1]-'0');
			ni /= 2;
		}
//		std::cout << cur << '\n';
		tem += cur;
		if (tem == y) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll ans = 0;
	for (ll i = 2; i * i <= maxn; i++) {
		if (i % 10000 == 0) {
			std::cout << i*i << '\n';
		}
		if (split(i * i, i)) {
//			std::cerr << i*i << '\n';
			ans += i*i;
		}
	}
	std::cout << ans << '\n';
}