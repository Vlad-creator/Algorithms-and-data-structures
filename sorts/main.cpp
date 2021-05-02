#include <iostream>
#include "time.h"
#include "sorts/gen_func.h"
#include "sorts/bubble_sort.h"
#include "sorts/insertion_sort.h"

template<class T>
void print_arr(T* arr , int arr_size)
{
	for (int i = 0 ; i < arr_size ; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int num = 0;
	uint64_t bubble_time = 0;
	uint64_t insertion_time = 0;
	my_time::Timer clock;

	std::cin >> num;
	float* arr = new float[num];
	float* arr_per = new float[num];
	for (int i = 0 ; i < num; i++)
	{
		arr[i] = rand() % 100;
		arr_per[i] = arr[i];
	}

	//print_arr(arr , num);

	clock.restart();
	bubble_sort(arr_per , num);
	bubble_time = clock.get_mls();

	//print_arr(arr_per , num);

	for (int i = 0 ; i < num ; ++i)
	{
		arr_per[i] = arr[i];
	}

	clock.restart();
	insertion_sort(arr_per , num);
	insertion_time = clock.get_mls();

	//print_arr(arr_per , num);

	for (int i = 0 ; i < num ; ++i)
	{
		arr_per[i] = arr[i];
	}

	std::cout << "bubble_sort time = " << bubble_time << " milliseconds" << std::endl;
	std::cout << "insertion_sort time = " << insertion_time << " milliseconds" << std::endl;

	delete[] arr;
	delete[] arr_per;

	return 0;
}