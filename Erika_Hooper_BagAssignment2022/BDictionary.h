/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your Dictionary
*/
#pragma once
#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"
#include <memory>

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {

public:
	// constructors
	BDictionary() {
		Bag=std::make_unique<ABag<KVpair<Key,E>>>(10);
	}
	BDictionary(int ten) {
		Bag= std::make_unique<ABag<KVpair<Key, E>>>(ten);
	}
	//destructor
	~BDictionary() {}
	
	// methods:
	// Reinitialize 
	void clear() {
		Bag->emptyBag(); //clears the bag
	}
	
	// inserts an element
	bool insert(const Key& k, const E& e) {
		KVpair<Key, E> name(k, e);
		if (Bag->addItem(name)) {
			return true;
		}
		else {
			return false;
		}
	}
	//finds and remove and element
	bool remove(const Key& k, E& e) {
		KVpair<Key, E> name(k, e);
		if (Bag->remove(name)) {
			e = name.value();
			return true;
		}
		else {
			return false;
		}
	}

	// removeAny
	bool removeAny(E& retValue) {
		Key k{};
		KVpair<Key, E> name(k, retValue);
		if (Bag->removeTop(name)) {
			retValue = name.value();
			Bag->removeTop(name);
			return true;
		}
		else {
			return false;
		}
	}
	
	
	//find will look for a record
	bool find(const Key& k, E& retValue) const {
		KVpair<Key, E> name(k, retValue);
		if (Bag->find(name)) {	//if found will return the record and true
			retValue = name.value();
			return true;
		}
		else {
			return false; //if not found will return false
		}
	}

	//size
	int size() {
		return Bag->size();
	}

private:
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the 
	//functions you need to build your dictionary.
	std::unique_ptr<ABag<KVpair<Key, E>>> Bag;
};


#endif	/* BDICTIONARY_H */
