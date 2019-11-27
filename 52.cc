#include <iostream>
#include <string>
#include <algorithm>

using ll = long long;

const ll lower = 100000;
const ll upper = 1000000;

int main(int argc, char *argv[]) {  
	for (ll i = lower; i <= upper; i++) {
		std::string sor = std::to_string(i);
		std::sort(sor.begin(), sor.end());
		bool yes = 1;
		for (ll x = 2; x <= 6; x++) {
			std::string tra = std::to_string(i*x);
			std::sort(tra.begin(), tra.end());
			if (tra != sor) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << i << '\n';
			break;
		}
	}
}