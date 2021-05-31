#include <iostream>
#include <map>

using ll = long long;

std::map<ll, ll> mp;

const ll upper = 2000010;

int main(int argc, char *argv[]) {
	for (ll k = 1; k <= upper; k++) {
		if (3*k*k > 1000000) {
			for (ll a = 2*k; a <= upper; a++) {
				if (3*k*k+2*k*a-a*a > 1000000) {
					break;
				}
				mp[3*k*k+2*k*a-a*a]++;
			}
		} else {
			for (ll a = 2*k; a >= 1; a--) {
				if (3*k*k+2*k*a-a*a > 1000000) {
					break;
				}
				mp[3*k*k+2*k*a-a*a]++;
			}
		}
	}
	ll ans = 0;
	for (auto it: mp) {
		if (it.second == 10) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}

/*
(a+2k)*(a+2k)-(a+k)*(a+k)-a*a
=a*a+4ka+4*k*k-a*a-2*k*a-k*k-a*a
=2ka+3*k*k-a*a
=3kk+2ka-aa
=n

3kk+(2k-a)a=n


*/