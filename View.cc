#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#include "View.h"

View::View(PLScontrol* c) : control(c) { }

void View::mainMenu()
{
  string choice = "-1";

  while (choice != "0") {
    //system("clear");
    cout<< "\n\n\n\n\n                   WELCOME TO THE PANDORA LIBRARY SYSTEM \n\n\n\n";
    cout<< "        Here are your options:\n\n";
    cout<< "          1. Patron Menu\n\n";
    cout<< "          2. Administrator Menu\n\n";
    cout<< "          3. View Entire Collection\n\n";
	cout<< "          4. View Patrons list\n\n";
    cout<< "          0. Exit\n\n";
    cout<< "        Enter one of the choices above:  ";
    getline(cin, choice);

    while (choice != "1" && choice != "2"
        && choice != "3" && choice != "0" && choice != "4") {
      cout<< "        Enter one of the choices above:  ";
      getline(cin, choice);
    }

    switch(choice[0]) {
      case '1':
        patronMenu();
        break;
      case '2':
        adminMenu();
        break;
      case '3':
        viewCollection();
        break;
	  case '4':
		  printDirection();
		  break; 
      default:
        return;
    }
  }
}

void View::printDirection() {

	string choice = "-1";

	cout << "\n\n\n\n\n          PRINT PATRONS IN WHICH ORDER? \n\n\n\n";
	cout << "        Here are your options:\n\n";
	cout << "          1. Descending\n\n";
	cout << "          2. Ascending\n\n";
	cout << "          0. Exit\n\n";
	cout << "        Enter one of the choices above:  ";

	while (choice != "1" && choice != "2" && choice != "0") {

		cout << "        Enter one of the choices above:  ";
		getline(cin, choice);
	}

	switch (choice[0]) {
	case '1':
		printPatrons();
		break;
	case '2':
		printPatronsBack();
		break;
	default:
		return;

	}
}

void View::patronMenu()
{
  Patron* patron;
  string  choice = "-1";
  string  fn, ln;

  getPatronName(fn, ln);
  patron = control->getLib()->findPatron(fn, ln);
  if (patron == NULL) {
    printError("\nCould not find patron, press <ENTER> to continue...");
    return;
  }

  while (choice != "0") {
    system("clear");
    cout<< "\n\n\n\n\n                   PATRON MENU \n\n";
    cout<< "        Here are your options:\n\n";
    cout<< "          1. Check in a book\n";
    cout<< "          2. Check out a book\n";
    cout<< "          3. List books checked out\n";
    cout<< "          0. Exit\n\n";
    cout<< "        Enter one of the choices above:  ";
    getline(cin, choice);

    while (choice != "1" && choice != "2"
        && choice != "3" && choice != "0") {
      cout<< "        Enter one of the choices above:  ";
      getline(cin, choice);
    }

    switch(choice[0]) {
      case '1':
        control->checkIn(patron);
        break;
      case '2':
        control->checkOut(patron);
        break;
      case '3':
        printCheckedOut(patron);
        break;
      default:
        return;
    }
  }
}

void View::adminMenu()
{
  string choice = "-1";

  while (choice != "0") {
    system("clear");
    cout<< "\n\n\n\n\n                   ADMINISTRATOR MENU \n\n";
    cout<< "        Here are your options:\n\n";
    cout<< "          1. Add a Patron \n";
    cout<< "          2. Delete a Patron\n";
    cout<< "          0. Exit\n\n";
    cout<< "        Enter one of the choices above:  ";
    getline(cin, choice);

    while (choice != "1" && choice != "2"
           && choice != "0") {
      cout<< "        Enter one of the choices above:  ";
      getline(cin, choice);
    }

    switch(choice[0]) {
      case '1':
        control->addPatron();
        break;
      case '2':
        control->remPatron();
        break;
      default:
        return;
    }
  }
}

void View::viewCollection()
{
  system("clear");
  printCollection();
  cout<< "\nPress <ENTER> to continue...";
  cin.get();
}

void View::getPatronName(string& fn, string& ln)
{
  string str;

  cout<< endl<<"        Enter patron name ([first] [last]:  ";
  getline(cin, str);
  stringstream ss(str);
  ss >> fn >> ln;
}
void View::getPatronParent(string& fn, string& ln)
{
	string str;

	cout << endl << "        You are less than 18, you will need someone responsible for you to hold an account here\n";
	cout << endl << "        Enter guardian/parent name ([first] [last]:  ";
	getline(cin, str);
	stringstream ss(str);
	ss >> fn >> ln;
}
void View::getPatronAge(int* age) {

	string str;

	cout << endl << "        ENTER YOUR AGE:  ";
	getline(cin, str);
	stringstream ss(str);
	ss >> *age;
}

void View::getBookId(int* id)
{
  string str;

  cout<< endl<<"        Enter book identifier:  ";
  getline(cin, str);
  stringstream ss(str);
  ss >> *id;
}

