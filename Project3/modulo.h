#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class modulo {
private:
	list<pair<int, int>> lista[10];
public:
	void display();
	int hash(int k);
	void insert(int k, int v);
	void remove(int k);
	void remove_all();
	void load(string file);
};