#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int numUnits;
    string *unitList;

public:
    Student(string name, int numUnits) : name(name), numUnits(numUnits) {
        unitList = new string[numUnits];
    }

    void addUnit();
    void display();

    ~Student() {
        delete[] unitList;
    }
};

void Student::addUnit() {
    for (int i = 0; i < numUnits; i++) { 
        cout << "Enter number no. " << i + 1 << ": ";
        cin >> unitList[i];
    }
}

void Student::display() {
    cout << string(20, '-') << endl;
    cout << "STUDENT INFO" << endl;
    cout << string(20, '-') << endl;
    cout << "Name: " << name << endl << endl;
    for (int i = 0; i < numUnits; i++) {
        cout << "Unit " << i + 1 << ": " << unitList[i] << endl;
    }
}

#endif
