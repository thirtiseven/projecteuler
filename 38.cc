#include <iostream>
#include <string>
#include <algorithm>

using ll = long long;
const ll upper = 987654321;
const ll lower = 123456789;

bool check(ll a) {
	bool yes[10];
	std::fill(yes, yes+10, 0);
	int cnt = 0;
	while (a) {
		cnt++;
		yes[a%10] = 1;
		a /= 10;
	}
	if (cnt != 9) {
		return false;
	}
	for (int i = 1; i < 10; i++) {
		if (!yes[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {  
	ll cur = 1;
	ll ans = lower;
	while (1) {
		ll cnt = 1;
		std::string s;
		do {
			s += std::to_string(cur*cnt);
			cnt++;
		} while (std::stoll(s) < lower);
		ll now = std::stoll(s);
		if (now <= upper) {
			if (check(now)) {
				ans = std::max(now, ans);
				std::cout << ans << '\n';
			}
		}
		cur++;
	}
}