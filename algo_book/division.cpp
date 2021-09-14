#include <iostream>

int main()
{
	int x = 0 , y = 0;
	std::cin >> x >> y;
	int q = 0 , r = x;

	std::cout << "div - " << q << std::endl;
	std::cout << "ret - " << r << std::endl;

	while (y <= r)
	{
		r = r - y;
		q++;

		std::cout << "div - " << q << std::endl;
		std::cout << "ret - " << r << std::endl;
	}

	std::cout << "result - q = " << q << " r = " << r << std::endl;

	return 0;
}