void View::printAll()
{
  system("clear");
  printCollection();
  printPatrons();


  string str;
  getline(cin, str);
}

void View::printCollection()
{
  cout << endl << setw(40)<< "COLLECTION" <<endl;;
  cout << setw(40)<< "----------"<<endl<<endl;

  control->getLib()->getStorage();

  for (int i=0; i<=control->getLib()->getMaxCollIndex(); ++i) {
    if (control->getLib()->getBook(i) == NULL)
      continue;
    printBookInfo(control->getLib()->getBook(i));
  }
}

void View::printBookInfo(Book* book)
{
  cout<< "    "<<setw(4)<<book->getId()<<setw(40)<<book->getTitle()<<setw(20)<<book->getAuthor();

  switch(book->getStatus()) {
    case CHECKED_IN:
      cout<< "  "<<setw(12)<< "Checked in";
      break;
    case CHECKED_OUT:
      cout<< "  "<<setw(12)<< "Checked out";
      break;
    case UNDER_REPAIR:
      cout<< "  "<<setw(12)<< "Under repair";
      break;
    case LOST:
      cout<< "  "<<setw(12)<< "Lost";
      break;
  }
  cout << endl;
}


void View::printPatrons()
{
  string str;

  cout<< endl<<endl<<setw(40)<<"PATRONS"<<endl;;
  cout << setw(40)<< "-------"<<endl<<endl;

  PDeque* patrons = control->getLib()->GetPatrons();
  Patron* curr;

  //print all patrons
  while (patrons->getSize() > 0) {
	  curr = patrons->front();
	  if (curr == 0)
		  continue;

	  str = curr->getFname() + " "
		  + curr->getLname();
	  str += ", lifetime #books: ";
	  cout << setw(40) << str;
	  cout << curr->getLifetimeCO() << endl;

	  //show their books
	  for (int j = 0; j <= curr->getMaxBooksIndex(); ++j) {
		  if (curr->getBook(j) == NULL)
			  continue;
		  printBookInfo(curr->getBook(j));
	  }

	  //show their dependents
	  if (curr->hasDependents()) {
		  cout << endl << setw(40) << "::::DEPENDENTS:::" << endl;;
		  for (int j = 0; j < curr->getMaxDepIndex(); j++) {
			  Patron* tempDep = curr->getDepList()->GetPatron(j);
			  if (tempDep == NULL)
				  continue;

			  str = tempDep->getFname() + " "
				  + tempDep->getLname();
			  str += ", lifetime #books: ";
			  cout << setw(40) << str;
			  cout << tempDep->getLifetimeCO() << endl << endl;
		  }
	  }

	  patrons->popFront();
  }

  cout<< endl;
}

void View::printPatronsBack() {
	string str;

	cout << endl << endl << setw(40) << "PATRONS" << endl;;
	cout << setw(40) << "-------" << endl << endl;

	PDeque* patrons = control->getLib()->GetPatrons();
	Patron* curr;

	while (patrons->getSize() > 0) {
		curr = patrons->back();
		if (curr == NULL)
			continue;

		str = curr->getFname() + " "
			+ curr->getLname();
		str += ", lifetime #books: ";
		cout << setw(40) << str;
		cout << curr->getLifetimeCO() << endl;

		//show their books
		for (int j = 0; j <= curr->getMaxBooksIndex(); ++j) {
			if (curr->getBook(j) == NULL)
				continue;
			printBookInfo(curr->getBook(j));
		}

		//show their dependents
		if (curr->hasDependents()) {
			cout << endl << setw(40) << "::::DEPENDENTS:::" << endl;;
			for (int j = 0; j < curr->getMaxDepIndex(); j++) {
				Patron* tempDep = curr->getDepList()->GetPatron(j);
				if (tempDep == NULL)
					continue;

				str = tempDep->getFname() + " "
					+ tempDep->getLname();
				str += ", lifetime #books: ";
				cout << setw(40) << str;
				cout << tempDep->getLifetimeCO() << endl << endl;
			}
		}

		patrons->popBack();
	}
	cout << endl;
}

void View::printCheckedOut(Patron* patron)
{
  system("clear");
  
  //title
  cout << endl<<endl<<endl <<setw(40)<< "BOOKS CHECKED OUT FOR:  "
       << patron->getFname() << " " << patron->getLname() <<endl;
  cout << setw(38)<< "----------------------"<<endl<<endl;

  //iterate through books owned
  for (int i=0; i<=patron->getMaxBooksIndex(); ++i) {
    if (patron->getBook(i) == 0)
      continue;
    printBookInfo(patron->getBook(i));
  }

  //end
  cout<< "\nPress <ENTER> to continue...";
  cin.get();
}

void View::printError(const string& err)
{
  cout << err << endl;
  cin.get();
}

