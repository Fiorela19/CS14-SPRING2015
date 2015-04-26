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

#include "lab3.h"
#include <iostream>

using namespace std;

int main()
{
	// int size;
	// int max;
	// cout << "Enter the size: ";
	// cin >> size;
	// cout << "Enter the maxtop: ";
	// cin >> max;
	
	// TwoStackFixed test1(size, max);
	
	cout << " - Testing TwoStackFixed" << endl;
	TwoStackFixed<int> test2(4, 2);
	cout << "Test pushStack1" << endl;
	test2.pushStack1(2);
	test2.pushStack1(3);
	test2.pushStack1(4);
	
	cout << "Test pushStack2" << endl;
	test2.pushStack2(5);
	test2.pushStack2(8); // should cause an error
	
	cout << "Testing popStack1" << endl;
	cout << "Value popped off: " << test2.popStack1() << endl;
	cout << "Value popped off: " << test2.popStack1() << endl;
	cout << "Testing popStack2" << endl;
	cout << "Value popped off: " << test2.popStack2() << endl;
	// cout << "Value popped of: " << test2.popStack2() << endl; // exits prog.
	
	TwoStackFixed<int> test3(8, 6);
	test3.pushStack1(6);
	test3.pushStack1(5);
	test3.pushStack1(2);
	test3.pushStack2(7);
	test3.pushStack2(9); // should output an error
	cout << "Testing display" << endl;
	test3.display();
	cout << endl;
	
	cout << " - Testing TwoStackOptimal class" << endl;
	TwoStackOptimal<int> test4(5);
	test4.pushFlexStack1(3);
	test4.pushFlexStack1(4);
	test4.pushFlexStack1(7);
	test4.pushFlexStack2(9);
	test4.pushFlexStack2(1);
	test4.pushFlexStack2(11); // should output an error
	test4.display();
	cout << endl;
	
	cout << "Test TwoStackOptimal when stack1 takes up the entire array";
	cout << endl;
	TwoStackOptimal<int> test5(3);
	test5.pushFlexStack1(2);
	test5.pushFlexStack1(4);
	test5.pushFlexStack1(8);
	test5.pushFlexStack1(3); // should give an error
	test5.pushFlexStack2(6); // should give an error
	
	cout << "Test TwoStackOptimal when stack2 takes up the entire array";
	cout << endl;
	TwoStackOptimal<int> test6(4);
	test6.pushFlexStack2(6);
	test6.pushFlexStack2(7);
	test6.pushFlexStack2(3);
	test6.pushFlexStack2(2);
	test6.pushFlexStack2(1); // should give an error
	test6.pushFlexStack1(8); // should give an error
	
	cout << "More tests for TwoStackOptimal" << endl;
	TwoStackOptimal<int> test7(5);
	test7.pushFlexStack1(3);
	test7.pushFlexStack1(93);
	test7.pushFlexStack1(45);
	test7.pushFlexStack2(33);
	test7.pushFlexStack2(21);
	cout << "Value popped off: " << test7.popFlexStack1() << endl;
	test7.display();
	cout << endl;
	cout << "Value popped off: " << test7.popFlexStack2() << endl;
	test7.display();
	cout << endl;
	
	cout << "Testing the push functions again" << endl;
	test7.pushFlexStack1(90);
	test7.pushFlexStack2(43);
	test7.pushFlexStack1(48); // should give an error
	test7.pushFlexStack2(86); // should give an error
	
	cout << "Testing pop when the first stack takes up the entire array";
	cout << endl;
	TwoStackOptimal<int> test8(6);
	test8.pushFlexStack1(1);
	test8.pushFlexStack1(54);
	test8.pushFlexStack1(84);
	test8.pushFlexStack1(47);
	test8.pushFlexStack1(14);
	test8.pushFlexStack1(19);
	test8.pushFlexStack2(32); // should say that stack2 is full
	// test8.popFlexStack2(); // should say that stack2 is empty, exits program
	cout << "Value popped off: " << test8.popFlexStack1() << endl;
	
	cout << "Testing pop when the second stack takes up the entire array";
	cout << endl;
	TwoStackOptimal<int> test9(3);
	test9.pushFlexStack2(93);
	test9.pushFlexStack2(63);
	test9.pushFlexStack2(52);
	// test9.popFlexStack1(); // should say that stack 1 is empty, exits program
	test9.pushFlexStack2(4); // should say that stack2 is full
	test9.pushFlexStack1(3); // should say that stack1 is full
	cout << "Value popped off: " << test9.popFlexStack2() << endl;
	
	cout << "Testing stacks of chars" << endl;
	TwoStackFixed<char> test10(4, 2);
	test10.pushStack1('a');
	test10.pushStack1('j');
	test10.pushStack1('k');
	test10.pushStack2('e');
	test10.pushStack2('r'); // should say stack2 is full
	cout << "Value popped off: " << test10.popStack1() << endl;
	
	cout << "Testing Tower of Hanoi" << endl;
	stack<int> A;
	A.push(3);
	A.push(2);
	A.push(1);
	stack<int> B;
	stack<int> C;
	cout << "stack: ";
	printT(A);
	cout << endl;
	showTowerStates(3, A, B, C);
	cout << "Final: ";
	printT(C);
	cout << endl;
	
	cout << "Testing another Tower of Hanoi" << endl;
	stack<int> A2;
	A2.push(4);
	A2.push(3);
	A2.push(2);
	A2.push(1);
	stack<int> B2;
	stack<int> C2;
	cout << "stack: ";
	printT(A2);
	cout << endl;
	showTowerStates(4, A2, B2, C2);
	cout << "Final: ";
	printT(C2);
	cout << endl;
	return 0;
}
