// Monica Moreno
// 861174030
// May 16, 2015
// Approach: I implemented the function selection sort using templates to sort
// the elements of the container passed-in. The function calls a different
// helper function depending on the container passed-in using function
// overloading. This is done in order to sort containers with pairs since
// pairs have a first and second which need to be accounted for. The
// selectionsort function I wrote is stable because when containers have 
// repeated elements, the repeated elements remain in the same relative 
// position. In order to make selectionsort stable, elements are only swapped
// if the element at the ith position and the smallest element found are 
// different. selectionsort.h contains my selectionsort implementation as 
// well as the helper function implementations. main.cc contains the testcases
// for different types of containers as well as code that tests the
// selectionsort function's stability.

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <utility>
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>

using namespace std;

// helper function for lists of pairs
template<typename P, typename p>
void selectionsort_(list<pair<P, p>> &l)
{
	cout << "pre: ";
	for(auto it = l.begin(); it != l.end(); ++it) // display the list passed-in
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	int counter = 0; // counter to count the number of moves made
	auto minIt = l.begin(); // iterator pointing to the first item in the list
	for(auto it1 = l.begin(); it1 != l.end(); ++it1)
	{
		minIt = it1;
		for(auto it2 = it1; it2 != l.end(); ++it2) // loop to find the smallest
		{
			if(*it2 < *minIt) // if a smaller element is found update minIt
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3; // increment counter
		}
	}
	cout << "post: ";
	for(auto it = l.begin(); it != l.end(); ++it) // display the sorted list
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}


// selection sort for vectors
template<typename V>
void selectionsort_(vector<V> &l)
{
	cout << "pre: "; // display the vector passed-in
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	int counter = 0; // counter to keep track of moves made
	auto minIt = l.begin(); // iterator for min element
	for(auto it1 = l.begin(); it1 != l.end(); ++it1)
	{
		minIt = it1;
		// find the smallest element
		for(auto it2 = it1 + 1; it2 != l.end(); ++it2)
		{
			if(*it2 < *minIt)
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: "; // display the sorted vector
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}

// selection sort for vectors of pairs
template<typename T, typename t>
void selectionsort_(vector<pair<T, t>> &l)
{
	cout << "pre: "; // display the vector passed-in
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	int counter = 0; // counter to keep track of the moves made
	auto minIt = l.begin(); // iterator to keep track of the smallest element
	for(auto it1 = l.begin(); it1 != l.end(); ++it1)
	{
		minIt = it1;
		// find the smallest element
		for(auto it2 = it1 + 1; it2 != l.end(); ++it2)
		{
			if(*it2 < *minIt)
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: "; // display the sorted vector
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}

// selection sort for lists
template<typename T>
void selectionsort_(list<T> &l)
{
	cout << "pre: "; // display the list passed-in
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	int counter = 0; // counter to keep track of the moves made
	auto minIt = l.begin(); // iterator for the smallest element
	for(auto it1 = l.begin(); it1 != l.end(); ++it1)
	{
		minIt = it1;
		for(auto it2 = it1; it2 != l.end(); ++it2) // find smallest element
		{
			if(*it2 < *minIt)
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: "; // display the sorted list
	for(auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}

// selection sort for arrays
template<typename T>
void selectionsort(T l[], int s)
{
	int size = s; // store the size of the array passed-in
	cout << "pre: "; 
	for(auto it = l; it != l + size; it++) // display the array passed-in
	{
		cout << *it << ' ';
	}
	cout << endl;
	int counter = 0; // counter to keep track of the moves made
	auto minIt = l; // iterator to keep track of the smallest element
	for(auto it1 = l; it1 != l + size; ++it1)
	{
		minIt = it1;
		for(auto it2 = it1; it2 != l + size; ++it2) // find smallest element
		{
			if(*it2 < *minIt)
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: "; // display the sorted array
	for(auto it = l; it != l + size; ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}

// selection sort for arrays of pairs
template<typename A, typename B>
void selectionsort(pair<A, B> l[], int s)
{
	int size = s; // store the size of the array passed-in
	cout << "pre: "; // display the array passed-in
	for(auto it = l; it != l + size; ++it)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	int counter = 0; // counter to keep track of the moves made
	auto minIt = l; // iterator to keep track of the smallest element
	for(auto it1 = l; it1 != l + size; ++it1)
	{
		minIt = it1;
		for(auto it2 = it1; it2 != l + size; ++it2) // find smallest element
		{
			if(*it2 < *minIt)
			{
				minIt = it2;
			}
		}
		if(*it1 != *minIt) // only swap if *it1 and *minIt are different
		{
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: "; // display the sorted array
	for(auto it3 = l; it3 != l + size; ++it3)
	{
		cout << "(" << it3->first << ", " << it3->second << ") ";
	}
	cout << endl;
	cout << "0 copies and " << counter << " moves" << endl; //display moves made
}

// function to sort containers
template<typename L>
void selectionsort(L &l)
{
	selectionsort_(l); // call helper function
}

#endif