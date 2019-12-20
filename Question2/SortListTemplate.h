#pragma once
#ifndef SORTLISTTEMPLATE_H
#define SORTLISTTEMPLATE_H
#include "SortList.h"

template <class Type>
Sortlist<Type>::~Sortlist()
{
	delete[] Element;
}

template <class Type>
void Sortlist<Type>::SetArray(Type sortarray[])
{

	for (int index = 0; index < ArraySize; index++)

		Element[index] = sortarray[index];

}

template <class Type>
void Sortlist<Type>::GetArray(Type sortarray[])
{

	for (int index = 0; index < ArraySize; index++)

		sortarray[index] = Element[index];
}

template <class Type>
void Sortlist<Type>::Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}

template <class Type>
void Sortlist<Type>::Split(const int first, const int last, int& split_index)
{
	int left, right;  // Markers for searching from left and right
	Type pivot;  // Pivot element

	pivot = Element[first];
	left = first;
	right = last;
	while (left < right)   // While markers have not met
	{
		// Search from the right for element <= pivot

		while (Element[right] > pivot)
			right = right - 1;

		// Search from the left for element > pivot

		while ((left < right) && (Element[left] <= pivot))
			left = left + 1;

		// If markers have not met, interchange elements

		if (left < right)
			Swap(Element[left], Element[right]);
	};

	// Searches complete; now place pivot in correct place

	split_index = right;
	Element[first] = Element[split_index];
	Element[split_index] = pivot;
}

template <class Type>
void Sortlist<Type>::Quicksort(const int first, const int last)
// Sorts portion of array X between X[first] and X[last]
{
	int split_index;     // Final position of pivot

	if (first < last)           // List has at least two elements
	{
		Split(first, last, split_index);      // Split into two sublists
		Quicksort(first, split_index - 1);   // Sort left sublist
		Quicksort(split_index + 1, last);     // Sort right sublist
	}
	// else list has 0 or 1 elements and needs no sorting
}

template <class Type>
void Sortlist<Type>::Quicksort()
{
	Quicksort(0, ArraySize - 1);
}
#endif
