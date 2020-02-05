#include <iostream>
#include <string>

using ll = unsigned long long;

ll pow(ll a, ll x) {
	ll res = 1;
	for (ll i = 0; i < x; i++) {
		res *= a;
	}
	return res;
}

int main(int argc, char *argv[]) { 
	ll ans = 0; 
	for (ll i = 1; i <= 20; i++) {
		int now = 1;
		while (std::to_string(pow(now, i)).length() <= i && now < 12) {
			if (std::to_string(pow(now, i)).length() == i) {
				std::cout << now << ' ' << pow(now, i) << ' ' << i << ' ' << std::to_string(pow(now, i)).length() << '\n';
				ans++;
			}
			now++;
//			std::cout << now << ' ';
		}
		std::cout << '.';
	}
	std::cout << ans << '\n';
}