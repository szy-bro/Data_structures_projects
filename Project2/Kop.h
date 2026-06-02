#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Arr {
private:
	int size;
	vector<pair<int, int>> array;
public:
	void display();
	void load(string file);
	void insert(int e, int p);
	int extract_max();
	pair<int, int> find_max();
	void modify_key(int e, int p);
	int return_size();
	void usun();
};

