#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct SNode
{
public:
	int data;
	SNode* next;
};

class SinglyLinked
{
private:
	SNode* head;
	int size;
public:
	SinglyLinked();
	~SinglyLinked();
	SNode* get_head();
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
