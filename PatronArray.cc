#include "PatronArray.h"

//CONSTRUCTORS
PatronArray::PatronArray() {
	maxSize = 10;
	currentIndex = -1;
	patronList = new Patron*[maxSize];
}

PatronArray::~PatronArray() {
	if (patronList != 0) {
		for (int i = 0; i <= currentIndex; i++) {
			if (patronList[i] != 0) {
				delete patronList[i];
				patronList[i] = 0;
			}
		}

		delete[] patronList;
	}
}

void PatronArray::CleanUp() {
	if (patronList != NULL) {
		for (int i = 0; i <= currentIndex; i++) {
			if (patronList[i] != NULL)
				patronList[i]->CleanUp();
		}
	}
}

PatronArray::PatronArray(const PatronArray& other) :
maxSize(other.maxSize), currentIndex(other.currentIndex)
{
	this->patronList = new Patron*[maxSize];

	for (int i = 0; i <= currentIndex; i++) {
		patronList[i] = new Patron(*(other.patronList[i]));
	}
}



//PRIVATE
void PatronArray::DoubleArray() {
	maxSize *= 2;
	Patron** temp = new Patron*[maxSize];

	for (int i = 0; i <= currentIndex; i++) {
		temp[i] = patronList[i];
	}

	delete [] patronList;

	patronList = temp;
}
void PatronArray::AddPatron(Patron* patron) {

	if (currentIndex == maxSize - 1) {
		DoubleArray();
	}

	currentIndex++;
	patronList[currentIndex] = patron;

}

Patron* PatronArray::GetPatron(int index) {
	if (index >= 0 && index <= currentIndex) {
		return patronList[index];
	}

	return NULL;
}
void PatronArray::ShiftArray(int index) {
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
bool PatronArray::RemovePatron(Patron* book)	{
	int index = PatronIndex(book);

	if (index >= 0) {
		RemovePatron(index);
		return true;
	}
	else return false;
}


Patron* PatronArray::FindPatron(string fn, string ln){
	for (int i = 0; i <= currentIndex; i++) {
		if (patronList[i]->getFname().compare(fn) == 0 &&
			patronList[i]->getLname().compare(ln) == 0) {
			return patronList[i];
		}
	}

	return NULL;
}

bool PatronArray::RemovePatron(int index) {
	//check for valid input
	if (index < 0 || index > currentIndex) {
		return false;
	}

	//delete patron
	if (currentIndex == index) {
	}
	else {
		ShiftArray(index);
	}

	currentIndex--;

	return true;
}

int PatronArray::PatronIndex(Patron* patron) {
	int retval = -1;
	
	for (int i = 0; i <= currentIndex; i++) {
		if (patronList[i]->getFname().compare(patron->getFname()) == 0 &&
			patronList[i]->getLname().compare(patron->getLname()) == 0) {
			return i;
		}
	}

	return retval;
}


int PatronArray::GetCurrentIndex() {
	return currentIndex;
}