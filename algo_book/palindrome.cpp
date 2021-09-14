#include <iostream>
#include <string>

bool palindrome(std::string test);

int main()
{
	std::string test;
	std::cin >> test;
	std::cout << palindrome(test) << std::endl;
	return 0;
}

bool palindrome(std::string test)
{
	int size = test.size();
	for (int i = 0 ; i < size / 2 ; ++i)
	{
		if (test[i] != test[size - i - 1])
			return false;
	}
	return true;
}