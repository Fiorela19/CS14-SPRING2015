#include "lab2.h"
#include <iostream>
#include <forward_list>

using namespace std;

typedef int Type;

// int primeCount(forward_list<int> lst)
// {
// 	forward_list<int>::iterator itt = lst.begin;
// 	int counter;
// }
// int primeCount(foward_list<int> &lst, int count, forward_list<int>::ite)

bool isPrime(int i) // checks if a number is prime
{
	if(i <= 1) return false; // 0, 1, and negative numbers are not prime
	else 
	{
		// check the ints between 2 and i - 1 and check if one divides i evenly
		for(int j = 2; j < i; ++j)
		{
			// if a number that divides i without a remainer is found, i 
			// is not prime
			if(i % j == 0)
			{
				return false;
			}
		}
		return true;
	}
}

// copies list L into P in reverse order
void listCopy(forward_list<Type> L, forward_list<Type> &P)
{
	P.resize(0); // resize P to size 0
	forward_list<Type>::iterator it;
	for(it = L.begin(); it != L.end(); it++)
	{
		//push front all of L's values onto P so that they will be reversed in P
		P.push_front(*it);
	}
}

void printLots(forward_list<Type> L, forward_list<int> P)
{
	int positionInL = 0;
	forward_list<Type>::iterator itL = L.begin(); // iterator for list L
	forward_list<int>::iterator itP = P.begin(); // iterator for list P
	for(itL = L.begin(); itL != L.end(); itL++) // print each value in a list
	{
		if(itP == P.end()) break; //if end of list P is reached break from loop
		if(*itP == positionInL) // if at the position in L print the value
		{
			cout << *itL << ' ';
			itP++; // increment itP
		}
		positionInL++; // increment positionInL
	}
}

void print(forward_list<Type> &L) // prints out the values in a list
{
	forward_list<Type>::iterator itt;
	for(itt = L.begin(); itt != L.end(); itt++) // print each value in a list
	{
		cout << *itt << ' ';
	}
}

int main()
{
	cout << "Testing isPrime" << endl;
	int num = 49;
	cout << "Is " << num << " prime? " << isPrime(num) << endl;
	num = 1;
	cout << "Is " << num << " prime? " << isPrime(num) << endl;
	num = 23;
	cout << "Is " << num << " prime? " << isPrime(num) << endl;
	num = 89;
	cout << "Is " << num << " prime? " << isPrime(num) << endl;
	num = 94;
	cout << "Is " << num << " prime? " << isPrime(num) << endl;
	
	forward_list<int> l1;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l1.push_front(4);
	
	forward_list<int> l2;
	l2.push_front(4);
	l2.push_front(5);
	
	cout << "Testing listCopy function" << endl;
	listCopy(l1, l2);
	cout << "List that is being copied: ";
	print(l1);
	cout << endl;
	cout << "List that was changed: ";
	print(l2);
	cout << endl;
	
	forward_list<int> l3;
	l3.push_front(10);
	l3.push_front(20);
	l3.push_front(90);
	l3.push_front(40);
	
	listCopy(l3, l2);
	cout << "List that is being copied: ";
	print(l3);
	cout << endl;
	cout << "List that was changed: ";
	print(l2);
	cout << endl;
	
	cout << "Testing listCopy when the list being copied is empty" << endl;
	forward_list<int> l4;
	listCopy(l4, l2);
	cout << "List that was changed: ";
	print(l2); // should be empty
	cout << endl;
	
	cout << "Testing listCopy when the list being changed is empty" << endl;
	forward_list<int> l5;
	listCopy(l3, l5);
	cout << "List that was changed: ";
	print(l5);
	cout << endl;
	
	cout << "Testing printLots" << endl;
	forward_list<int> l6;
	l6.push_front(3);
	l6.push_front(0);
	print(l5);
	cout << endl;
	printLots(l5, l6);
	cout << endl;
	
	forward_list<int> l7;
	l7.push_front(10);
	forward_list<int> l8;
	for(int i = 50; i >= 5; i -= 5) l8.push_front(i);
	print(l8);
	cout << endl;
	printLots(l8, l7);
	cout << endl;
	// l7.push_front(4);
	// printLots(l8, l7);
	// cout << endl;
	// l7.push_front(0);
	// printLots(l8, l7);
	// cout << endl;
	
	return 0;
}