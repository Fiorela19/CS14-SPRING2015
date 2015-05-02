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

#include "lab4.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	// if there is an invalid number of arguments, an error message is printed
	// and the program is exited
	if(argc != 2)
	{
		cout << "Invalid number of arguments. Exiting program." << endl;
		exit(-1); // exit the program
	}
	
	int num = atoi(argv[1]); // store the number given in the command line
	
	cout << "pre-order" << endl;
	preorder(num);
	cout << endl;
	
	cout << "post-order" << endl;
	postorder(num);
	cout << endl;
	
	cout << "sorted" << endl;
	sorted(num);
	cout << endl;
	
	// cout << "Testing pre-order" << endl;
	// cout << "0: " << endl;
	// preorder(0);
	// cout << endl;
	// cout << "1: " << endl;
	// preorder(1);
	// cout << endl;
	// cout << "2: " << endl;
	// preorder(2);
	// cout << endl;
	// cout << "3: " << endl;
	// preorder(3);
	// cout << endl;
	// cout << "4: " << endl;
	// preorder(4);
	// cout << endl;
	// cout << "9: " << endl;
	// preorder(9);
	// cout << endl;
	
	// cout << "Testing post-order" << endl;
	// cout << "0: " << endl;
	// postorder(0);
	// cout << endl;
	// cout << "1: " << endl;
	// postorder(1);
	// cout << endl;
	// cout << "2: " << endl;
	// postorder(2);
	// cout << endl;
	// cout << "3: " << endl;
	// postorder(3);
	// cout << endl;
	// cout << "4: " << endl;
	// postorder(4);
	// cout << endl;
	// cout << "9: " << endl;
	// postorder(9);
	// cout << endl;
	
	// cout << "Testing sorted" << endl;
	// cout << "0: " << endl;
	// sorted(0);
	// cout << endl;
	// cout << "1: " << endl;
	// sorted(1);
	// cout << endl;
	// cout << "2: " << endl;
	// sorted(2);
	// cout << endl;
	// cout << "3: " << endl;
	// sorted(3);
	// cout << endl;
	// cout << "4: " << endl;
	// sorted(4);
	// cout << endl;
	// cout << "9: " << endl;
	// sorted(9);
	
	return 0;
}
