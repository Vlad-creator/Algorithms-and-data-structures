#include <iostream>
#include <array>

void Ulman_N(int N);
void Ulman(int A);

int main()
{
	int N = 0;
	std::cin >> N;
	Ulman_N(N);
	return 0;
}

void Ulman_N(int N)
{

	for (int i = 1 ; i < N ; ++i)
	{
		std::cout << "number - " << i << " ";
		Ulman(i);
		std::cout << std::endl;
	}
}

void Ulman(int A)
{
	std::array<int , 3> last = {0 , 0 , 0};
	last[0] = A;
	int counter = 0;
	while ((last[2] != 4) || (last[1] != 2) || (last[0] != 1))
	{
		if (A % 2 == 0)
			A = A / 2;
		else
			A = 3 * A + 1;

		last[2] = last[1];
		last[1] = last[0];
		last[0] = A;

		std::cout << A << " ";
	}
}

