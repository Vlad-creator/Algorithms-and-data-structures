#pragma once

#include <iostream>
#include <cstdlib>
#include <assert.h>

template<class T>
void bubble_step(T* arr , int arr_size)
{
	for (int i = 0 ; i < arr_size - 1 ; ++i)
	{
		if (arr[i] > arr[i + 1])
			swap(arr[i] , arr[i + 1]);
	}
}

template<class T>
void bubble_sort(T* arr , int arr_size)
{
	assert(arr != nullptr);

	while(!check_arr(arr , arr_size))
	{
		bubble_step(arr , arr_size);
	}
}