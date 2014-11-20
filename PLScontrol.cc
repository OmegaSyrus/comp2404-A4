#include <iostream>
using namespace std;
#include "PLScontrol.h"

PLScontrol::PLScontrol() 
{ 
  lib  = new Library;
  view = new View(this);
}

PLScontrol::~PLScontrol() 
{ 
  delete lib;
  delete view;
}

void PLScontrol::launch() 
{ 
  lib->init();
  view->mainMenu();
  view->printAll();
}

void PLScontrol::addPatron() 
{
  Patron patron;
  Patron* parent = NULL;
  string fn, ln;
  int    rc;
  int age;

  view->getPatronName(fn, ln);
  view->getPatronAge(&age);


  if (age < 18) {
	  Child temp = Child(fn, ln);
	  while (parent == NULL) {
		  view->getPatronParent(fn, ln);

		  parent = lib->findPatron(fn, ln);
		  if (parent != NULL)
			  temp.setParent(parent);
			  lib->addDependent(parent, &temp);
	  }
  }
  else patron = Adult(fn, ln);

  rc = lib->addPatron(&patron);
  if (rc != C_OK) {
    view->printError("\nCould not add patron to library, press <ENTER> to continue...");
  }

  //add dependent to parent list
}

void PLScontrol::remPatron() 
{
  Patron *patron;
  string fn, ln;

  view->getPatronName(fn, ln);

  //grab the appropriate patron
  patron = lib->findPatron(fn, ln);
  if (patron == NULL) {
    view->printError("\nCould not find patron, press <ENTER> to continue...");
    return;
  }

  if (patron->hasBooksOut()) {
    view->printError("\nPatron has books checked out, could not remove.  Press <ENTER> to continue...");
    return;
  }

  if (patron->hasDependents()) {
	  view->printError("\nPatron has dependents, could not remove.  Press <ENTER> to continue...");
	  return;
  }

  lib->remPatron(patron);
}

void PLScontrol::checkIn(Patron* patron) 
{
  Book* book;
  int   id;

  //determine which book it is
  view->getBookId(&id);

  //find the book in the system
  book = patron->findBookByID(id);
  if (book == NULL) {
    view->printError("\nBook is not checked out to this patron, press <ENTER> to continue...");
    return;
  }

  //take book from owner and check it in
  patron->remBook(book);
  book->setStatus(CHECKED_IN);

}

void PLScontrol::checkOut(Patron* patron) 
{
  Book* book;
  int   id;

  if (patron->getMaxBooksIndex() >= MAX_CO_BOOKS - 1) {
    view->printError("\nPatron cannot check out any more books.  Press <ENTER> to continue...");
    return;
  }

  view->getBookId(&id);

  book = lib->findBook(id);
  if (book == NULL) {
    view->printError("\nCould not find book, press <ENTER> to continue...");
    return;
  }

  if (book->getStatus() != CHECKED_IN) {
    view->printError("\nBook is not available, press <ENTER> to continue...");
    return;
  }

  //take book from patron and check out the book
  patron->addBook(book);
  book->setStatus(CHECKED_OUT);
}

Library* PLScontrol::getLib() { return lib; }

