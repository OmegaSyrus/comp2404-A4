#include "Adult.h"

Adult::Adult(string fname, string lname) : Patron(fname, lname){

}

Adult::Adult(const Adult& other) {
	fname = other.fname;
	lname = other.lname;
	lifetimeCO = other.lifetimeCO;
	dependents = new DepArray(other.dependents);
	books = new BookArray(other.books);

}

Adult::~Adult() {
	delete dependents;
	delete books;
}

int Adult::getType() {
	return 1;
}