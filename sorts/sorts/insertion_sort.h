#pragma once

#include <iostream>
#include <cstdlib>
#include <assert.h>

template<class T>
void insertion_step(T* arr , int arr_size , int num)
{
	T per = arr[num];
	int i_per = num;
	for (int i = num ; i < arr_size ; ++i)
	{
		if (per > arr[i])
		{
			per = arr[i];
			i_per = i;
		}
	}
	swap(arr[num] , arr[i_per]);
}

template<class T>
void insertion_sort(T* arr , int arr_size)
{
	for (int i = 0 ; i < arr_size - 1 ; ++i)
	{
		insertion_step(arr , arr_size , i);
	}

	assert(check_arr(arr , arr_size));
}