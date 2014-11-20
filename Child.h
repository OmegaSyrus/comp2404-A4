#ifndef CHILDPATRON_H
#define CHILDPATRON_H

#pragma once

#include <string>
#include "Book.h"
#include "types.h"
#include "DepArray.h"
#include "BookArray.h"
#include "Patron.h"

class DepArray;

class Child : public Patron
{
  public:
    Child(string="", string="");
	Child(const Child& other);
	~Child();

	void	setParent(Patron*);
	virtual int getType();
	virtual int		computeLifetimeCO();

};

#endif
