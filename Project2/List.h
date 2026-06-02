#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

struct SNode
{
public:
	int data;
	int priority;
	SNode* next;
};

class List
{
private:
	int size;
	SNode* head;
public:
	List();
	~List();
	void deleteFront();
	void display();
	void insert(int e, int p);
	int extract_max();
	pair<int, int> find_max();
	void modify_key(int e, int p);
	int return_size();
	void load(string file);
};
