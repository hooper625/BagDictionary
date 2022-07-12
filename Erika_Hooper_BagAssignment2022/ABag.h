/*
* File:   ABag.h
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your ABag. 
*/

#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"
#include <memory>

template <typename E>
class ABag : public Bag<E> {
public:
	// constructors
	ABag() {
		bagCap = 10;
		used = 0;
		data = std::make_unique<E[]>(bagCap);//double checks to make sure array is correct
	}
	//base constructor
	ABag(int capacity) {
		bagCap = capacity;
		used = 0;
		data= std::make_unique<E[]>(bagCap);
	}
	//destructor
	~ABag() {}
	// bag methods: 
	
	//addItem to bag:		
	//true if not at capacity
	bool addItem(const E& item) {
		if (used < bagCap) {
			data[used++] = item; //adds item to bag
			return true;
		}
		else {
			return false; //inserting item will return false if fails
		}
	}
	//remove item from bag 	
	bool remove(E& item) {
		if (used>=0) {
			for (int i = 0; i < used; i++) {
				if (data[i] == item) {
					item = data[i];
					
					for (int j = i; j < used; j++) {
						data[i] = data[j+1];
					}
					used--;
					return true;
				}
			}
		}
		else {
			return false; //removing item will return false if fails
		}
	}

	//removes the top element and puts it in the returnValue
	bool removeTop(E& returnValue) {
		if (used == 0) {
			return false; //returns false and unchanged if empty
		}
		else {
			returnValue = data[--used]; //removed the element and decreases the count
			return true;
		}
	}
	//finds and updates the record 	
	bool find(E& returnValue) const {
		if (used == 0) {
			return false; //if record not found returns false
		}
		else {
			for (int i = 0; i < used; i++) {
				if (data[i] == returnValue) {
					returnValue = data[i];
					return true;
				}
				return false;
			}
		}
	}

		//if found the item is ubdated with content of the bag
		bool inspectTop(E & item) const {
			if (used == 0) {
				return false; //looks at top of the bag and returns false if empty
			}
			else {
				item = data[used - 1];
				return true;
			}
		}
		// empties the bag
		void emptyBag() {
			used = 0;
		}

		//operator+= used the += poerator to add an item to the bag
		bool operator+=(const E & addend) {
			if (addItem(addend)) {
				return true;
			}
			else {
				return false;
			}
		}
		//returns the number of items in the bag
		int size() const {
			return used;
		}

		//returns the capacity of the bag
		int bagCapacity() const {
			return bagCap;
		}

	private:
		std::unique_ptr<E[]> data;            // an array of items
		int used;           // number of items the data array currently holds
		int bagCap;       // the number of items the bag can hold (size of array)
	};

#endif	/* ABAG_H */