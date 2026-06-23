#include "vector.h"


void DictVector::insert(int key, int value){
    int index = hashModulo(key);
    for (auto& p : table[index]) {
        if (p.first == key) {
            p.second = value;
            return;
        }
    }
    table[index].push_back({ key, value });
}

bool DictVector::remove(int key){
    int index = hashModulo(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            return true;
        }
    }
    return false;
}

void DictVector::display(){
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Kubelek " << i << ": ";
        for (auto& element : table[i]) {
            cout << "(" << element.first << "," << element.second << ") ";
        }
        cout << "\n";
    }
}

void DictVector::load(string file){
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

void DictVector::remove_all(){
    table.clear();
}


