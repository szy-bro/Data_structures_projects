#include "SinglyLinked.h"


SinglyLinked::SinglyLinked():head(nullptr){
	size = 0;
}

SinglyLinked::~SinglyLinked(){
	SNode* v = get_head();
	while (v != nullptr) {
		deleteFront();
		v = get_head();
	}
}

SNode* SinglyLinked::get_head(){
	return head;
}

void SinglyLinked::display() {
	SNode* v = get_head();
	while (v != nullptr) {
		cout << v ->data << " -> ";
		v = v ->next;
	}
	cout << "END";
	
}

void SinglyLinked::addAt(int index, int value){
	SNode* v = new SNode(); //dodawany węzeł
	v->data = value;
	if (index == 0) {
		addFront(value);
	}
	if (index < 0 || index > size) {
		cout<<"brak indeksu nr "<<index<<endl;
	}
	else {
		SNode* old = new SNode();	//węzeł "transportowy"
		old->data = value;
		old->next = head;
		for (int i = 0; i < index; i++) {
			old = old->next;
		}
		v->next = old->next;
		old->next = v;
		size++;
	}
}

void SinglyLinked::addFront(int value) {
	SNode* v = new SNode();
	v ->data = value;
	v ->next = head;
	head = v;
	size++;
}

void SinglyLinked::addBack(int value) {
	addAt(size, value);
}

void SinglyLinked::deleteAt(int index){
	if (index < 0 || index > size) {
		cout << "brak indeksu nr " << index << endl;
	}
	if (index == 0) {
		deleteFront();
	}
	else {
		SNode* temp = new SNode();
		SNode* old = new SNode();	//węzeł "transportowy"
		old->next = head;
		for (int i = 0; i < index; i++) {
			old = old->next;
		}
		temp = old->next;
		old->next = temp->next;
		delete temp;
		size--;
	}

}

void SinglyLinked::deleteFront(){
	SNode* old = get_head();
	if (old==nullptr) {
		return;
	}
	else{
		head = old->next;
		delete old;
		size--;

	}
}

void SinglyLinked::deleteBack() {
	deleteAt(size-1);
}

void SinglyLinked::load(string file) {
	ifstream myfile(file);
	int a;
	while (myfile >> a) {
		addFront(a);
	}
}
