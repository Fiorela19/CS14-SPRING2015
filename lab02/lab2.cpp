// Monica Moreno
// 861174030
// April 19, 2015
// lab2.h contains the classes Node and List as well as the forward_list
// functions I implemented. The functions in lab2.h are implemented using
// templates. I implemeted a List class that creates a singly linked list which
// uses the Node class. List is a friend class of Node so that it can access 
// its private data members. I created an additional print function so that I 
// could view the lists while I tested the functions. 
// The forward_list functions I implemented contain the use of iterators which
// are used to traverse the forward_lists when necessary. 
// Additionally, the functions output error messages for corner cases.
// lab2.cpp contains the the helper function isPrime and the recursive function
// primeCount. primeCount makes use of the forward_list functions front, empty, 
// and pop_front.

#include "lab2.h"
#include <iostream>
#include <forward_list>

using namespace std;

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

int primeCount(forward_list<int> lst)
{
	if(lst.empty() == true) return 0; // base case
	else
	{
		if(isPrime(lst.front()) == true) // check if the first value is prime
		{
			lst.pop_front(); // remove the first value in the list
			return 1 + primeCount(lst); // add 1 and call primeCount recursively
		}
		else // if not prime don't add
		{
			lst.pop_front(); // remove the first value in the list
			return primeCount(lst); // call primeCount recursively 
		}
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
	cout << "List: ";
	print(l5);
	cout << endl;
	cout << "printLots: ";
	printLots(l5, l6);
	cout << endl;
	
	forward_list<int> l7;
	l7.push_front(9);
	forward_list<int> l8;
	for(int i = 50; i >= 5; i -= 5) l8.push_front(i);
	cout << "List: ";
	print(l8);
	cout << endl;
	cout << "positions: ";
	print(l7);
	cout << endl;
	cout << "printLots: ";
	printLots(l8, l7);
	cout << endl;
	l7.push_front(4);
	cout << "positions: ";
	print(l7);
	cout << endl;
	cout << "printLots: ";
	printLots(l8, l7);
	cout << endl;
	l7.push_front(0);
	cout << "positions: ";
	print(l7);
	cout << endl;
	cout << "printLots: ";
	printLots(l8, l7);
	cout << endl;
	cout << "Testing for out of bounds error" << endl;
	forward_list<int> l9;
	l9.push_front(10);
	printLots(l8, l9);
	l9.push_front(3);
	printLots(l8, l9); // should give an error
	
	cout << "Testing elementSwap" << endl;
	cout << "Testing swap on a list of size 0" << endl;
	List<int> l11;
	l11.elementSwap(0);
	cout << "Testing swap on a list of size 1" << endl;
	List<int> l12;
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
	List<int> l10;
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
	
	cout << "Testing elementSwap on a list of chars" << endl;
	List<char> l15;
	l15.push('g');
	l15.push('e');
	l15.push('k');
	l15.push('j');
	l15.push('t');
	l15.push('j');
	l15.push('r');
	
	cout << "Original: ";
	l15.display();
	cout << endl;
	l15.elementSwap(5);
	l15.display();
	cout << endl;
	
	cout << "Testing elementSwap on a list of chars at the begining" << endl;
	l15.elementSwap(0);
	l15.display();
	cout << endl;
	
	cout << "Testing elementSwap on a list of chars at the middle" << endl;
	l15.elementSwap(3);
	l15.display();
	cout << endl;
	
	cout << "Testing corner case" << endl;
	l15.elementSwap(-1); // should give an error
	l15.elementSwap(9); // should give an error
	
	cout << "Testing listCopy on a list of chars" << endl;
	forward_list<char> l16;
	l16.push_front('c');
	l16.push_front('a');
	l16.push_front('v');
	l16.push_front('e');
	
	forward_list<char> l17;
	l17.push_front('t');
	l17.push_front('j');
	
	listCopy(l16, l17);
	print(l17);
	cout << endl;
	forward_list<int> l18;
	l18.push_front(3);
	l18.push_front(2);
	printLots(l17, l18);
	cout << endl;
	
	cout << "Testing listCopy when the first list passed-in is empty" << endl;
	forward_list<char> l19;
	cout << "List being changed: ";
	print(l17);
	cout << endl;
	listCopy(l19, l17);
	cout << "After using listCopy: ";
	print(l17);
	cout << endl;
	
	cout << "Testing when the second list passed-in is empty" << endl;
	cout << "List being changed: ";
	print(l19);
	cout << endl;
	cout << "List being copied: ";
	print(l17);
	cout << endl;
	listCopy(l17, l19);
	cout << "After using listCopy: ";
	print(l19);
	cout << endl;
	
	cout << "Testing printLots on a list of characters" << endl;
	forward_list<int> l20;
	l20.push_front(-1);
	printLots(l19, l20); // should output an error;
	forward_list<int> l21;
	l21.push_front(5);
	l21.push_front(3);
	l21.push_front(0);
	cout << "List: ";
	print(l19);
	cout << endl;
	cout << "positions: ";
	print(l21);
	cout << endl;
	cout << "using printLots: ";
	printLots(l19, l21);
	cout << endl;
	
	cout << "Testing primeCount again" << endl;
	forward_list<int> l22;
	l22.push_front(3);
	l22.push_front(2);
	l22.push_front(7);
	l22.push_front(3);
	l22.push_front(5);
	l22.push_front(51);
	
	print(l22);
	cout << endl;
	cout << "primeCount: " << primeCount(l22) << endl;
	
	cout << "Testing primeCount on an empty list" << endl;
	forward_list<int> l23;
	cout << "primeCount: " << primeCount(l23) << endl;
	
	cout << "Testing primeCount on a list of size 1" << endl;
	l23.push_front(5);
	cout << "primeCount: " << primeCount(l23) << endl;
	return 0;
}