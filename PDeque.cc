#include "PDeque.h"


PDeque::PDeque() {
	size = 0;
	head = 0;
}

PDeque::PDeque(Patron* firstElement) {
	size = 1;
	head = new Node(firstElement);
}

PDeque::~PDeque() {
	if (size == 0) return;

	Node* temp;

	//delete each node in the linked list
	while (head != 0) {
		temp = head->next;
		delete head;
		head = temp;
	}

	head = 0;
	size = 0;
	
}

void PDeque::push(Patron* patron) {
	if (patron == NULL) {
		return;
	}
	if (size == 0) {
		size++;
		head = new Node(patron);
		return;
	}

	Node* temp;
	Node* prev;
	temp = head;
	prev = head;
	

	if (patron->computeLifetimeCO() >= temp->patron->computeLifetimeCO() || size == 0){
		// H -> (new node) -> (node) -> 0
		// or
		// H -> (new node) -> 0
		head = new Node(patron);
		head->next = temp;
	} else {
		//iterate through to where to place Node
		while (temp != 0)  {
			if (patron->computeLifetimeCO() >= temp->patron->computeLifetimeCO()){	//compare the first and last name
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = new Node(patron);
		prev->next->next = temp;
	}

	size++;
}

void 	PDeque::popFront() {		//remove from front
	//check base case
	if (size == 0) return;

	Node* temp = head;
	head = head->next;
	
	//delete removed node
	delete temp;
	temp = 0;

	size--;
}
void	PDeque::popBack() {			//remove from back
	if (size == 0) return;

	Node* prev;
	Node* temp;
	temp = head;
	prev = head;

	//find the tail
	while (temp->next != 0) {
		prev = temp;
		temp = temp->next;
	}
	

	prev->next = 0;
	delete temp;
	temp = 0;

	size--;
}
Patron* PDeque::front() {		//return the patron at the front
	return head->patron;
}
Patron* PDeque::back() {			//return the patron at the back
	if (size == 0) return NULL;

	Node* temp;
	temp = head;

	//find the tail
	while (temp->next != 0) {
		temp = temp->next;
	}
	
	return temp->patron;
}
Patron* PDeque::find(string fname, string lname) {	//find whether this patron is in here
	if (size == 0) return false;
	
	Node* temp;
	temp = head;
	
	while (temp!=0) {
		if (temp->patron->getFname().compare(fname) == 0 &&
				temp->patron->getLname().compare(lname) == 0) {
			return temp->patron;
		}
	}
	
	return false;
}
bool PDeque::modify(Patron* patron) {
	Patron* check = find(patron->getFname(), patron->getLname());
	if (!check) {
		return false;
	}
	
	check = new Patron(*patron);

	return true;
}
bool PDeque::remove(Patron* patron) {	//look for patron, if found remove them
	if (size == 0) return false;
	
	Node* temp;
	Node* prev;
	prev = head;
	temp = head;
	
	while (temp != 0) {
		if (*(temp->patron) == *patron)	{		//make sure you implement the == operator
			prev->next = temp->next;
			delete temp;
			temp = 0;
		}
		prev = temp;
		temp = temp->next;
	}
	
	size--;
	return false;
}
int 	PDeque::getSize() { return size; }

//make a deep copy
void PDeque::makeCopy(PDeque& other) {
	//cover base cases
	if (this->size > 0 || other.size == 0) {
		this->wipe();
		
		//return empty linked list
		if (other.size == 0) return;
	}
	
	Node* source;
	
	//create the head
	source = other.head;
	
	//create deep copy of each element
	while (source != 0) {
		this->push(source->patron);
		source = source->next;
	}


}

//PRIVATE TOOL FUNCTIONS
void PDeque::wipe() {
	if (size == 0) {
		return;
	}
	Node* temp;
	
	//delete each node in the linked list
	while (head != 0) {
		temp = head->next;
		delete head;
		head = temp;
	}
	
	head = 0;
	size = 0;
}