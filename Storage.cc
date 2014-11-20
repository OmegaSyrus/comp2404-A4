#include "Storage.h"

Storage::Storage() {

	Book*   newBook;
	Patron* newPatron;
	int id = 1000;
	books = new BookArray();
	patrons = new PDeque();

	newBook = new Book(id++, "Ender's Game", "Orson Scott Card", 1985);
	books->AddBook(newBook);

	newBook = new Book(id++, "Dune", "Frank Herbert", 1965);
	newBook->setStatus(LOST);
	books->AddBook(newBook);

	newBook = new Book(id++, "Foundation", "Isaac Asimov", 1951);
	books->AddBook(newBook);

	newBook = new Book(id++, "Hitch Hiker's Guide to the Galaxy", "Douglas Adams", 1979);
	books->AddBook(newBook);

	newBook = new Book(id++, "1984", "George Orwell", 1949);
	books->AddBook(newBook);

	newBook = new Book(id++, "Stranger in a Strange Land", "Robert A. Heinlein", 1961);
	newBook->setStatus(UNDER_REPAIR);
	books->AddBook(newBook);

	newBook = new Book(id++, "Farenheit 451", "Ray Bradbury", 1954);
	newBook->setStatus(LOST);
	books->AddBook(newBook);

	newBook = new Book(id++, "2001:  A Space Odyssey", "Arthur C. Clarke", 1968);
	books->AddBook(newBook);

	newBook = new Book(id++, "I, Robot", "Isaac Asimov", 1950);
	books->AddBook(newBook);

	newBook = new Book(id++, "Starship Troopers", "Robert A. Heinlein", 1959);
	books->AddBook(newBook);

	newBook = new Book(id++, "Do Androids Dream of Electric Sheep?", "Philip K. Dick", 1968);
	books->AddBook(newBook);

	newBook = new Book(id++, "Neuromancer", "William Gibson", 1984);
	newBook->setStatus(LOST);
	books->AddBook(newBook);

	newBook = new Book(id++, "Ringworld", "Larry Niven", 1970);
	books->AddBook(newBook);

	newBook = new Book(id++, "Rendezvous with Rama", "Arthur C. Clarke", 1973);
	newBook->setStatus(UNDER_REPAIR);
	books->AddBook(newBook);

	newBook = new Book(id++, "Hyperion", "Dan Simmons", 1989);
	books->AddBook(newBook);


	newPatron = new Patron("Jack", "Shephard");
	patrons->push(newPatron);

	newPatron = new Patron("Kate", "Austen");
	patrons->push(newPatron);

	newPatron = new Patron("Hugo", "Reyes");
	patrons->push(newPatron);

	newPatron = new Patron("James", "Ford");
	patrons->push(newPatron);

	newPatron = new Patron("Sayid", "Jarrah");
	patrons->push(newPatron);

	newPatron = new Patron("Sun-Hwa", "Kwon");
	patrons->push(newPatron);

	newPatron = new Patron("Jin-Soo", "Kwon");
	patrons->push(newPatron);

	newPatron = new Patron("John", "Locke");
	patrons->push(newPatron);

	newPatron = new Patron("Juliet", "Burke");
	patrons->push(newPatron);

	//newPatron = new Patron("Benjamin", "Linus");
	//patrons->push(newPatron);
}

Storage::~Storage() {
	delete patrons;
	delete books; 
}
void Storage::retBooks(BookArray* bookArr) {
	delete bookArr;

	bookArr = new BookArray(books);

}
void Storage::retPatrons(PDeque* patronArr) {
	(*patronArr).makeCopy(*patrons);
}
void Storage::updPatrons(UpdateType action, Patron* patron){
	Patron* temp;
	if (patron == NULL)
		return;

	temp = patron->getParent();

	//decide which operation to perform
	switch (action) {
	case ADD:
		patrons->push(patron);
		if (temp != NULL) {
			temp->addDependent(patron);
		}
		break;
	case MODIFY:
		//enter a modify function, used for adding dependents to a parent
		patrons->modify(patron);
		break;
	case DELETE:
		//remove them from any dependent list
		if (temp != NULL)
			temp->remDependent(patron);

		//remove them from the master list
		patrons->remove(patron);
	}
}