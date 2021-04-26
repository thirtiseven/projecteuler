#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1e7;

bool is_pandigital(int x) {
	std::string s = std::to_string(x);
//	std::cout << "int " << x << '\n';
	std::sort(s.begin(), s.end());
	if (s == "123456789") {
		return true;
	}
	return false;
}

int f_last[maxn];
long long f_first[maxn];

void gao() {
	f_first[1] = f_first[2] = f_last[1] = f_last[2] = 1;
	for (int i = 3; i < maxn; i++) {
		f_first[i] = f_first[i-1] + f_first[i-2];
		f_last[i] = (f_last[i-1] + f_last[i-2]) % 1000000000;
		if (f_first[i] > 100000000 && f_last[i] > 100000000 && is_pandigital(f_last[i])) {
			double t = (i * 0.20898764024997873 - 0.3494850021680094);         
			if (is_pandigital((long long)pow(10, t - (long long)t + 8))) {
				std::cout << i << '\n';
				break;
			}
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	gao();
}