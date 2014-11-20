#ifndef PATRONARRAY_H
#define PATRONARRAY_H

#pragma once

#include<string>
#include "Patron.h"

using namespace std;

class PatronArray {
public:
	PatronArray();
	PatronArray(const PatronArray& other);
	~PatronArray();


	void AddPatron(Patron* patron);
	bool RemovePatron(Patron* patron);
	bool RemovePatron(int index);
	int PatronIndex(Patron* patron);
	int GetCurrentIndex();
	Patron* GetPatron(int);
	Patron* FindPatron(string fn, string ln);
	void CleanUp();

	//functions
private:

	void DoubleArray();
	void DeleteArray();
	void ShiftArray(int index);
private:
	Patron** patronList;
	int maxSize;
	int currentIndex;
};
#endif