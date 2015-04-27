// Monica Moreno
// 861174030
// April 25, 2014
// Approach:
// I implemented the class TwoStackFixed for two stacks which are contained 
// in a single array. The private data members of TwoStackFixed are a pointer
// to the array and four ints. Top1 is a variable for the position after the
// top of stack1 and top2 is for the position after the top of stack2. The
// variable sz contains the size of the array and mxt contains the position of 
// maxtop. I used the helper functions to check if a stack was full or empty 
// before calling push and pop. After every push and pop on a stack, I updated
// the variable that contains the position after the top of the stack(top1 and
// top2). If pop or push are called when it is invalid to do so, an error
// message is printed. I also implemented the class TwoStackOptimal which uses 
// the same approach as TwoStackFixed except that TwoStackOptimal does not have
// a maxtop. The function showTowerStates solves the puzzle of the Tower of
// Hanoi. It is a function that uses stacks which calls recursive helper 
// functions (one which prints the movements of the disks and another which
// moves the disks) to move the disks from the source to the desination.

#ifndef __LAB3_H__
#define __LAB3_H__

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

template <typename T>
class TwoStackFixed
{
	private:
	T *arr; // points to the dynamically created array
	int top1; // keeps track of the position after the top of stack1
	int top2; // keeps track of the position after the top of stack2
	int sz; // the size of the array
	int mxt; // the position of maxtop
		
