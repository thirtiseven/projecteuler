#include <iostream>
#include <algorithm>
using ll = long long;

ll cal(ll x, ll y) {
	ll res = 0;
	res = (x*x+x)*(y*y+y)/4;
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll diff = 10000, ans1, ans2;
	for (ll i = 1; i <= 5000; i++) {
		for (int j = i; j <= 5000; j++) {
			ll x = std::abs(cal(i, j)-2000000);
			if (x < diff) {
				ans1 = i, ans2 = j;
				diff = x;
			}
//			std::cout << cal(i, j) << ' ';
		}
//		std::cout << '\n';
	}
	std::cout << cal(ans1, ans2) << ans1 * ans2;
}