#include "DoublyLinked.h"

DoublyLinked::DoublyLinked() :header(nullptr), trailer(nullptr) {
	size = 0;
}

DoublyLinked::~DoublyLinked() {
	DNode* v;
	while (header) {
		v = header;
		header = header->next;
		delete v;
	}
}

void DoublyLinked::addAt(int index, int value) {
	if (index == size - 1) {
		addBack(value);
	}
	if (index<0 || index>size - 1) {
		cout << "brak indeksu nr " << index << endl;
	}
	else {
		DNode* front = header;
		for (int i = 0; i < index - 1; i++) {
			front = front->next;
		}
		DNode* v = new DNode;
		v->data = value;
		if (front->next) {
			front->next->prev = v;
		}
		v->next = front->next;
		front->next = v;
		v->prev = front;
		size++;

	}
}

void DoublyLinked::addFront(int value) {
	DNode* v = new DNode;
	v->data = value;
	v->prev = nullptr;
	if (size == 0) {
		v->next = nullptr;
		header = trailer = v;
	}
	else {
		v->next = header;
		header->prev = v;
		header = v;
	}
	size++;
}

void DoublyLinked::addBack(int value) {
	DNode* v = new DNode;
	v->data = value;
	v->next = nullptr;
	if (size == 0) {
		v->prev = nullptr;
		header = trailer = v;
	}
	else {
		v->prev = trailer;
		trailer->next = v;
		trailer = v;
	}
	size++;
}

void DoublyLinked::deleteAt(int index) {
	if (index == size - 1) {
		deleteBack();
		return;
	}
	DNode* old = header;
	for (int i = 0; i < index; i++) {
		old = old->next;
	}
	old->prev->next = old->next;
	old->next->prev = old->prev;
	delete old;
}

void DoublyLinked::deleteFront() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete header;
		header = trailer = nullptr;
		size = 0;
		return;
	}
	DNode* v = header;
	header = header->next;
	header->prev = nullptr;
	delete v;
	size--;


}

void DoublyLinked::deleteBack() {
	if (size == 0) {
		return;
	}
	if (trailer->prev == nullptr) {
		delete trailer;
		header = trailer = nullptr;
		size = 0;
		return;
	}
	DNode* v = trailer->prev;
	v->next = nullptr;
	delete trailer;
	trailer = v;
	size--;
}

void DoublyLinked::display() {
	DNode* v = header;
	while (v != nullptr) {
		cout << v->data << " -> ";
		v = v->next;

	}
	cout << "END";
}

void DoublyLinked::load(string file) {
	ifstream myfile(file);
	int a;
	while (myfile >> a) {
		addFront(a);
	}
}

void DoublyLinked::search(int value) {
	int count = 0;
	DNode* v = new DNode;
	v = header;
	while (v != nullptr) {
		if (v->data == value) {
			count++;
		}
		v = v->next;
	}
	cout << value << " found in list " << count << " times" << endl;
}
