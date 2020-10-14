#include <iostream>
#include <algorithm>
#include <iomanip>

double rnd4[40], rnd6[40], pro4[40], pro6[40], base4, base6;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (int i = 0; i < 40; i++) {
		rnd4[i] = 0;
		rnd6[i] = 0;
		pro4[i] = 0;
		pro6[i] = 0;
	}
	for (int i1 = 1; i1 <= 4; i1++) {
		for (int i2 = 1; i2 <= 4; i2++) {
			for (int i3 = 1; i3 <= 4; i3++) {
				for (int i4 = 1; i4 <= 4; i4++) {
					for (int i5 = 1; i5 <= 4; i5++) {
						for (int i6 = 1; i6 <= 4; i6++) {
							for (int i7 = 1; i7 <= 4; i7++) {
								for (int i8 = 1; i8 <= 4; i8++) {
									for (int i9 = 1; i9 <= 4; i9++) {
										rnd4[i1+i2+i3+i4+i5+i6+i7+i8+i9] += 1.0;
										base4 += 1.0;
									}		
								}
							}	
						}		
					}
				}
			}		
		}
	}
	for (int i1 = 1; i1 <= 6; i1++) {
		for (int i2 = 1; i2 <= 6; i2++) {
			for (int i3 = 1; i3 <= 6; i3++) {
				for (int i4 = 1; i4 <= 6; i4++) {
					for (int i5 = 1; i5 <= 6; i5++) {
						for (int i6 = 1; i6 <= 6; i6++) {
							rnd6[i1+i2+i3+i4+i5+i6] += 1.0;	
							base6 += 1.0;
						}		
					}
				}
			}		
		}
	}
	for (int i = 0; i < 40; i++) {
		pro4[i] = rnd4[i] / base4;
		pro6[i] = rnd6[i] / base6;
	}
	double ans = 0;
	for (int i = 9; i <= 36; i++) {
		for (int j = 6; j <= 36; j++) {
			if (i > j) {
				ans += pro4[i] * pro6[j];
			}
		}
	}
	std::cout << std::fixed << std::setprecision(7) << ans << '\n';
}