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

#include "selectionsort.h"
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>

using namespace std;

int main()
{
	// Testing selectionsort on a vector
	vector<int> test1;
	test1.push_back(2);
	test1.push_back(4);
	test1.push_back(5);
	test1.push_back(1);
	test1.push_back(8);
	test1.push_back(9);

	selectionsort(test1);
	
	// Testing selectionsort on an empty container
	vector<int> test1_2;
	
	selectionsort(test1_2);
	
	// Testing selectionsort on a vector of pairs
	vector<pair<int, int>> test4;
	pair<int, int> p(1, 2);
	test4.push_back(p);
	pair<int, int> p2(3, -1);
	test4.push_back(p2);
	pair<int, int> p3(-1, 3);
	test4.push_back(p3);
	pair<int, int> p4(0, 0);
	test4.push_back(p4);
	pair<int, int> p5(2, 3);
	test4.push_back(p5);
	pair<int, int> p6(1, 2);
	test4.push_back(p6);
	pair<int, int> p7(1, -2);
	test4.push_back(p7);
	pair<int, int> p8(8, 10);
	test4.push_back(p8);
	
	selectionsort(test4);
	
	// Testing selectionsort on a list of pairs with repeats
	list<pair<int, int>> test5;
	pair<int, int> p9(10, 2);
	pair<int, int> p10(-3, -1);
	pair<int, int> p11(-8, 0);
	pair<int, int> p12(1, 1);
	pair<int, int> p13(1, 1);
	pair<int, int> p14(0, 0);
	pair<int, int> p15(10, 2);
	pair<int, int> p16(5, 5);
	pair<int, int> p17(5, -5);
	pair<int, int> p18(0, 0);
	pair<int, int> p19(10, 2);
	test5.push_back(p9);
	test5.push_back(p10);
	test5.push_back(p11);
	test5.push_back(p12);
	test5.push_back(p13);
	test5.push_back(p14);
	test5.push_back(p15);
	test5.push_back(p16);
	test5.push_back(p17);
	test5.push_back(p18);
	test5.push_back(p19);
	
	selectionsort(test5);
	
	// Testing selectionsort on another list of pairs with repeats
	list<pair<int, int>> test6;
	pair<int, int> p20(-1, 3);
	pair<int, int> p21(0, 0);
	pair<int, int> p22(1, -2);
	pair<int, int> p23(1, 2);
	pair<int, int> p24(1, 2);
	pair<int, int> p25(2, 3);
	pair<int, int> p26(3, -1);
	pair<int, int> p27(8, 10);
	test6.push_back(p20);
	test6.push_back(p21);
	test6.push_back(p22);
	test6.push_back(p23);
	test6.push_back(p24);
	test6.push_back(p25);
	test6.push_back(p26);
	test6.push_back(p27);
	
	selectionsort(test6);
	
	cout << endl;
	cout << "Additional tests" << endl;
	list<int> test2;
	test2.push_back(5);
	test2.push_back(3);
	test2.push_back(1);
	test2.push_back(2);
	
	selectionsort(test2);
	
	// testing selectionsort on an array
	int test3[5];
	test3[0] = 9;
	test3[1] = 2;
	test3[2] = 3;
	test3[3] = 1;
	test3[4] = 5;
	
	int s = sizeof(test3) / sizeof(int);
	selectionsort(test3 , s);
	
	// Testing selectionsort on an array of pairs
	pair<int, int> test11[5];
	pair<int, int> pr1(3, 4);
	pair<int, int> pr2(5, 3);
	pair<int, int> pr3(1, 4);
	pair<int, int> pr4(2, 3);
	pair<int, int> pr5(3, 7);
	test11[0] = pr1;
	test11[1] = pr2;
	test11[2] = pr3;
	test11[3] = pr4;
	test11[4] = pr5;
	
	selectionsort(test11, 5);
	
	cout << endl;
	cout << " - Stability tests - " << endl;
	vector<pair<int, int>> test7;
	pair<int, int> pA(0, 0);
	pair<int, int> pB(1, 8);
	pair<int, int> pC(1, 8);
	
	test7.push_back(pA);
	test7.push_back(pB);
	test7.push_back(pC);
	
	selectionsort(test7);
	
	vector<int> test8;
	test8.push_back(3);
	test8.push_back(2);
	test8.push_back(3);
	
	selectionsort(test8);
	
	list<int> test9;
	test9.push_back(102);
	test9.push_back(124);
	test9.push_back(23);
	test9.push_back(102);
	
	selectionsort(test9);
	
	list<pair<int, int>> test10;
	pair<int, int> pD(10, 3);
	pair<int, int> pE(4, 32);
	pair<int, int> pF(1, 3);
	pair<int, int> pG(1, 3);
	pair<int, int> pH(3, 5);
	pair<int, int> pI(2, 464);
	test10.push_back(pD);
	test10.push_back(pE);
	test10.push_back(pF);
	test10.push_back(pG);
	test10.push_back(pH);
	test10.push_back(pI);
	
	selectionsort(test10);
	
	vector<int> test12;
	test12.push_back(3);
	test12.push_back(6);
	test12.push_back(4);
	test12.push_back(3);
	test12.push_back(785);
	test12.push_back(325);
	test12.push_back(43);
	test12.push_back(12);
	
	selectionsort(test12);
	
	vector<pair<int, int>> test13;
	pair<int, int> pJ(1, 2);
	test13.push_back(pJ);
	test13.push_back(pJ);
	
	selectionsort(test13);
	return 0;
}