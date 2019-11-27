#include <iostream>
#include <string>

int up = 1, down = 1;
using ll = int;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
//	for (int i = 10; i <= 98; i++) {
//		for (int j = i+1; j <= 99; j++) {
//			if (gcd(i, j) != 1 && i%10 != 0 && j%10 != 0) {
//				std::string a = std::to_string(i);
//				std::string b = std::to_string(j);
//				if (a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1]) {
//					if (i / gcd(i, j) < 10 && j / gcd(i, j) < 10) {
//						std::cout << i << ' ' << j << ' ' << i / gcd(i, j) << " " << j / gcd(i, j) << '\n';
//					}
//				}
//			}
//		}
//	}
//	std::cout << down / gcd(up, down);
	up = 16*19*26*49;
	down = 64*95*65*98;
	std::cout << down / gcd(up, down);
}



//16 64 1 4
//19 95 1 5
//26 65 2 5
//49 98 1 2


