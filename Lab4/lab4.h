// Monica Moreno
// 861174030
// May 2, 2015
// Approach: I implemented the function preorder which lists the coprime pairs
// in the tree of coprime pairs in a preorder traversal. Only the pairs whose
// sum is smaller than some integer k which is passed in as an argument are 
// printed. The function calls the helper function preorder_ which calls itself 
// recursively to traverse the tree and print the pairs. I also implemented the
// function postorder which uses the same approach as preorder with the only 
// difference being that the helper function(postorder_) has the print statement
// after the recursive calls instead of before the recursive calls. I 
// implemented a class called priority_queue in order to store the coprime pairs
// in sorted order. The class priority_queue's data member is a vector of 
// integer pairs. The class contains four member functions: front, pop, push, 
// and print_q. I implemented a funcion called sorted which prints out all the 
// coprime pairs whose sum is smaller than some argument k in sorted order. The
// function sorted calls its helper function(sorted_) which calls itself
// recursively to push the coprime pairs onto the priority_queue.
// The priority_queue which contains the pairs is then printed. The file
// lab4.h contains the implementations and main.cc contains the testcases.

#ifndef __LAB4_H__
#define __LAB4_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Entry;
class priority_queue {
	public:
	vector<Entry> entries;
	Entry& front() { return entries.back(); }
	void pop() { entries.pop_back(); }
	void push( Entry e ) 
	{ 
		entries.push_back( e );
		// compares the pairs in order to sort them in the vector
		for (int i = entries.size()-1; i != 0; --i )
		{
			if ( entries[i].first + entries[i].second >= entries[i-1].first
			+ entries[i-1].second) break;
			swap(entries[i], entries[i-1]); // swaps the pairs to sort them
		}
	}
	void print_q() 
	{
		// loop to print the pairs in the vector(priority_queue)
		for ( unsigned i = 0; i < entries.size(); ++i)
		{
			cout << entries[i].first << ' ' << entries[i].second << endl;
		}
	}
};

void sorted_(int m, int n, int k, priority_queue& q) // sorted helper function
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		Entry t(m, n);
		q.push(t); // push the pair onto the queue
		// recursively call sorted_ three times using the formulas given
		sorted_(2 * m - n, m, k, q);
		sorted_(2 * m + n, m, k, q);
		sorted_(m + 2 * n, n, k, q);
	}
}

void sorted(int num) // function to print coprime pairs in sorted order
{
	priority_queue qu; // create que to pass into the sorted helper function
	sorted_(2, 1, num, qu); // call the helper function
	sorted_(3, 1, num, qu); // call the helper function
	qu.print_q(); // print the queue
}

void preorder_(int m, int n, int k) // preorder helper function
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		cout << m << ' ' << n << endl; // print the coprime pair
		// recursively call preorder_ three times using the given formulas
		preorder_(2 * m - n, m, k);
		preorder_(2 * m + n, m, k);
		preorder_(m + 2 * n, n, k);
	}
}

void preorder(int num) // function to print coprime pairs in preorder traversal
{
	// call the preorder helper function(preorder_)
	preorder_(2, 1, num);
	preorder_(3, 1, num);
}

void postorder_(int m, int n, int k) // postorder helper function 
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		// recursively call postorder_ three times
		postorder_(2 * m - n, m, k);
		postorder_(2 * m + n, m, k);
		postorder_(m + 2 * n, n, k);
		cout << m << ' ' << n << endl; // print the coprime pair
	}
}

void postorder(int num) //function to print coprime pairs in postorder traversal
{
	// call the postorder helper function(postorder_)
	postorder_(2, 1, num);
	postorder_(3, 1, num);
}

#endif
