#pragma once
#include "Dynamic.h"
#include "SinglyLinked.h"
#include "DoublyLinked.h"
#include <vector>
#include <chrono>
using namespace std::chrono;

void menuMaking() {
    int list, operation, value, index;
    char cont;
    unique_ptr<DynamicArray> ArrayList = make_unique<DynamicArray>();
    unique_ptr<SinglyLinked> SinglyList = make_unique<SinglyLinked>();
    unique_ptr<DoublyLinked> DoublyList = make_unique<DoublyLinked>();

    cout << "Select type of list to operate on: \n"
        "1. Dynamic List\n"
        "2. Linked List\n"
        "3. Doubly Linked List\n";
    cin >> list;


    while (true) {
        cout << "\nSelect operation:\n"
            "1. Add value to the start of list\n"
            "2. Add value to the end of list\n"
            "3. Add value at the selected place in the list\n"
            "4. Remove the first value from the list\n"
            "5. Remove the last value from the list\n"
            "6. Remove the selected index from the list\n"
            "7. Search numbers of the given value in list\n";
        cin >> operation;

        if (operation == 3 || operation == 6) {
            cout << "Enter position" << endl;
            cin >> index;
        }

        if (operation == 1 || operation == 2 || operation == 3 || operation==7) {
            cout << "Enter value" << endl;
            cin >> value;
        }
        if (operation < 1 || operation > 7) {
            cout << "Invalid operation.\n";
            continue;
        }
        switch (list) {
        case 1:
            switch (operation) {
            case 1:ArrayList->addFront(value); break;
            case 2:ArrayList->addBack(value); break;
            case 3:ArrayList->addAt(index, value); break;
            case 4:ArrayList->deleteFront(); break;
            case 5:ArrayList->deleteBack(); break;
            case 6:ArrayList->deleteAt(index); break;
            case 7:ArrayList->search(value); break;
            }
        case 2:
            switch (operation) {
            case 1:SinglyList->addFront(value); break;
            case 2:SinglyList->addBack(value); break;
            case 3:SinglyList->addAt(index, value); break;
            case 4:SinglyList->deleteFront(); break;
            case 5:SinglyList->deleteBack(); break;
            case 6:SinglyList->deleteAt(index); break;
            case 7:SinglyList->search(value); break;
            }
        case 3:
            switch (operation) {
            case 1:DoublyList->addFront(value); break;
            case 2:DoublyList->addBack(value); break;
            case 3:DoublyList->addAt(index, value); break;
            case 4:DoublyList->deleteFront(); break;
            case 5:DoublyList->deleteBack(); break;
            case 6:DoublyList->deleteAt(index); break;
            case 7:DoublyList->search(value); break;
            }
            break;
        default: cout << "Invalid list selection\n"; break;
        }

        cout << "\nDo you want to display this list? (y/n): ";
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            switch (list) {
            case 1: ArrayList->display(); break;
            case 2: SinglyList->display(); break;
            case 3: DoublyList->display(); break;
            }
        }
        cout << "\nDo you want to continue with this list? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            cout << "Exiting list operation menu. . .\n";
            break;
        }

    }
}

