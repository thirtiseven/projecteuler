#include <iostream>
#include <set>

using ll = long long;
const ll ub = 3000;

std::set<ll> s;

void inti() {
	for (int i = 1; i <= ub; i++) {
		s.insert(i*(3*i-1)/2);
	}
}

int main(int argc, char *argv[]) {  
	inti();
	ll ans = 10000000000;
	for (ll i = 1; i <= 3000; i++) {
		for (ll j = 1; j <= ub; j++) {
			ll a = j*(3*j-1)/2;
			ll b = (j+i)*(3*(j+i)-1)/2;
			if (s.count(b-a) && s.count(b+a)) {
				ans = std::min(b-a, ans);
			}
		} 
	}
	std::cout << ans << '\n';
}