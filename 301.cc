#include <iostream>
 
// see en.wikipedia.org/wiki/Nim
unsigned int evaluate(unsigned int n1, unsigned int n2, unsigned int n3)
{
	return n1 ^ n2 ^ n3;
}
 
int main()
{
	// search up to n = 2^exponent
	unsigned int exponent = 30;
	std::cin >> exponent;
 
	unsigned int lost = 0;
	// 2^30 => about 1 billion values
	for (unsigned int n = 1U << exponent; n > 0; n--)
	{
		auto score = evaluate(n, 2*n, 3*n);
		if (score == 0)
			lost++;
	}
 
	std::cout << lost << std::endl;
	return 0;
}