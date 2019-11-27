#include <iostream>
#include <cmath>

using ll = long long;

bool checkT(int a) {
	ll x = sqrt(1LL+8ll*a);
	if (x * x == 1LL+8ll*a && x%2==1) {
		return 1;
	}
	return 0;
}

bool checkP(ll a) {
	ll x = (long long)sqrt(1LL+24ll*a);
//	std::cout << a << ' ' << x << ' ' << x * x << ' ' << 1LL+24ll*a << '\n';
	if (x * x == 1LL+24ll*a && x%6==5) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	for (ll i = 1; i <= 27693; i++) {
		ll H = i*(2*i-1LL);
		std::cout << H << ' ' << checkP(H) << ' ' << checkT(H) << '\n';
		if (checkP(H) && checkT(H)) {
			std::cout << H << '\n';
//			break;
		}
	}
}