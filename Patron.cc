#include "Patron.h"

Patron::Patron(string fn, string ln) 
  : fname(fn), lname(ln), lifetimeCO(0) 
{ 
	dependents = new DepArray();
	books = new BookArray();
}

Patron::Patron(const Patron& other) :
fname(other.fname), lname(other.lname), lifetimeCO(other.lifetimeCO){

	dependents = new DepArray(other.dependents);
	books = new BookArray(other.books);
}

Patron::~Patron() {
	delete dependents;
	delete books;
}

int Patron::getType() {
	return 0;
}

bool Patron::operator==(const Patron& other) {
	if (this->getFname() == other.getFname() &&
		this->getLname() == other.getLname()) return true;

	return false;
}

Patron& Patron::operator=(const Patron& other) {
	if (this == &other) return *this;
	
	this->lifetimeCO = other.lifetimeCO;
	this->dependents = other.dependents;
	
	//clean up the books variable if set
	if (this->books != NULL)
		delete this->books;
		
	//create the new bookarray
	this->books = new BookArray();
	
	for (int i = 0; i < other.books->GetCurrentIndex(); i++) {
		this->books->AddBook(other.books->GetBook(i));
	}
	
	return *this;
}

void Patron::CleanUp() {
	delete dependents;
}

void Patron::addBook(Book* book)
{
	books->AddBook(book);
}

void Patron::remBook(Book* book)
{
	books->RemoveBook(book);
}


bool Patron::hasCheckedOut(Book* book) {
	if (books->BookIndex(book) >= 0) {
		return true;
	}
	return false;
}

int Patron::hasBooksOut()
{
	if (books->ContainsBooks())
		return C_TRUE;

	return C_FALSE;
}


int Patron::computeLifetimeCO()    { 

	if (dependents == NULL || dependents->GetCurrentIndex() <= 0) return lifetimeCO;
	
	int count = 0;
	
	for (int i = 0; i < dependents->GetCurrentIndex(); i++) {
		count += dependents->GetPatron(i)->getLifetimeCO();
	}
	return lifetimeCO + count; 
}
string Patron::getFname() const     { return fname; }
string Patron::getLname() const     { return lname; }
int Patron::getLifetimeCO()			{ return lifetimeCO; }
DepArray* Patron::getDepList()		{ return dependents; }
int	Patron::getMaxDepIndex()		{ return dependents->GetCurrentIndex(); }
Patron* Patron::getParent()			{ return dependents->GetParent(); }
Book* Patron::getBook(int index)	{ return books->GetBook(index); }
int	Patron::getMaxBooksIndex()		{ return books->GetCurrentIndex();}

bool Patron::hasDependents() {
	return dependents->ContainsDeps();
}


Book* Patron::findBookByID(int id) {
	return books->GetBookByID(id);
}

//manage dependents
void	Patron::addDependent(Patron* dep) {
	dependents->AddDep(dep);
}

void	Patron::remDependent(Patron* dep) {
	dependents->RemoveDep(dep);
}

/////////SETTERS
void Patron::setLifetimeCO(int co) {
	this->lifetimeCO = co;
}

