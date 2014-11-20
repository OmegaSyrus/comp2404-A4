#include "Child.h"
Child::Child(string fname, string lname) : Patron(fname, lname){
		
}

Child::Child(const Child& other) {
	fname = other.fname;
	lname = other.lname;
	lifetimeCO = other.lifetimeCO;
	dependents = new DepArray(other.dependents);
	books = new BookArray(other.books);
	
}
Child::~Child() {
	delete dependents;
	delete books;
}


int Child::getType() {
	return 2; //child signature
}


void Child::setParent(Patron* parent) {
	this->dependents->SetParent(parent);
}

int Child::computeLifetimeCO()    { 

	return lifetimeCO;
}