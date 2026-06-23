#include "multiplication.h"

void multi::display() {
	cout << "[";
	for (int i = 0; i < 10; i++) {
		for (const auto& j : lista[i]) {
			cout << i<< " [ " << j.first << ", " << j.second << " ] ";
		}
	}
	cout << " ]";
}

int multi::hash(int k) {
	return floor((7*k % 10)/(10/8));
}

void multi::insert(int k, int v) {
	int index = hash(k);
	for (const auto& i : lista[index]) {
		if (i.first == k) {
			return;
		}
	}
	lista[index].emplace_back(k, v);
}


void multi::remove(int k) {
	int index = hash(k);
	lista[index].remove_if([&k](const pair<int, int>& p) {
		return p.first == k;
		});
}

void multi::remove_all() {
	for (int i = 0; i < 10; i++) {
		lista[i].clear();
	}
}

void multi::load(string file) {
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

