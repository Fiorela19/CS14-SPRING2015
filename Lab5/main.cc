// Monica Moreno
// 861174030
// May 9, 2015
// Approach: I modified my BST class implementation by adding additional
// functions. I implemented the function minCover which finds the smallest 
// vertex cover of the tree. I added the data member selected in the Node class 
// to keep track of which nodes are selected as part of the vertex cover. To 
// find the minimum cover, for each leaf in the tree, I select its parent(this 
// is done in the function minCoverLeaf). Additionally, I select each internal 
// node if any of its children are not selected(this is done in the function
// minCoverParent). I also implemented the function displayMinCover to display 
// the smallest vertex cover and its size. I implemented the function 
// findSumPath to display all of the paths to the passed-in sum. Its helper 
// function uses a counter to keep track of the position of the last value that
// was put into the buffer. The sum is decremented by the value of each node in
// the path using recursion. A path is found if the sum is 0 when a leaf is 
// reached. Otherwise, a path was not found. If no paths are found, a 0 is
// printed. The helper function print_path is used to print the values in the 
// buffer when a path is found. The function vertSum finds the vertical sums of
// the nodes that are in the same vertical line. The function calls its helper 
// function which recursively calls itself to insert all the Node values into 
// the passed-in map. After the map is filled with the Node values, the values 
// are printed.

#include "lab5.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cout << "Testcase1" << endl;
	BST<int> test1;
	test1.insert(50);
	test1.insert(20);
	test1.insert(10);
	test1.insert(40);
	test1.insert(35);
	test1.insert(45);
	test1.insert(60);
	test1.insert(70);
	
	cout << "Part 1" << endl;
	test1.minCover();
	test1.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr1[100];
	test1.findSumPath(test1.root, 80, arr1);
	
	cout << "Part 3" << endl;
	map<int, int> m1;
	test1.vertSum(test1.root, 0, m1);
	
	cout << endl;
	cout << "Testcase2" << endl;
	BST<int> test2;
	test2.insert(15);
	test2.insert(10);
	test2.insert(13);
	test2.insert(12);
	test2.insert(14);
	test2.insert(5);
	test2.insert(7);
	test2.insert(2);
	test2.insert(1);
	test2.insert(20);
	test2.insert(17);
	test2.insert(25);
	test2.insert(23);
	
	cout << "Part 1" << endl;
	test2.minCover();
	test2.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr2[100];
	test2.findSumPath(test2.root, 33, arr2);
	
	cout << "Part 3" << endl;
	map<int, int> m2;
	test2.vertSum(test2.root, 0, m2);
	
	cout << endl;
	cout << "Testcase3" << endl;
	BST<int> test3;
	test3.insert(10);
	test3.insert(15);
	test3.insert(9);
	test3.insert(5);
	test3.insert(1);
	
	cout << "Part 1" << endl;
	test3.minCover();
	test3.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr3[100];
	test3.findSumPath(test3.root, 25, arr3);
	
	cout << "Part 3" << endl;
	map<int, int> m3;
	test3.vertSum(test3.root, 0, m3);
	
	cout << endl;
	cout << "Testcase4" << endl;
	BST<int> test4;
	test4.insert(15);
	test4.insert(35);
	test4.insert(10);
	test4.insert(11);
	test4.insert(14);
	test4.insert(9);
	test4.insert(8);
	test4.insert(6);
	test4.insert(2);
	
	cout << "Part 1" << endl;
	test4.minCover();
	test4.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr4[100];
	test4.findSumPath(test4.root, 50, arr4);
	
	cout << "Part 3" << endl;
	map<int, int> m4;
	test4.vertSum(test4.root, 0, m4);
	
	cout << endl;
	cout << "Testcase5" << endl;
	BST<int> test5;
	test5.insert(100);
	
	cout << "Part 1" << endl;
	test5.minCover();
	test5.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr5[100];
	test5.findSumPath(test5.root, 100, arr5);
	
	cout << "Part 3" << endl;
	map<int, int> m5;
	test5.vertSum(test5.root, 0, m5);
	
	cout << endl;
	cout << "Testcase6" << endl;
	BST<int> test6;
	test6.insert(40);
	test6.insert(30);
	
	cout << "Part 1" << endl;
	test6.minCover();
	test6.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr6[100];
	test6.findSumPath(test6.root, 60, arr6);
	
	cout << "Part 3" << endl;
	map<int, int> m6;
	test6.vertSum(test6.root, 0, m6);
	
	cout << endl;
	cout << "Testcase7" << endl;
	BST<int> test7;
	test7.insert(70);
	test7.insert(60);
	test7.insert(50);
	test7.insert(40);
	test7.insert(30);
	test7.insert(110);
	test7.insert(140);
	test7.insert(150);
	
	cout << "Part 1" << endl;
	test7.minCover();
	test7.displayMinCover();
	
	cout << "Part 2" << endl;
	int arr7[100];
	test7.findSumPath(test7.root, 250, arr7);
	
	cout << "Part 3" << endl;
	map<int, int> m7;
	test7.vertSum(test7.root, 0, m7);
	
	return 0;
}