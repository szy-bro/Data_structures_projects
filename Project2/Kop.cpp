#include "Kop.h"

// wyświetlanie tablicy
void Arr::display() { 
	cout << "[ ";
	for (const auto& i:array) {
		cout << " [ " << i.first << ", " << i.second << " ] ";
	}
	cout << " ]";
}

// dodanie elementu e o priorytecie p
void Arr::insert(int e, int p) {
	array.push_back(make_pair(e, p));

	int index = size;
	size++;
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (array[parent].second < p) {
			swap(array[index], array[parent]);
			index = parent;
		}
		else {
			break;
		}
	}
}

// usunięcie i zwrócenie elementu o największym priorytecie
int Arr::extract_max(){

	if (size == 0) {
		return 0;
	}
	array[0] = array.back();
	array.pop_back();
	size--;
	int i = 0;
	while (true) {
		int index = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left<size && array[left].second > array[index].second) {
			index = left;
		}
		if (right < size && array[right].second > array[index].second) {
			index = right;
		}
		if (index != i) {
			swap(array[index], array[i]);
			i = index;
		}
		else{
			break;
		}
	}
	
	return array[0].first;
}

// zwrócenie elementu o największym priorytecie i jego priorytetu
pair<int, int> Arr::find_max(){
	return array[0];
}

//zmiana priorytetu elementu e na p
void Arr::modify_key(int e, int p){
	int i = 0;
	int check = array[0].first;
	while (e!=check) {
		i++;
		check = array[i].first;
	}
	if (array[i].second > p) {
		array[i].second = p;
		while (true) {	
			int index = i;
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left<size && array[left].second > array[index].second) {
				index = left;
			}
			if (right < size && array[right].second > array[index].second) {
				index = right;
			}
			if (index != i) {
				swap(array[index], array[i]);
				i = index;
			}
			else {
				break;
			}
		}
	}
	if (array[i].second <p) {
		array[i].second = p;
		while (true) {
			int index = i;
			int parent=(i-1)/2;
			if (parent >= 0 && array[index].second > array[parent].second) {
				index = parent;
			}
			if (index != i) {
				swap(array[index], array[i]);
				i = index;
			}
			else {
				break;
			}

		}
	}
}

// wczytywanie pliku tekstowego
void Arr::load(string file) {
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

//zwrócenie rozmiaru
int Arr::return_size(){
	return size;
}

//wyczyszczenie tablicy
void Arr::usun(){
	array.clear();
}
