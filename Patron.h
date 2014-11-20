#ifndef PATRON_H
#define PATRON_H

#pragma once

#include <string>
#include "Book.h"
#include "types.h"
#include "DepArray.h"
#include "BookArray.h"

class DepArray;

class Patron
{
  public:
    Patron(string="", string="");
	Patron(const Patron& other);
	~Patron();
	bool operator==(const Patron& other);
	Patron& operator=(const Patron& other);

	virtual int getType();
	
    void	addBook(Book*);
    void	remBook(Book*);
	void	addDependent(Patron* dep);
	void	remDependent(Patron* dep);
    int		findBook(int);
	bool	hasCheckedOut(Book*);
	Book*	findBookByID(int);
    int		hasBooksOut();
    string	getFname() const;
    string	getLname() const;
	Book*	getBook(int);
	int		getMaxBooksIndex();
	int		getMaxDepIndex();
    int		getLifetimeCO();
	virtual int		computeLifetimeCO();
	Patron* getParent();
	bool	hasDependents();
	void	setLifetimeCO(int);
	void	CleanUp();
	DepArray*	getDepList();
  private:
    string fname;
    string lname;
    int    lifetimeCO;

	//collections
	BookArray* books;
	DepArray* dependents;

};

#endif