	bool isFullStack1() // returns true if stack1 is full
	{
		// stack1 is full if top1 is the position after the maxtop
		// or if top1 is -1
		if(top1 == mxt + 1 || top1 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isFullStack2() // returns true if stack2 is full
	{
		// stack2 is full if top2 is the position of maxtop
		// or if top2 is -1
		if(top2 == mxt || top2 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isEmptyStack1() // returns true if stack1 is empty
	{
		// stack1 is empty if top1 is the first position
		// or if top1 is -1
		if(top1 == 0 || top1 == -1)
		{
			return true;
		}
		else return false;
	}
	
	bool isEmptyStack2() // returns true if stack2 is empty
	{
		// stack2 is empty if top2 is the position of the last element in the
		// array or if top2 is -1
		if(top2 == sz - 1 || top2 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public:
	
	// construct the array and two stacks
	TwoStackFixed(int size, int maxtop)
	:arr(0), top1(0), top2(size - 1), sz(size), mxt(maxtop)
	{
		if(maxtop >= size) // checking if maxtop is past the last valid position
		{
			top1 = 0; // top1 is initially 
			top2 = -1;//assign -1 to top2 to know that stack1 takes up the array
			mxt = size - 1; // maxtop is the last valid position
		}
		else if(maxtop < 0) // if maxtop < 0, stack2 takes up the entire array
		{
			top1 = -1;//assign -1 to top1 to know that stack2 takes up the array
			top2 = size - 1; // top2 is initially the last position
			mxt = 0; // maxtop is the first position in the array
		}
		else
		{
			top1 = 0; // top1 is the first position in the array
			top2 = size - 1; // top2 is the last position in the array
			mxt = maxtop; // mxt is the maxtop passed-in
		}
		arr = new T[size]; // creates the array aka both stacks
		sz = size; // sets sz to the size passed-in
	}

	
	void pushStack1(T value)
	{
		if(isFullStack1()) // if stack1 is full output an error
		{
			cout << "Error. Stack1 is full." << endl;
			return;
		}
		arr[top1] = value; // add the value to Stack1
		++top1; // update top1
		display(); // display the contents in stacks
	}
	
	void pushStack2(T value)
	{
		if(isFullStack2()) // if stack2 is full output an error
		{
			cout << "Error. Stack2 is full." << endl;
			return;
		}
		arr[top2] = value; // add the value to Stack2
		--top2; // update top2
		display(); // display the contents in the stack
	}
	
	T popStack1()
	{
		if(isEmptyStack1()) // if stack1 is full output an error
		{
			cout << "Error. Stack1 is empty." << endl;
			exit(-1); // exiting program
		}
		--top1; // update top1
		return arr[top1]; // return the value that was removed
	}
	
	T popStack2()
	{
		if(isEmptyStack2()) // if stack2 is full output an error
		{
			cout << "Error. Stack2 is empty." << endl;
			exit(-1); // exiting program
		}
		++top2; // update top2
		return arr[top2]; // return the value that was removed
	}
	
	void display() // displays the contents of both arrays
	{
		// prints a space where there is no value in the stacks
		int i;
		for(i = 0; i < top1; ++i) 
		{
			cout << arr[i] << ' ';
		}
		int j;
		for(j = i; j <= top2; ++j)
		{
			cout << "  "; // whitespace for unused array space
		}
		int k;
		for(k = j; k < sz; ++k)
		{
			cout << arr[k] << ' ';
		}
		cout << endl;
	}
};

template <typename T>
class TwoStackOptimal
{
	private:
	T *arr;
	int top1;
	int top2;
	int sz;
		
	bool isFullStack1()
	{
		// stack1 is full if top1 is the position of the last value in stack2
		if(top1 == top2 + 1)
		{
			return true;
		}
		else if(top1 == sz) // can also be full is it reached the end of array
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isFullStack2()
	{
		// stack2 is full if top1 is the position of the last value in stack2
		if(top1 == top2 + 1)
		{
			return true;
		}
		else if (top2 == -1) // can also be full if top2 is past the left bound
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	bool isEmptyStack1()
	{
		if(top1 == 0) // stack1 is empty if top1 is the first position
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isEmptyStack2()
	{
		if(top2 == sz - 1) // stack2 is empty if top2 is the last position
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public:
	TwoStackOptimal(int size)
	: arr(0), top1(0), top2(size - 1), sz(size)
	{
		if(size < 0) // check that size is valid
		{
			cout << "Error. A negative int was inputed for the size." << endl;
			exit(-1); // exiting program
		}
		arr = new T[size]; // create an array of that size
	}
		
	void display()
	{
		int i;
		for(i = 0; i < top1; ++i)
		{
			cout << arr[i] << ' ';
		}
		int j;
		for(j = i; j <= top2; ++j)
		{
			cout << "  "; // whitespace for unused array space
		}
		int k;
		for(k = j; k < sz; ++k)
		{
			cout << arr[k] << ' ';
		}
		cout << endl;
	}
	
	void pushFlexStack1(T value)
	{
		if(isFullStack1()) // check if stack1 is full
		{
			cout << "Error. Stack1 is full." << endl;
			return;
		}
		arr[top1] = value; // add the value to Stack1
		++top1; // update top1
		display(); // display the contents
	}
	
	void pushFlexStack2(T value)
	{
		if(isFullStack2()) // check that stack2 is not full
		{
			cout << "Error. Stack2 is full." << endl;
			return;
		}
		arr[top2] = value; // add the value to Stack2
		--top2; // update top2
		display(); // display the contents
	}
	
	T popFlexStack1()
	{
		if(isEmptyStack1()) // check that stack1 is not empty
		{
			cout << "Error. Stack1 is empty." << endl;
			exit(-1); // exiting program
		}
		--top1; // update top1
		return arr[top1]; // return the value that was removed
	}
	
	T popFlexStack2()
	{
		if(isEmptyStack2()) // check that stack2 is not empty
		{
			cout << "Error. Stack2 is empty." << endl;
			exit(-1); // exiting program
		}
		++top2; // update top2
		return arr[top2]; // return the value that was removed
	}
	
};

template <typename T>
void printT(stack<T> tmp) // function to print the stack
{
    if(tmp.size() == 0) // base case
    {
        return;
    }
    else
    {
        cout << tmp.top() << " "; // print the top and then pop it off
        tmp.pop();
        printT(tmp); // recursively call the function
    }
}

// helper function that prints the movements
void showTowerStates(int n, char a, char b, char c)
{
	if(n == 1) // base case
	{
		cout << "Moved " << n << " from peg " << a << " to peg " << b << endl;
		return;
	}
	else
	{
		showTowerStates(n - 1, a, c, b); // recursive call
		cout << "Moved " << n << " from peg " << a << " to peg " << b << endl;
		showTowerStates(n - 1, c, b, a); // recursive call
	}
}

// helper function to solve the Tower of Hanoi problem
template <typename T>
void showTowerStates2(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
	if(n == 1) // base case
	{
		C.push(A.top()); // moves A's top to C
		A.pop();
		return;
	}
	else
	{
		showTowerStates2(n - 1, A, C, B); // recursive call
		C.push(A.top()); // move A's top to C
		A.pop();
		showTowerStates2(n - 1, B, A, C); // recursive call
	}
}

// function to solve the Tower of Hanoi problem
template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
	showTowerStates(n, 'A', 'C', 'B'); // call helper function that prints moves
	showTowerStates2(n, A, B, C); // call helper function showTowerStates2
}

#endif
