/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap
		
		// returning something so it compiles:
		text_item returnItem = top();
		data[0] = data[numItems - 1];
		numItems--;
		swap_down(0);
		return returnItem;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
	int s = i;
	int left = i * 2 + 1;
	int right = left + 1;
	if(left < numItems && data[left].freq > data[s].freq)
		s = left;
	if(right < numItems && data[right].freq > data[s].freq)
		s = right;
	if(s != i){
		int temp = data[i].freq;
		std::string temp0 = data[i].word;
		data[i].freq = data[s].freq;
		data[i].word = data[s].word;
		data[s].freq = temp;
		data[s].word = temp0;
		swap_down(s);
	}
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
		data[numItems++] = item;
		swap_up(numItems - 1);
	}
}

void max_heap::swap_up(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
	if(i == 0) return;
	int p = (i - 1)/2;
	if(data[i].freq > data[p].freq){
		int temp = data[i].freq;
		std::string temp0 = data[i].word;
		data[i].freq = data[p].freq;
		data[i].word = data[p].word;
		data[p].freq = temp;
		data[p].word = temp0;
		swap_up(p);
	}
}
