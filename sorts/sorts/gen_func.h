#pragma once

#include <iostream>
#include <cstdlib>
#include <assert.h>

template<class T>
void swap(T& A , T& B)
{
	T per = A;
	A = B;
	B = per;
}

template<class T>
bool check_arr(T* arr , int arr_size)
{
	for (int i = 0 ; i < arr_size - 1 ; ++i)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
