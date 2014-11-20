#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

#include "types.h"

class Book
{
  public:
	  Book(string = "", string = "", int = 0, BookStatusType = CHECKED_IN);
	Book(Book* book);
    void setStatus(BookStatusType);
    BookStatusType getStatus();
    int    getId();
    string getTitle();
    string getAuthor();
	int		getYear();

	Book* copy();

  private:
    static int     nextId;
    int            id;
    string         title;
    string         author;
    int            year;
    BookStatusType status;
};

#endif

