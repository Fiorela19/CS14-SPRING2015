// Monica Moreno
// 861174030
// May 25, 2015
// Approach: I implemented three function to find the average runtimes for 
// inserting and finding strings in trees(set) and hash tables(unordered set).
// The function insertRun makes use of templates and returns the time it takes
// to insert n words(n being the number entered as a command line argument)
// into a set and unordered set. The function findRun also makes use of 
// templates and returns the time it takes to lookup n words in a set and
// unordered set. The function findAvg finds the average time of 
// inserting or finding n words. The function shuffle uses rand() to shuffle
// the strings in a vector by swaping words at random positions. In main, 
// I use the functions I implemented to calculate the time it takes to insert 
// and find n words in a set and in an unordered set. I do this process 10 
// times, shuffling the words each time. I then increment n by 5000 and repeat
// the process for each increment of n. I calculate the average runtime for tree
// insert, hash table insert, tree lookup, and hash table look up. I record the
// data found on a data.txt file in order to create a graph based on the 
// runtimes found. main.cc contains my function implementations as well as the
// tests for both trees and hash tables. 

// When running the program, 4 command line arguments have to be entered(the
// run command, the word file, n, and the data file).

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// function to find the time it takes to insert n words
template<typename T>
duration<double, milli> insertRun(T &t, vector<string> &wrds, int n)
{
	auto start = std::chrono::high_resolution_clock::now(); // get start time
	for(unsigned i = 0; i < n; ++i) // for all of the words in wrds up to n
	{
		t.insert(wrds.at(i)); // insert each word
	}
	auto end = std::chrono::high_resolution_clock::now(); // get the end time
	// calculate the time span
	duration<double, milli> time_span = duration_cast<duration<double>>(end - start);
	return time_span;
}

// function to find the time it take to find n words
template<typename T>
duration<double, milli> findRun(T &t, vector<string> &wrds, int n)
{
	auto start = std::chrono::high_resolution_clock::now(); // get start time
	for(unsigned i = 0; i < n; ++i)
	{
		t.find(wrds.at(i)); // find all of the words
	}
	auto end = std::chrono::high_resolution_clock::now(); // get the end time
	// calculate the time span
	duration<double, milli> time_span = duration_cast<duration<double>>(end - start);
	return time_span;
}

// function that calculates the average
duration<double, milli> findAvg(vector<duration<double, milli> > v, int n)
{
	duration<double, milli> sum; // variable to store the sum
	for(unsigned i = 0; i < v.size(); ++i)
	{
		sum += v.at(i); // add each value to the total sum
	}
	return sum / n; // return the calculated average
}

void shuffle(vector<string> &v) // function to shuffle the vector of words
{
	int s = 0;
	for(unsigned i = 0; i < v.size(); ++i)
	{
		s = rand() % v.size(); // use rand to swap with a random position
		swap(v.at(i), v.at(s));
	}
}

int main(int argc, char **argv)
{
	if(argc != 4) // if the incorrect number of arguments are passed-in
	{
		cout << "Invalid argument count." << endl;
		exit(-1); // exit the program
	}
	
	vector<string> words; // vector to hold the words from the file
	
	ifstream fin;
	fin.open(argv[1]);
	string s;
	if(fin.is_open()) // if the file opened
	{
		while (fin >> s) // read in the words
		{
			words.push_back(s); // add each word to the vector words
		}
	}
	else // if the file did not open correctly
	{
		cout << "Error opening file." << endl; // print an error message
		exit(-1);
	}
	
	fin.close();
	
	int n = atoi(argv[2]);
	
	set<string> test1; // set for tree
	unordered_set<string> test2; // hash
	
	// vectors to store the runtimes for each
	vector<duration<double, milli>> tInsert; // for tree insert
	vector<duration<double, milli>> hInsert; // for hash insert
	vector<duration<double, milli>> tFind; // for tree find
	vector<duration<double, milli>> hFind; // for hash find
	
	cout << "Calculating average runtimes for tree insert, hash insert, ";
	cout << "tree lookup, and hash lookup . . . " << endl;
	
	ofstream fout;
	fout.open(argv[3]); // open data file to write the times to the file
	
	for(unsigned i = n; i <= 50000; i = i + 5000) // increment by 5000 each time
	{
		for(int j = 0; j < 10; ++j) // do process 10 times for each i
		{
			shuffle(words); // shuffle the words
			tInsert.push_back(insertRun(test1, words, i)); // find tree insert
			hInsert.push_back(insertRun(test2, words, i)); // find hash insert
			tFind.push_back(findRun(test1, words, i)); // find tree find
			hFind.push_back(findRun(test2, words, i)); // find hash find
		}
		// put the data found on the data.txt file
		fout << i << ' ';
		fout << chrono::duration_cast<duration<double, milli>>(findAvg(tInsert, (10 * i))).count() << ' ';
		fout << chrono::duration_cast<duration<double, milli>>(findAvg(hInsert, (10 * i))).count() << ' ';
		fout << chrono::duration_cast<duration<double, milli>>(findAvg(tFind, (10 * i))).count() << ' ';
		fout << chrono::duration_cast<duration<double, milli>>(findAvg(hFind, (10 * i))).count() << ' ';
		fout << endl;
	}
	
	fout.close(); // close the data file
	
	cout << "Process completed" << endl;
	
	return 0;
}