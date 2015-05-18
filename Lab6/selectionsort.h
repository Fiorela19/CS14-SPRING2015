// Monica Moreno
// 861174030
// May 18, 2015
// Approach: I implemented the function selection sort using templates to sort
// the elements of the container passed-in. The function calls a print
// helper function depending on the container passed-in using function
// overloading. This is done in order to sort containers with pairs since
// pairs have a first and second which need to be accounted for. The
// selectionsort function I wrote is stable because when containers have 
// repeated elements, the repeated elements remain in the same relative 
// position. In order to make selectionsort stable, elements are only swapped
// if the element at the ith position and the smallest element found are 
// different. A counter is used to keep track of the number of moves made.
// selectionsort.h contains my selectionsort implementation as 
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

template<typename a, typename b> // print function for list of pairs
void print(const list<pair<a, b>> &l)
{
	for(auto it = l.begin(); it != l.end(); ++it) // iterate through list
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
}

template<typename c, typename d> // print function for vector of pairs
void print(const vector<pair<c, d>> &l)
{
	for(auto it = l.begin(); it != l.end(); ++it) // iterate through vector
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
}

template<typename T>
void print(const T &l) // print function for vectors and lists
{
	for(auto it = l.begin(); it != l.end(); ++it) // iterate through container
	{
		cout << *it << ' ';
	}
	cout << endl;
}

// function to sort containers
template<typename L>
void selectionsort(L &l)
{
	cout << "pre: ";
	print(l); // print list passed-in
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
			// swap and update counter
			swap(*it1, *minIt);
			counter += 3;
		}
	}
	cout << "post: ";
	print(l); // print sorted list
	cout << "0 copies and " << counter << " moves" << endl; // print moves made
}

#endif