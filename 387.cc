#include <iostream>

using ll = long long;

ll prime[6] = {2, 3, 5, 233, 331};

ll qmul(ll x, ll y, ll mod) { // 乘法防止溢出， 如果p * p不爆ll的话可以直接乘； O(1)乘法或者转化成二进制加法
	return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
}

ll qpow(ll a, ll n, ll mod) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = qmul(ret, a, mod);
		a = qmul(a, a, mod);
		n >>= 1;
	}
	return ret;
}

bool Miller_Rabin(ll p) {
	if(p < 2) return 0;
	if(p != 2 && p % 2 == 0) return 0;
	ll s = p - 1;
	while(! (s & 1)) s >>= 1;
	for(int i = 0; i < 5; ++i) {
		if(p == prime[i]) return 1;
		ll t = s, m = qpow(prime[i], s, p);
		while(t != p - 1 && m != 1 && m != p - 1) {
			m = qmul(m, m, p);
			t <<= 1;
		}
		if(m != p - 1 && !(t & 1)) return 0;
	}
	return 1;
}

ll ans;

void gao(ll x) {
	ll temp;
	for (ll i = 1; i <= 9; i++) {
		temp = x*10+i;
		if (Miller_Rabin(temp) && temp <= 1e14) {
			ans += temp;
			std::cout << temp << ' ';
		}
	}
}

void dfs(ll x, ll digsum) {
//	std::cout << x << ' ';
	if (x > 1e13) {
		return;
	}
	if (x%digsum != 0) {
		return;
	}
	if (x >= 2 && Miller_Rabin(x/digsum)) {
		gao(x);
	}
	for (ll i = 0; i <= 9; i++) {
		dfs(x*10+i, digsum+i);
	}
}

int main(int argc, char *argv[]) {  
	ans = 0;
	for (ll i = 1; i <= 9; i++) {
		dfs(i, i);
	}
	std::cout << ans << '\n';
}