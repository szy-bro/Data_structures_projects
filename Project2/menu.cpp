#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <sstream>
#include <vector>
#include "List.h"
#include "Kop.h"
using namespace std;

void menu() {
	int type, operation, val, prio;
	char cont;
	unique_ptr<List> lista = make_unique<List>();
	Arr arr;
	cout << "List or Heap:\n"
		"1. List\n"
		"2. Heap\n";
	cin >> type;

	while (true) {
		cout << "Select operation:\n"
			"1. Add element of chosen pirority\n"
			"2. Delete element with the highest pirority\n"
			"3. Find element with the highest pirority\n"
			"4. Change priority of chosen element\n"
			"5. Give size of structure\n"
			"6. Load base with 10 elements\n";
		cin >> operation;

		if (operation == 1 || operation == 4) {
			cout << "Enter value of element" << endl;
			cin >> val;
			cout << "Enter level of priority" << endl;
			cin >> prio;
		}
		if (operation < 1 || operation > 6) {
			cout << "Invalid operation.\n";
			continue;
		}
		
		if (type == 1) {
			switch (operation)
			{
			case 1:lista->insert(val, prio); break;
			case 2:cout << "New element of the highest priority: " << lista->extract_max(); break;
			case 3:cout << "Element of the highest priority: " << lista->find_max().first << endl;
				cout << "The highest priority: " << lista->find_max().second << endl; break;
			case 4:lista->modify_key(val, prio); break;
			case 5:cout << "Size of the structure: " << lista->return_size() << endl; break;
			case 6:lista->load("test.txt"); break;
			default:cout << "Invalid\n"; break;
			}

		}


		if (type == 2) {
			switch (operation)
			{
			case 1:arr.insert(val, prio); break;
			case 2:cout << "New element of the highest priority: " << arr.extract_max(); break;
			case 3:cout << "Element of the highest priority: " << arr.find_max().first << endl;
				cout << "The highest priority: " << arr.find_max().second << endl; break;
			case 4:arr.modify_key(val, prio); break;
			case 5:cout << "Size of the structure: " << arr.return_size() << endl; break;
			case 6:arr.load("test.txt"); break;
			default:cout << "Invalid\n"; break;
			}

		}

		cout << "\nDo you want to display this structure? (y/n): ";
		cin >> cont;
		if (cont == 'y' || cont == 'Y') {
			switch (type) {
			case 1:lista->display(); break;
			case 2: arr.display(); break;
			}
		}

		cout << "\nDo you want to continue with this structure? (y/n): ";
		cin >> cont;
		if (cont != 'y' && cont != 'Y') {
			cout << "Exiting list operation menu. . .\n";
			break;
		}
	}
}
