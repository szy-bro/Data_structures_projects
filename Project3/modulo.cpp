#include "modulo.h"

void modulo::display() {
	cout << "[";
	for (int i = 0; i <10; i++) {
		for (const auto& j : lista[i]) {
			cout << " [ " << j.first<< ", "<<j.second << " ] ";
		}	
	}
	cout << " ]";
}

int modulo::hash(int k) {
	return k % 10;
}

void modulo::insert(int k, int v) {
	int index = hash(k);
	for (const auto& i : lista[index]) {
		if (i.first == k) {
			return;
		}
	}
	lista[index].emplace_back(k, v);
}


void modulo::remove(int k){
	int index = hash(k);
	lista[index].remove_if([&k](const pair<int, int>& p) {
		return p.first == k;
		});
}

void modulo::remove_all(){
	for (int i= 0; i < 10; i++) {
		lista[i].clear();
	}
}

void modulo::load(string file) {
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
