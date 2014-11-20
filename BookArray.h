#ifndef BOOKARRAY_H
#define BOOKARRAY_H

#pragma once

#include<string>
#include "Book.h"

using namespace std;

class BookArray {
public:
	BookArray();
	~BookArray();
	BookArray(BookArray* other);
	BookArray& operator+=(Book* book);
	void AddBook(Book* book);
	void RemoveBook(Book* book);
	void RemoveBook(int index);
	int BookIndex(Book* book);
	Book* GetBookByID(int id);
	int	GetBookIndexByID(int id);
	Book* GetBook(int index);
	bool ContainsBooks();
	int GetCurrentIndex();
	void makeCopy(BookArray* other);

//functions
private:
	void DoubleArray();
	void DeleteArray();
	void ShiftArray(int index);
private:
	Book** bookList;
	int maxSize;
	int currentIndex;
};
#endif