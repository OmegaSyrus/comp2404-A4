#include "Book.h"

int Book::nextId = 1001;

Book::Book(string t, string a, int y, BookStatusType type) 
	: title(t), author(a), year(y), status(type)
{ 
  this->id     = nextId++;
}
Book::Book(Book* book) {
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
	Book* temp = new Book(this->title, this->author, this->year, this->status);
	temp->setStatus(this->status);

	return temp;
}


int            Book::getId()     { return id; }
string         Book::getTitle()  { return title; }
string         Book::getAuthor() { return author; }
BookStatusType Book::getStatus() { return status; }
int				Book::getYear()		{ return year; }

