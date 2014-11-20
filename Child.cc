int Child::getType() {
	return 2; //child signature
}


void Child::setParent(Patron* parent) {
	this->dependents->SetParent(parent);
}

int Child::computeLifetimeCO()    { 

	return lifetimeCO;
}