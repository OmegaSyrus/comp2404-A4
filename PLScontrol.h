#ifndef PLS_CONTROL_H
#define PLS_CONTROL_H

#include "types.h"
#include "Library.h"
#include "View.h"
#include "Adult.h"
#include "Child.h"
#include "Patron.h"

class View;

class PLScontrol
{
  public:
    PLScontrol();
    ~PLScontrol();
    void launch();
    void addPatron();
    void remPatron();
    void checkIn(Patron*);
    void checkOut(Patron*);
    Library* getLib();
  private:
    Library* lib;
    View*    view;
};

#endif

