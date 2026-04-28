#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct DNode
{
public:
	int data;
	DNode* next;
	DNode* prev;
};

class DoublyLinked
{
private:
	DNode* header;
	DNode* trailer;
	int size;
public:
	DoublyLinked();
	~DoublyLinked();
	void addAt(int index, int value);
	void deleteAt(int index);
	void addFront(int value);
	void deleteFront();
	void addBack(int value);
	void deleteBack();
	void display();
	void load(string file);
	void search(int value);
};
