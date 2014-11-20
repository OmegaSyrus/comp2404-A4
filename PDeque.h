#ifndef PDEQUE_H
#define PDEQUE_H

#pragma once

#include <string>
#include "Patron.h"

using namespace std;

class PDeque {
private:
	class Node {
		public:
			Patron* patron;
			Node* next;
		
		public:
			Node(Patron* data) {
				patron = new Patron(*data);
				next = 0;
			}
			
			~Node() {
				delete patron;
				patron = 0;
			}
		
		private:
			Node() {
			}
	};

	/////// FUNCTIONS
	////////////////////////////////////////////////////
	public:
		PDeque();
		PDeque(Patron* firstElement);
		PDeque(const PDeque& other);
		~PDeque();
		PDeque& operator--();
		PDeque operator--(int);
		
		void 	push(Patron*);		//push to the front
		void 	popFront();		//remove from front
		void	popBack();			//remove from back
		Patron* front();		//return the patron at the front
		Patron* back();			//return the patron at the back
		Patron* find(string fname, string lname);	//find whether this patron is in here
		bool modify(Patron*);
		bool remove(Patron*);
		int 	getSize();
		void	makeCopy(PDeque& other);
		
	private:
		void 	wipe();
		
	//////// VARIABLES
	////////////////////////////////////////////////////
	
		int size;
		Node* head;	//head of the linked list
		Node* beforeTail;
		
		
};

#endif