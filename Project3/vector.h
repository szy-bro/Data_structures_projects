#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class DictVector {
private:
    static const int TABLE_SIZE = 10;
    vector<list<pair<int, int>>> table;

    int hashModulo(int key) {
        return key % TABLE_SIZE;
    }

public:
    DictVector() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key, int value);

    bool remove(int key);

    void display();

    void load(string file);

    void remove_all();
};