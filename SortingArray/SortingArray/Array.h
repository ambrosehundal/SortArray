#pragma once
#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Array {
private:
	int arraysize;
	T* arrayPtr; //pointer to first element of the array
public:
	Array();
	Array(int m);
	//virtual ~Array();
	void clearArray();
	void setItem(int index, int value);
	string printArray();
	T &operator[] (int);
	//friend ostream& operator<< (ostream &foo, Array<T> *aPtr);
};

/**************************
* Array() constructor
***************************/
template <class T>
Array<T>::Array() {
	arraysize = 0;
}

/**************************
* Array(int m) constructor
* sets size of array = m
***************************/
template <class T>
Array<T>::Array(int m) {
	arraysize = m;
	arrayPtr = new T[m];
}

/**************************
* void clear()
* clears all
* the elements of array
***************************/
template <class T>
void Array<T>::clearArray() {
	if (arraysize = 0) {
		cout << "Array is Empty! nothing to clear." << endl;
	}
	else if (arraysize > 0) {
		delete[] arrayPtr;
		arrayPtr = nullptr;
	}
}

/*************************
* void setItem()
* sets the array element
* value to the value in
* parameter at given index
**************************/
template <class T>
void Array<T>::setItem(int index, int value) {
	arrayPtr[index] = value;
}

/*********************************
printArray()
- prints out all elements of array
**********************************/
template <class T>
string Array<T>::printArray() {
	stringstream aa;
	for (int i = 0; i < arraysize; i++) {
		aa << i << " " << arrayPtr[i] << endl;
	}
	aa << "*****************************" << endl;
	return aa.str();
}

template< class T >
T &Array<T>::operator[](int index)
{
	if (index >= arraysize)
	{
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return arrayPtr[index];
}
#endif