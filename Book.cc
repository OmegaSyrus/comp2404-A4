#include "Book.h"

int Book::nextId = 1001;

Book::Book(int id, string t, string a, int y, BookStatusTyp y) 
  : title(t), author(a), year(y)
{ 
  this->id     = id;
  status = CHECKED_IN;
}
Book::Book(Book* book) {
	nextId = book->nextId;
	id = book->id;
	title = book->title;
	author = book->author;
	year = book->year;
	status = book->status;
}


void Book::setStatus(BookStatusType s)
{
  status = s;
}

Book* Book::copy() {
	Book* temp = new Book(this->id , this->title, this->author, this->year);
	temp->setStatus(this->status);

	return temp;
}


int            Book::getId()     { return id; }
string         Book::getTitle()  { return title; }
string         Book::getAuthor() { return author; }
BookStatusType Book::getStatus() { return status; }
int				Book::getYear()		{ return year; }

