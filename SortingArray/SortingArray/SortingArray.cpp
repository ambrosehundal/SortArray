// SortingArray.cpp : Defines the entry point for the console application.
// main application

/*Ambrose Hundal
 * CIS 22C
 * Lab 4
 * Winter 2018
 */
 


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Array.h"
#include "Sort.h"
#include "fileoutput.h"

using namespace std;

const int SORT_MAX_SIZE = 32;

int main()
{
	cout << "Welcome to Array sorting program. " << endl;
    
	bool loopchoice = true;
	int asize, i;
	stringstream result;
	int choice;
	string s1, s2, s3;
	string outputFile = "result.txt";

	while (loopchoice) {
		result.str("");
		s1 = "";
		s2 = "";
		s3 = "";

		cout << "Enter the desired size for your array" << endl;
		cin >> asize;

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please Try again!" << endl;
			continue;
		}

		/*if size > maximum array size allowed*/

		if (asize > SORT_MAX_SIZE) {
			cin.clear();
			cin.ignore();
			cout << "Input size cannot be greater than 32! Please enter another array size." << endl;
			continue;
		}
		else if (asize < 1) {
			cin.clear();
			cin.ignore();
			cout << "Error! Input size must be valid and greater than 0. Please enter again." << endl;
			continue;
		}

		/*Ask user for data type for array*/
		cout << "Select the data type for your array" << endl
			<< "1. Int" << endl
			<< "2. Double" << endl
			<< "3. Char" << endl
			<< "4. String" << endl;
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid input! Please try again. " << endl;
			continue;
		}

		if (choice == 1) {
			Array<int> arrayPtr(asize);  //check if arrayPtr is right or have to use instance of array
			for (i = 0; i < asize; i++) {
				cout << "Please enter int " << i + 1 << ": ";
				cin >> arrayPtr[i];
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid input! Please try again." << endl;
					i--;
					continue;

				}
			}

			Array<int> arr1(arrayPtr);
			Array<int> arr2(arrayPtr);

			s1 += arrayPtr.printArray();
			s2 += arr1.printArray();
			s3 += arr2.printArray();

			Sort<int>::insertionSortRecursive(arrayPtr, asize, s1);
			Sort<int>::quickSortRecursive(arr1, 0, asize - 1, s2);
			Sort<int>::mergeSort(arr2, 0, asize - 1, s3);
			
			/*print out each recursive depth of each algorithm*/
			result << "InsertionSort Recursion method: " << endl << s1 << endl;
			result << "Quicksort Recursion method: " << endl << s2 << endl;
			result << "Merge Recursion method: " << endl << s3 << endl;
			cout << result.str();

			//fileIO
			Fileoutput::strToFile(result.str(), outputFile);
			/*reset array data after every loop*/
			arrayPtr.clearArray();
			arr1.clearArray();
			arr2.clearArray();

		}
		else if (choice == 2) {
			Array<double> arrayPtr(asize);  //check if arrayPtr is right or have to use instance of array
			for (i = 0; i < asize; i++) {
				cout << "Please enter double " << i + 1 << ": ";
				cin >> arrayPtr[i];
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid input! Please try again." << endl;
					i--;
					continue;

				}
			}

			Array<double> arr1(arrayPtr);
			Array<double> arr2(arrayPtr);

			s1 += arrayPtr.printArray();
			s2 += arr1.printArray();
			s3 += arr2.printArray();

			Sort<double>::insertionSortRecursive(arrayPtr, asize, s1);
			Sort<double>::quickSortRecursive(arr1, 0, asize - 1, s2);
			Sort<double>::mergeSort(arr2, 0, asize - 1, s3);

			/*print out each recursive depth of each algorithm*/
			result << "InsertionSort Recursion method: " << endl << s1 << endl;
			result << "Quicksort Recursion method: " << endl << s2 << endl;
			result << "Merge Recursion method: " << endl << s3 << endl;
			cout << result.str();

			//fileIO
			Fileoutput::strToFile(result.str(), outputFile);
			/*reset array data after every loop*/
			arrayPtr.clearArray();
			arr1.clearArray();
			arr2.clearArray();

		}

		else if (choice == 3) {
			Array<char> arrayPtr(asize);  //check if arrayPtr is right or have to use instance of array
			for (i = 0; i < asize; i++) {
				cout << "Please enter char " << i + 1 << ": ";
				cin >> arrayPtr[i];
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid input! Please try again." << endl;
					i--;
					continue;

				}
			}

			Array<char> arr1(arrayPtr);
			Array<char> arr2(arrayPtr);

			s1 += arrayPtr.printArray();
			s2 += arr1.printArray();
			s3 += arr2.printArray();

			Sort<char>::insertionSortRecursive(arrayPtr, asize, s1);
			Sort<char>::quickSortRecursive(arr1, 0, asize - 1, s2);
			Sort<char>::mergeSort(arr2, 0, asize - 1, s3);

			/*print out each recursive depth of each algorithm*/
			result << "InsertionSort Recursion method: " << endl << s1 << endl;
			result << "Quicksort Recursion method: " << endl << s2 << endl;
			result << "MergeSort Recursion method: " << endl << s3 << endl;
			cout << result.str();

			//fileIO
			Fileoutput::strToFile(result.str(), outputFile);
			/*reset array data after every loop*/
			arrayPtr.clearArray();
			arr1.clearArray();
			arr2.clearArray();

		}
		else if (choice == 4) {
			Array<string> arrayPtr(asize);  
			for (i = 0; i < asize; i++) {
				cout << "Please enter int " << i + 1 << ": ";
				cin >> arrayPtr[i];
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid input! Please try again." << endl;
					i--;
					continue;

				}
			}

			Array<string> arr1(arrayPtr);
			Array<string> arr2(arrayPtr);

			s1 += arrayPtr.printArray();
			s2 += arr1.printArray();
			s3 += arr2.printArray();

			Sort<string>::insertionSortRecursive(arrayPtr, asize, s1);
			Sort<string>::quickSortRecursive(arr1, 0, asize - 1, s2);
			Sort<string>::mergeSort(arr2, 0, asize - 1, s3);

			/*print out each recursive depth of each algorithm*/
			result << "InsertionSort Recursion method: " << endl << s1 << endl;
			result << "Quicksort Recursion method: " << endl << s2 << endl;
			result << "Merge Recursion method: " << endl << s3 << endl;
			cout << result.str();

			//fileIO
			Fileoutput::strToFile(result.str(), outputFile);
			/*reset array data after every loop*/
			arrayPtr.clearArray();
			arr1.clearArray();
			arr2.clearArray();

		}
	}










	system("pause");
    return 0;
}

