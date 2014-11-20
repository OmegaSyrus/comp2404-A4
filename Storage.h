#ifndef STORAGE_H
#define STORAGE_H

#pragma once

#include <string>
#include "Book.h"
#include "Patron.h"
#include "types.h"
#include "PDeque.h"
#include "DepArray.h"
#include "BookArray.h"

using namespace std;

class Storage
{
	friend class Patron;
	friend class Book;
	friend class PatronArray;
	friend class BookArray;

public:
	Storage();
	~Storage();
	void retBooks(BookArray* bookArr);
	void retPatrons(PDeque* patronArr);
	void updPatrons(UpdateType action, Patron* patron);

private:

	//collections
	BookArray* books;
	PDeque* patrons;
	Server* server;
};

#endif