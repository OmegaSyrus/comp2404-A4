#ifndef VIEW_H
#define VIEW_H

#include "Book.h"
#include "PLScontrol.h"
#include "View.h"

class PLScontrol;

class View
{
  public:
    View(PLScontrol*);
    void mainMenu();
    void getBookId(int*);
    void getPatronName(string&,string&);
	void getPatronParent(string&, string&);
	void getPatronAge(int*);
	void printDirection();
    void printAll();
    void printError(const string&);
  private:
    PLScontrol* control;
    void adminMenu();
    void patronMenu();
    void viewCollection();
    void printCollection();
    void printPatrons();
	void printPatronsBack();
    void printBookInfo(Book*);
    void printCheckedOut(Patron*);
};

#endif

