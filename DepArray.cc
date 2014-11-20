#include "DepArray.h"

//CONSTRUCTORS
DepArray::DepArray() {
	maxSize = 10;
	currentIndex = -1;
	patronList = new Patron*[maxSize];

	this->parent = NULL;
}
DepArray::DepArray(Patron* parent) {
	maxSize = 10;
	currentIndex = -1;
	patronList = new Patron*[maxSize];

	//set this dependent's parent
	this->parent = parent;
}

DepArray::~DepArray() {
	for (int i = 0; i <= currentIndex; i++) {
		delete this->patronList[i];
	}

	delete this->parent;

	this->patronList = 0;
}

DepArray::DepArray(DepArray* other) {
	maxSize = 10;
	currentIndex = -1;
	patronList = new Patron*[maxSize];

	this->parent = other->parent;

	for (int i = 0; i <= currentIndex; i++) {
		this->patronList[i] = new Patron(*(other->patronList[i]));
	}
}

//PRIVATE
void DepArray::DoubleArray() {
	maxSize *= 2;
	Patron** temp = new Patron*[maxSize];

	for (int i = 0; i <= currentIndex; i++) {
		temp[i] = patronList[i];
	}

	patronList = temp;
}
void DepArray::AddDep(Patron* dep) {
	if (dep = NULL) return;

	if (currentIndex == maxSize - 1) {
		DoubleArray();
	}

	currentIndex++;
	patronList[currentIndex] = new Patron(*dep);
}
void DepArray::ShiftArray(int index) {
	if (index < 0 || index > currentIndex) return;

	delete patronList[index];

	if (index != currentIndex) {
		//shift all elements down
		for (int j = index; j < currentIndex; j++) {
			patronList[j] = patronList[j + 1];
		}
	}

	currentIndex--;
}

//PUBLIC
void DepArray::RemoveDep(Patron* book)	{
	int index = DepIndex(book);

	if (index >= 0)
		RemoveDep(index);
}

void DepArray::RemoveDep(int index) {
	if (currentIndex == index) {
	}
	else {
		ShiftArray(index);
	}

	currentIndex--;
}

void DepArray::SetParent(Patron* parent) {
	this->parent = new Patron(*parent);
}
Patron* DepArray::GetParent() {
	return parent;
}

bool DepArray::ContainsDeps() {
	if (currentIndex >= 0)
		return true;

	return false;
}

int DepArray::DepIndex(Patron* patron) {
	int retval = -1;

	for (int i = 0; i <= currentIndex; i++) {
		if (patronList[i]->getFname().compare(patron->getFname()) == 0 &&
			patronList[i]->getLname().compare(patron->getLname()) == 0) {
			return i;
		}
	}

	return retval;
}

Patron* DepArray::GetPatron(int index) {
	if (index >= 0 && index <= currentIndex) {
		return patronList[index];
	}

	return NULL;
}

int DepArray::GetCurrentIndex() { return currentIndex; }

void DepArray::makeCopy(const DepArray& other) {
	this->currentIndex = other.currentIndex;

	for (int i = 0; i <= currentIndex; i++) {
		this->AddDep(other.patronList[i]);
	}
}