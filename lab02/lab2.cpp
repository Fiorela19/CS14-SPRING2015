#include "lab2.h"
#include <iostream>
#include <forward_list>

using namespace std;

typedef int Type;

int primeCount(forward_list<int> lst)
{
	forward_list<int>::iterator itt = lst.begin();
	
	int tot = primeCount(lst, itt);
	
	return tot;
}

int primeCount(forward_list<int> lst, forward_list<int>::iterator &it)
{
	if(it == lst.end()) // base case if the end of the list is reached
	{
		return 0;
	}
	else if(isPrime(*it) == true) // if the value pointed to by it is prime
	{
		// add 1 to the count and recursively call primeCount 
		return 1 + primeCount(lst, ++it); // increment it
	}
	else
	{
		// don't add 1 to the count and recusively call primeCount
		return primeCount(lst, ++it);
	}
	return -1; // to avoid error of reaching a non void function
}

bool isPrime(int i) // checks if a number is prime
{
	if(i <= 1) return false; // 0, 1, and negative numbers are not prime
	else 
	{
		// check the ints between 2 and i - 1 and check if one divides i evenly
		for(int j = 2; j < i; ++j)
		{
			// if a number that divides i without a remainer is found, 
			// that means is not prime
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
	for(it = L.begin(); it != L.end(); ++it)
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
	for(itL = L.begin(); itL != L.end(); itL++) // print the values in list
	{
		if(itP == P.end()) break; //if end of list P is reached break from loop
		if(*itP == positionInL) 
		{
			// print the value of L at position specified by P
			cout << *itL << ' ';
			itP++; // increment itP
		}
		positionInL++; // increment positionInL
	}
	forward_list<Type>::iterator itLS = L.begin();
	int sizeL = 0;
	// count the number of elements in list L
	for(itLS = L.begin(); itLS != L.end(); itLS++)
	{
		sizeL++;
	}
	forward_list<Type>::iterator itPS = P.begin();
	for(itPS = P.begin(); itPS != P.end(); itPS++)
	{
		 // check if any of the positions specified by P are out of bounds
		if(*itPS >= sizeL)
		{
			cout << "Error. Trying to access a position that is out of bounds";
			cout << endl;
			break;
		}
	}
}

void print(forward_list<Type> &L) // prints out the values in a list
{
	forward_list<Type>::iterator itt;
	for(itt = L.begin(); itt != L.end(); ++itt) // print each value in a list
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
	l7.push_front(9);
	forward_list<int> l8;
	for(int i = 50; i >= 5; i -= 5) l8.push_front(i);
	print(l8);
	cout << endl;
	printLots(l8, l7);
	cout << endl;
	l7.push_front(4);
	printLots(l8, l7);
	cout << endl;
	l7.push_front(0);
	printLots(l8, l7);
	cout << endl;
	cout << "Testing for out of bounds error" << endl;
	forward_list<int> l9;
	l9.push_front(10);
	printLots(l8, l9);
	
	cout << "Testing elementSwap" << endl;
	cout << "Testing swap on a list of size 0" << endl;
	List l11;
	l11.elementSwap(0);
	cout << "Testing swap on a list of size 1" << endl;
	List l12;
	l12.push(5);
	l12.elementSwap(0);
	cout << "Testing swap on a list of size 2" << endl;
	l12.push(4);
	l12.elementSwap(1);
	cout << "Original: ";
	l12.display();
	cout << endl;
	l12.elementSwap(0);
	cout << "Changed: ";
	l12.display();
	cout << endl;
	cout << "Testing elementSwap on a list with several elements" << endl;
	List l10;
	l10.push(1);
	l10.push(30);
	l10.push(45);
	l10.push(64);
	l10.push(32);
	cout << "Original: ";
	l10.display();
	cout << endl;
	l10.elementSwap(0);
	l10.display();
	cout << endl;
	cout << "Testing elementSwap in the middle" << endl;
	l10.elementSwap(2);
	l10.display();
	cout << endl;
	cout << "Testing elementSwap at the end" << endl;
	l10.elementSwap(3);
	l10.display();
	cout << endl;
	l10.elementSwap(4);
	l10.elementSwap(-3);
	
	cout << "Testing primeCount function" << endl;
	forward_list<int> l13;
	l13.push_front(4);
	l13.push_front(3);
	l13.push_front(0);
	l13.push_front(78);
	l13.push_front(13);
	l13.push_front(4);
	
	cout << "Prime count: " << primeCount(l13) << endl;
	
	forward_list<int> l14;
	l14.push_front(4);
	l14.push_front(3);
	l14.push_front(11);
	l14.push_front(78);
	l14.push_front(13);
	l14.push_front(17);
	
	cout << "Prime count: " << primeCount(l14) << endl;
	return 0;
}