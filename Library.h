#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "types.h"
#include "Book.h"
#include "Patron.h"
#include "PDeque.h"
#include "PatronArray.h"
#include "BookArray.h"
#include "Storage.h"

using namespace std;

class Library
{
  public:
    Library();
    ~Library();
    void    init();
    int     addBook(Book*);
    int     addPatron(Patron*);
    int     remPatron(int);
	void	remPatron(Patron*);
	int     findBook(int, Book**, int*);
	Book*   findBook(int);
	int     findPatron(string, string, Patron**, int*);
	Patron* findPatron(string, string);
    int     getMaxCollIndex();
    int     getMaxPatronsIndex();
	BookArray* GetBooks();
	PDeque* GetPatrons();
	void	getStorage();
    Book*   getBook(int);
    Patron* getPatron(int);
	void	addDependent(Patron*, Patron*);

  private:
    //Book*   collection[MAX_COLL_SIZE];
    //Patron* patrons[MAX_COLL_SIZE];
    //int     maxCollIndex;
    //int     maxPatronsIndex;

	BookArray* books;
	PDeque* patroncollection;
	Storage* storage;
};

#endif

