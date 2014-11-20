#include "Library.h"

Library::Library()
{ 

	//create the storage container
	storage = new Storage();

	//initialize temporary collections
	books = new BookArray();
	patroncollection = new PDeque();
}

Library::~Library()
{
	/*for (int i=0; i<maxCollIndex; ++i)
		delete collection[i];

	for (int i=0; i<maxPatronsIndex; ++i)
		delete patrons[i];*/

//	delete books;
	delete patroncollection;
	delete storage;
}

int Library::getMaxCollIndex()    { 
	storage->retBooks(books);

	return books->GetCurrentIndex();
}
int Library::getMaxPatronsIndex() {
	storage->retPatrons(patroncollection);
	return patroncollection->getSize(); 
}

void Library::getStorage() {
	storage->retBooks(books);
	storage->retPatrons(patroncollection);
}

Book* Library::getBook(int index) 
{ 
	getStorage();

	Book* book = books->GetBook(index);

	if (index >= 0) {
		return book;
	}

	return NULL;
}

Patron* Library::getPatron(int index) 
{
	getStorage();

	//Patron* patron = patroncollection->GetPatron(index);

	//return patron;
	return NULL;
}

PDeque* Library::GetPatrons() {
	storage->retPatrons(patroncollection);
	return patroncollection;
}
BookArray* Library::GetBooks() {
	storage->retBooks(books);
	return books;
}

void Library::init()
{
}

int Library::addBook(Book* book)
{
  /*if (maxCollIndex >= MAX_COLL_SIZE - 1) {
    return C_NOK;
  }

  collection[maxCollIndex++] = book;

  return C_OK;*/

	//storage->addBook(book);
	return C_OK; 
}

int Library::addPatron(Patron* patron)
{
  /*if (maxPatronsIndex >= MAX_COLL_SIZE - 1) {
    return C_NOK;
  }

  patrons[maxPatronsIndex++] = patron;

  return C_OK;*/
	storage->updPatrons(ADD, patron);
	return C_OK;
}

int Library::remPatron(int index)
{
  /*if (index < 0 || index >= maxPatronsIndex)
    return C_NOK;

  delete patrons[index];
  patrons[index] = 0;
  return C_OK;*/

	//storage->updPatrons(DELETE, );
	return C_OK;
}

void Library::remPatron(Patron* patron) {
	//patroncollection
	storage->updPatrons(DELETE, patron);
}

int Library::findPatron(string fn, string ln, Patron** patron, int* index)
{
  /*for (int i=0; i<maxPatronsIndex; ++i) {
    if (patrons[i] == 0)
      continue;
    if (patrons[i]->getFname() == fn && patrons[i]->getLname() == ln) {
      *patron = patrons[i];
      *index  = i;
      return C_OK;
    }
  }
  *patron =  0;
  *index  = -1;
  return C_NOK;*/
	
	//grab current collection of patrons
	storage->retPatrons(patroncollection);

	//search that collection for the patron
	patroncollection->find(fn, ln);

	return 0;
}

void Library::addDependent(Patron* parent, Patron* dependent) {
	//parent->addDependent(dependent);
	storage->updPatrons(MODIFY, dependent);
}

Patron* Library::findPatron(string fn, string ln)
{
	//grab current collection of patrons
	storage->retPatrons(patroncollection);

	//search that collection for the patron
	return patroncollection->find(fn, ln);
}

int Library::findBook(int id, Book** book, int* index)
{
	return C_NOK;
}

Book* Library::findBook(int id) {
	//grab book collection
	storage->retBooks(books);

	//search by id
	return books->GetBookByID(id);
}

