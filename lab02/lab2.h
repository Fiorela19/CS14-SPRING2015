#ifndef __LAB2_H__
#define __LAB2_H__

#include <forward_list>

using namespace std;

typedef int Type;

int primeCount(forward_list<int> lst);

bool isPrime(int i);

void listCopy(forward_list<Type> L, forward_list<Type> &P);

void printLots(forward_list<Type> L, forward_list<int> P);

void print(forward_list<Type> &L);

#endif
