#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using ll = long long;
const int maxn = 2177282;

ll fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

ll next(ll x) {
	ll res = 0;
	while (x) {
		res += fac[x%10];
		x /= 10;
	}
	return res;
}

int vis[maxn];

std::vector<ll> g[maxn];

void init() {
	std::fill(vis, vis+maxn, 0);
}

void gao(ll x) {
	if (vis[x]) {
		return; 
	}
	vis[x] = 1;
	ll y = next(x);
	g[x].push_back(y);
	gao(y);
}

bool check(ll x) {
	ll xx = x;
	std::set<ll> s;
	s.insert(x);
	for (int i = 2; i <= 60; i++) {
		x = next(x);
		s.insert(x);
		if (s.size() != i) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	init();
	ll ans = 0;
	for (ll i = 1; i < 1000000; i++) {
		ans += check(i);
	}
	std::cout << ans << '\n';
}