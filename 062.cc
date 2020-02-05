#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using ll = long long;

std::map<ll, int> cnt;

const ll upper = 1e5+8;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (ll i = 1; i <= upper; i++) {
		ll x = i*i*i;
		std::string xx = std::to_string(x);
		std::sort(xx.rbegin(), xx.rend());
//		std::cout << xx << '\n';
		ll xxx = std::stoll(xx);
		cnt[xxx]++;
	}
	for (ll i = 1; i <= upper; i++) {
		ll x = i*i*i;
		std::string xx = std::to_string(x);
		std::sort(xx.rbegin(), xx.rend());
//		std::cout << xx << '\n';
		ll xxx = std::stoll(xx);
		if (cnt[xxx] == 5) {
			std::cout << i*i*i << '\n';
			break;
		}
	}
}