#pragma once

#ifndef SORT_H
#define SORT_H
#include <string>
#include "Array.h"

using namespace std;

template<class T>
class Sort {
public:
	

	/*Sorting Algorithms*/
	/*InsertionSort recursive*/
	static void insertionSortRecursive(Array<T> &arr, int n, string &a1);
	/*QuickSort recursive*/
	static int partition(Array<T>& arr, int start, int end);
	static void quickSortRecursive(Array<T> & arr, int p, int r, string &a1);
	/*Mergesort recursive methods*/
	static void mergeAssign(Array<T> &arr, int l, int m, int r, T L[], T R[], int i, int j);
	static void mergeArray(Array<T> &arr, int l, int m, int r, T L[], T R[], int i, int j, int k);
	static void merge(Array<T> &arr, int l, int m, int r);
	static void mergeSort(Array<T> &arr, int l, int r, string &a1);


};


/***************************************
* insertion sort Recursive algorithm
* 
****************************************/
template<class T>
void Sort<T>::insertionSortRecursive(Array<T> &arr, int n, string &a1)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive(arr, n - 1, a1);

	// Insert last element at its correct position
	// in sorted array.
	T last = arr[n - 1]; //check data type
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;

	/*print array contents at each recursive depth*/
	a1 += arr.printArray();
}

/*************************************
Quicksort recursive algorithm helper 
method
**************************************/
template <class T>
int Sort<T>::partition(Array<T> & arr, int start, int end) {
	T pivot = arr[start];
	int left = start + 1;
	int right = end;
	T tmp;

	while (left != right) {
		if (arr[left] <= pivot) left++;
		else {
			while ((left != right) && (pivot < arr[right])) right--;

			tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
		}
	}

	if (arr[left]>pivot) left--;
	arr[start] = arr[left];
	arr[left] = pivot;

	return (left);
}

/***************************************
quicksort recursive algorithm
****************************************/
template <class T>
void Sort<T>::quickSortRecursive(Array<T> & arr, int p, int r, string &a1) {
	if (p < r) {
		int q = partition(arr, p, r);
		quickSortRecursive(arr, p, q - 1, a1);
		quickSortRecursive(arr, q + 1, r, a1);
	}
	//print elements
	a1 += arr.printArray();

}
/************************************
 MergeSort helper method
************************************/
template< class T >
void Sort<T>::mergeAssign(Array<T> &arr, int l, int m, int r, T L[], T R[], int i, int j)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	if (i < n1)
	{
		L[i] = arr[l + i];
	}
	if (j < n2)
	{
		R[j] = arr[m + 1 + j];
	}
	if (i < n1 && j < n2)
		mergeAssign(arr, l, m, r, L, R, i + 1, j + 1);
}



/*****************************
 MergeSort helper method
Merges two subarrays of arr[] 
******************************/

template< class T >
void Sort<T>::mergeArray(Array<T> &arr, int l, int m, int r, T L[], T R[], int i, int j, int k)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	if (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			mergeArray(arr, l, m, r, L, R, i + 1, j, k + 1);
		}
		else
		{
			arr[k] = R[j];
			mergeArray(arr, l, m, r, L, R, i, j + 1, k + 1);
		}
	}
	else
	{

		/* Copy the remaining elements of L[], if there
		are any */
		if (i < n1)
		{
			arr[k] = L[i];
			mergeArray(arr, l, m, r, L, R, i + 1, j, k + 1);
		}

		/* Copy the remaining elements of R[], if there
		are any */
		if (j < n2)
		{
			arr[k] = R[j];
			mergeArray(arr, l, m, r, L, R, i, j + 1, k + 1);
		}
	}
}

 /************************************
  MergeSort helper method
  - creates two subarrays
 *************************************/
template< class T >
void Sort<T>::merge(Array<T> &arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	/* create temp arrays */
	T* L = new T[n1];
	T* R = new T[n2];
	mergeAssign(arr, l, m, r, L, R, 0, 0);

	mergeArray(arr, l, m, r, L, R, 0, 0, l);
	delete[] L;
	delete[] R;
}

/*********************************
  recursive merge sort algorithm
  main method
**********************************/
template< class T >
void Sort<T>::mergeSort(Array<T> &arr, int l, int r, string &a1)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m, a1);
		mergeSort(arr, m + 1, r, a1);

		merge(arr, l, m, r);
	}

	a1 += arr.printArray();
};

#endif