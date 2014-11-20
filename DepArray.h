#ifndef DEPARRAY_H
#define DEPARRAY_H

#pragma once

#include<string>
#include "Patron.h"

class Patron;

using namespace std;

class DepArray {
public:
	DepArray();
	DepArray(Patron* parent);
	DepArray(DepArray* other);
	~DepArray();

	void AddDep(Patron* patron);
	void RemoveDep(Patron* patron);
	void RemoveDep(int index);
	int DepIndex(Patron* patron);
	int GetCurrentIndex();
	bool ContainsDeps();
	Patron* GetParent();
	void	SetParent(Patron* parent);
	Patron* GetPatron(int);
	void makeCopy(const DepArray& other);

	//functions
private:
	void DoubleArray();
	void DeleteArray();
	void ShiftArray(int index);

	Patron** patronList;
	int maxSize;
	int currentIndex;
	Patron* parent;
};
#endif