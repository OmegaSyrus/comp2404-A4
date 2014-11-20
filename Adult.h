#ifndef ADULTPATRON_H
#define ADULTPATRON_H

#pragma once

#include <string>
#include "Book.h"
#include "types.h"
#include "DepArray.h"
#include "BookArray.h"
#include "Patron.h"

class DepArray;

class Adult : Patron
{
  public:
    Adult(string="", string="");
	Adult(const Adult& other);
	~Adult();

	virtual int getType();

};

#endif

