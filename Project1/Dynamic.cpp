#include "Dynamic.h"

DynamicArray::DynamicArray() {
	capacity = 4;
	size = 0;
	array = new int[capacity];
}

DynamicArray::~DynamicArray() {
	delete[] array;
}

//powiekszanie x2 zajmowanego miejsca w pamięci
void DynamicArray::expand() {
	capacity *= 2;

	int* newArray = new int[capacity];
	copy(array, array + size, newArray);
	delete[] array;
	array = newArray;
}

//funkcja wyświetlająca tablicę
void DynamicArray::display() {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << array[i];
		if (i != size-1) {
			cout<< ", ";
		}
	}
	cout << "]";
}


//Funkcja dodająca dany element w danym miejscu
void DynamicArray::addAt(int index, int value) {
	if (size == capacity) {
		expand();
	}
	for (int i = size; i > index; i--) {
		array[i] = array[i - 1];
	}

	array[index] = value;
	size++;
}

//funkcja dodająca dany element na początek
void DynamicArray::addFront(int value) {
	addAt(0,value);
}

//funkcja dodająca dany element na początek
void DynamicArray::addBack(int value) {
	addAt(size, value);
}

//funkcja usuwająca element w danym miejscu
void DynamicArray::deleteAt(int index) {
	if (size > 0) {
		for (int i = index; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
	}
	size--;
}

//funkcja usuwająca element na początku
void DynamicArray::deleteFront() {
	deleteAt(0);
}

//funkcja usuwająca element na końcu
void DynamicArray::deleteBack() {
	deleteAt(size - 1);
}

//funkcja wczytująca plik
void DynamicArray::load(string file) {
	ifstream myfile(file);
	int a;
	while (myfile >> a) {
		addFront(a);
	}
}
