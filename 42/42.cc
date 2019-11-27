#include <iostream>
#include <fstream>
#include <string>
#include <set>

std::string s;
std::set<int> ss;

void generate() {
	for (int i = 1; i <= 100; i++) {
		ss.insert(i*(i+1)/2);
	}
}

int main(int argc, char *argv[]) {  
	std::ifstream fin ("p042_words.txt"); 
	generate();
	int tot = 0;
	for (int i = 0; i < 1786; i++) {
		fin >> s;
		int x = 0;
		for (auto it: s) {
			x += int(it-'A')+1;
		}
		if (ss.count(x) == 1) {
			tot++;
		}
	}
	std::cout << tot << '\n';
}