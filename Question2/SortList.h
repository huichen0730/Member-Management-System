#pragma once
#ifndef SORTLIST_H
#define SORTLIST_H
#include <iostream>
using namespace std;

template <class Type>
class Sortlist
{
private:
	Type* Element;
	int ArraySize;
	void Swap(Type& a, Type& b);
	void Split(const int first, const int last, int& split_index);
	void Quicksort(const int first, const int last);
public:
	Sortlist(int arraysize = 10) : ArraySize(arraysize),
		Element(new Type[arraysize]) {}
	~Sortlist();
	void SetArray(Type sortarray[]);
	void GetArray(Type sortarray[]);
	void Quicksort();
};
#endif

