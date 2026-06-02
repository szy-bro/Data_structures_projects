#include "List.h"

// konstruktor
List::List():head(nullptr) {
	int size = 0;
}

// destruktor
List::~List() {
	SNode* v = head;
	while (v != nullptr) {
		deleteFront();
		v = head;
	}
}

//metoda pomocna dla destruktora
void List::deleteFront() {
	SNode* old = head;
	if (old == nullptr) {
	}
	else {
		head = old->next;
		delete old;
	}
}

// wyświetlanie listy
void List::display() {
	SNode* v = head;
	while (v != nullptr) {
		cout << v->data <<", "<<v->priority << " -> ";
		v = v->next;
	}
	cout << "END";
}

// dodanie elementu e o priorytecie p
void List::insert(int e, int p){
	SNode* v = new SNode();
	v->data = e;
	v->priority = p;
	v->next = head;
	head = v;
	size++;
}

// usunięcie i zwrócenie elementu o największym priorytecie
int List::extract_max() {
	int p_max=find_max().second;
	SNode* v = new SNode();
	SNode* d = new SNode();
	d = head;
	int max = 0;
	while (d->priority != p_max) {
		v = d;
		d = d->next;
	}
	v->next = d->next;
	delete d;
	size--;

	return find_max().first;
}

// zwrócenie elementu o największym priorytecie i jego priorytetu
pair<int, int> List::find_max(){
	SNode* temp = new SNode();
	temp = head;

	int max = 0;
	int maxp_val = 0;
	while (temp!=nullptr) {
		if (temp->priority > max) { 
			max = temp->priority; 
			maxp_val = temp->data;
		}
		temp = temp->next;
	}
	return make_pair(maxp_val, max);
}

//zmiana priorytetu elementu e na p
void List::modify_key(int e, int p){
	SNode* temp = new SNode();
	temp = head;
	while (temp->data != e) {
		temp = temp->next;
	}
	temp->priority = p;
}

//zwrócenie rozmiaru
int List::return_size(){
	return size;
}

// wczytywanie pliku tekstowego
void List::load(string file){
	fstream myfile;
	myfile.open(file, ios::in);
	string par;
	while (getline(myfile, par)) {
		istringstream ss(par);
		int first, second;
		char comma;

		ss >> first >> comma >> second;
		if (ss) {
			insert(first, second);
		}
	}
}
