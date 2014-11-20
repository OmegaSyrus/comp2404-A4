#include "BookArray.h"

//CONSTRUCTORS
BookArray::BookArray() {
	maxSize = 10;
	currentIndex = -1;
	bookList = new Book*[maxSize];
}

BookArray::~BookArray() {
	if (currentIndex < 0) return;

	for (int i = 0; i <= currentIndex; i++) {
		delete this->bookList[i];
	}

	this->bookList = 0;
}

BookArray::BookArray(BookArray* other)
{
	maxSize = 10;
	currentIndex = -1;
	bookList = new Book*[maxSize];

	for (int i = 0; i <= other->currentIndex; i++) {
		this->AddBook(other->bookList[i]);
	}
}

BookArray& BookArray::operator+=(Book& book) {
		this->AddBook(*book);
		
		return *this;
}

//PRIVATE
void BookArray::DoubleArray() {
	maxSize *= 2;
	Book** temp = new Book*[maxSize];

	for (int i = 0; i <= currentIndex; i++) {
		temp[i] = bookList[i];
	}

	bookList = temp;
}
void BookArray::AddBook(Book* book) {

	if (currentIndex == maxSize - 1) {
		DoubleArray();
	}

	currentIndex++;
	bookList[currentIndex] = new Book(book);
}
void BookArray::ShiftArray(int index) {
	if (index < 0 || index > currentIndex) return;

	delete bookList[index];

	if (index != currentIndex) {
		//shift all elements down
		for (int j = index; j < currentIndex; j++) {
			bookList[j] = bookList[j + 1];
		}
	}

	currentIndex--;
}

//PUBLIC
void BookArray::RemoveBook(Book* book)	{
	int index = BookIndex(book);

	if (index >= 0)
		RemoveBook(index);
}

void BookArray::RemoveBook(int index) {
	if (currentIndex == index) {
		//delete bookList[index];
	}
	else {
		ShiftArray(index);
	}

	currentIndex--;
}

int BookArray::BookIndex(Book* book) {
	int retval = -1;
	
	for (int i = 0; i <= currentIndex; i++) {
		if (bookList[i]->getId() == book->getId()) {
			return i;
		}
	}

	return retval;
}

bool BookArray::ContainsBooks() {
	if (currentIndex >= 0) {
		return true;
	}

	return false;
}

Book* BookArray::GetBook(int index) {
	if (index >=0 && index <= currentIndex)
		return bookList[index];

	return NULL;
}


int BookArray::GetCurrentIndex() {
	return currentIndex;
}

Book* BookArray::GetBookByID(int id) {
	int index = GetBookIndexByID(id);

	if (index >= 0)
		return bookList[index];

	return NULL;
}
int BookArray::GetBookIndexByID(int id) {
	for (int i = 0; i <= currentIndex; i++) {
		if (bookList[i]->getId() == id) {
			return i;
		}
	}

	return -1;
}
void BookArray::makeCopy(BookArray* other) {
	for (int i = 0; i <= currentIndex; i++) {
		this->AddBook(other->bookList[i]);
	}
}