void menuTest() {
    string file;
    long long time = 0;
    int testSize, list, operation, value, index;
    char cont;

    cout << "Select type of list to operate on: \n"
        "1. Dynamic List\n"
        "2. Linked List\n"
        "3. Doubly Linked List\n";
    cin >> list;

    cout << "How many elements to test?\n"
       "1.10000\n"
       "2.20000\n"
       "3.30000\n"
       "4.40000\n"
       "5.50000\n"
       "6.60000\n"
       "7.70000\n"
       "8.80000\n";
       "9.90000\n";
       "10.100000\n";
    cin >> testSize;

    switch (testSize) {
    case 1:file = "base10000.txt"; break;
    case 2:file = "base20000.txt"; break;
    case 3:file = "base30000.txt"; break;
    case 4:file = "base40000.txt"; break;
    case 5:file = "base50000.txt"; break;
    case 6:file = "base60000.txt"; break;
    case 7:file = "base70000.txt"; break;
    case 8:file = "base80000.txt"; break;
    case 9:file = "base90000.txt"; break;
    case 10:file = "base100000.txt"; break;
    }

    while (true) {
        cout << "\nSelect operation:\n"
            "1. Add value to the start of list\n"
            "2. Add value to the end of list\n"
            "3. Add value at the selected place in the list\n"
            "4. Remove the first value from the list\n"
            "5. Remove the last value from the list\n"
            "6. Remove the selected index from the list\n"
            "7. Search numbers of the given value in list\n";
        cin >> operation;

        if (operation == 3 || operation == 6) {
            cout << "Enter position" << endl;
            cin >> index;
        }

        if (operation == 1 || operation == 2 || operation == 3) {
            cout << "Enter value" << endl;
            cin >> value;
        }
        if (operation < 1 || operation > 6) {
            cout << "Invalid operation.\n";
            continue;
        }

        switch (list) {
        case 1:
            switch (operation) {
            case 1:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->addFront(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout <<"Arr AddFront: " << time / 100 << endl; break;
            case 2:for (int i = 0; i < 10; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->addBack(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout <<"Arr AddBack: " << time / 100 << endl; break;
            case 3:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->addAt(index, value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout << "Arr AddAt: " << time / 100 << endl; break;
            case 4:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->deleteFront();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout << "Arr DeleteFront: "<< time / 100 << endl; break;
            case 5:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->deleteBack();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout << "Arr DeleteBack: " << time / 100 << endl; break;
            case 6:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->deleteAt(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout << "Arr DeleteAt: " << time / 100 << endl; break;
            case 7:for (int i = 0; i < 100; i++) {
                DynamicArray* Array = new DynamicArray();
                Array->load(file);
                auto begin = high_resolution_clock::now();
                Array->search(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Array->~DynamicArray();
            }
                  cout << "Arr Search: " << time / 100 << endl; break;
            }
        case 2:
            switch (operation) {
            case 1:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->addFront(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL AddFront: " << time / 100 << endl; break;
            case 2:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->addBack(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL AddBack: " << time / 100 << endl; break;
            case 3:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->addAt(index, value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL AddAt: " << time / 100 << endl; break;
            case 4:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->deleteFront();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL DeleteFront: "<<time / 100 << endl; break;
            case 5:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->deleteBack();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL DeleteBack: " << time / 100 << endl; break;
            case 6:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->deleteAt(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL DeleteAt: " << time / 100 << endl; break;
            case 7:for (int i = 0; i < 100; i++) {
                SinglyLinked* Singly = new SinglyLinked();
                Singly->load(file);
                auto begin = high_resolution_clock::now();
                Singly->search(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Singly->~SinglyLinked();
            }
                  cout << "SL Search: " << time / 100 << endl; break;
            }
        case 3:
            switch (operation) {
            case 1:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->addFront(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL AddFront: " << time / 100 << endl; break;
            case 2:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->addBack(value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL AddBack: " << time / 100 << endl; break;
            case 3:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->addAt(index, value);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL AddAt: " << time / 100 << endl; break;
            case 4:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->deleteFront();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout <<"DL DeleteFront: "<< time / 100 << endl; break;
            case 5:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->deleteBack();
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL DeleteBack: " << time / 100 << endl; break;
            case 6:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->deleteAt(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL DeleteAt: " << time / 100 << endl; break;
            case 7:for (int i = 0; i < 100; i++) {
                DoublyLinked* Doubly = new DoublyLinked();
                Doubly->load(file);
                auto begin = high_resolution_clock::now();
                Doubly->search(index);
                auto end = high_resolution_clock::now();
                time += duration_cast<nanoseconds>(end - begin).count();
                Doubly->~DoublyLinked();
            }
                  cout << "DL Search: " << time / 100 << endl; break;
            }
            break;
        default: cout << "Invalid list selection\n"; break;
        }

        cout << "\nDo you want to continue with this list? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            cout << "Exiting list operation menu. . .\n";
            break;
        }
    }
}

void menu() {
    int choice;
    cout << "Choose your menu\n"
        "1.Testing menu\n"
        "2.Crafting menu\n";
    cin >> choice;
    switch (choice)
    {
    case 1:menuTest(); break;
    case 2:menuMaking(); break;
    default:
        break;
    }
}
