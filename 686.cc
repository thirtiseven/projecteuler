#include <iostream>
#include <algorithm>
#include <vector>

//author: xudyh

using namespace std;
using ll = long long;

namespace linear_seq {
	const int N = 10010;
	typedef long long ll;
	constexpr ll mod = (ll) 1e9 + 7;

	ll pow_mod(ll a, ll b) {
		ll r = 1;
		for (a %= mod; b; b >>= 1, a = a * a % mod) {
			if (b & 1)r = r * a % mod;
		}
		return r;
	}

	ll res[N], base[N], _c[N], _md[N];
	vector<int> Md;

	void mul(ll *a, ll *b, int k) {
		k <<= 1;
		for (int i = 0; i < k; ++i) _c[i] = 0;
		k >>= 1;
		for (int i = 0; i < k; ++i) {
			if (a[i]) {
				for (int j = 0; j < k; ++j) {
					_c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
				}
			}
		}
		for (int i = k + k - 1; i >= k; i--) {
			if (_c[i]) {
				for (const int md: Md) {
					_c[i - k + md] = (_c[i - k + md] - _c[i] * _md[md]) % mod;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			a[i] = _c[i];
		}
	}

	int solve(ll n, vector<int> a, vector<int> b) { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
//        printf("SIZE %d\n",SZ(b));
		ll ans = 0, pnt = 0;
		int k = (int) a.size();
		assert(a.size() == b.size());
		for (int i = 0; i < k; ++i) {
			_md[k - 1 - i] = -a[i];
		}
		_md[k] = 1;
		Md.clear();
		for (int i = 0; i < k; ++i) {
			if (_md[i] != 0) {
				Md.push_back(i);
			}
		}
		for (int i = 0; i < k; ++i) {
			res[i] = base[i] = 0;
		}
		res[0] = 1;
		while ((1ll << pnt) <= n) {
			pnt++;
		}
		for (int p = pnt; p >= 0; p--) {
			mul(res, res, k);
			if ((n >> p) & 1) {
				for (int i = k - 1; i >= 0; i--) {
					res[i + 1] = res[i];
				}
				res[0] = 0;
				for (const int md: Md) {
					res[md] = (res[md] - res[k] * _md[md]) % mod;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			ans = (ans + res[i] * b[i]) % mod;
		}
		if (ans < 0) ans += mod;
		return ans;
	}

	vector<int> BM(vector<int> s) {
		vector<int> C(1, 1), B(1, 1);
		int L = 0, m = 1, b = 1;
		for (int n = 0; n < (int) s.size(); ++n) {
			ll d = 0;
			for (int i = 0; i <= L; ++i) {
				d = (d + (ll) C[i] * s[n - i]) % mod;
			}
			if (d == 0) {
				++m;
			}
			else if (2 * L <= n) {
				vector<int> T = C;
				ll c = mod - d * pow_mod(b, mod - 2) % mod;
				while (C.size() < B.size() + m) {
					C.push_back(0);
				}
				for (int i = 0; i < (int) B.size(); ++i) {
					C[i + m] = (C[i + m] + c * B[i]) % mod;
				}
				L = n + 1 - L;
				B = T;
				b = d;
				m = 1;
			} else {
				ll c = mod - d * pow_mod(b, mod - 2) % mod;
				while (C.size() < B.size() + m) {
					C.push_back(0);
				}
				for (int i = 0; i < (int) B.size(); ++i) {
					C[i + m] = (C[i + m] + c * B[i]) % mod;
				}
				++m;
			}
		}
		return C;
	}

	int gao(vector<int> a, ll n) {
		vector<int> c = BM(a);
		c.erase(c.begin());
		for (int &x:c) {
			x = (mod - x) % mod;
		}
		return solve(n, c, vector<int>(a.begin(), a.begin() + c.size()));
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::vector<int> x;
	x.push_back(90);
	x.push_back(379);
	x.push_back(575);
	x.push_back(864);
	x.push_back(1060);
	x.push_back(1545);
	x.push_back(1741);
	x.push_back(2030);
	x.push_back(2226);
	x.push_back(2515);
	x.push_back(2711);
	x.push_back(3000);
	x.push_back(3196);
	x.push_back(3681);
	x.push_back(3877);
	x.push_back(4166);
	x.push_back(4362);
	x.push_back(4651);
	x.push_back(4847);
	x.push_back(5136);
	x.push_back(5332);
	x.push_back(5817);
	x.push_back(6013);
	x.push_back(6302);
	x.push_back(6498);
	x.push_back(6787);
	x.push_back(6983);
	x.push_back(7272);
	x.push_back(7468);
	x.push_back(7953);
	x.push_back(8438);
	x.push_back(8634);
	x.push_back(8923);
	x.push_back(9119);
	x.push_back(9408);
	x.push_back(9604);
	x.push_back(10089);
	x.push_back(10574);
	x.push_back(10770);
	x.push_back(11059);
	x.push_back(11255);
	x.push_back(11544);
	x.push_back(11740);
	x.push_back(12225);
	x.push_back(12710);
//	std::cout << x[45] << '\n';
	for (int i = 0; i < 44; i++) {
		std::cout << x[i+1] - x[i] << ' ';
		if (i % 2 == 1) {
			std::cout << '\n';
		}
	}
//	std::cout << linear_seq::gao(x, 3);
//	int cur = 90;
//	for (int i = 0; i <= 45; i++) {
//		int x = i%6;
//		if (x == 0 || x == 2) {
//			cur += 289;
//		} else if (x == 4) {
//			cur += 485;
//		} else {
//			cur += 196;
//		}
//		std::cout << cur << ' ';
//	}
//	std::cout << cur << '\n';
}
//289 196 289 196 485 196
//289 196 289 196 289 196