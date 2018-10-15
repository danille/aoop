//
// Created by Lebediev, Danylo on 07/10/2018.
//
#define DEFAULT_ARRAY_SIZE 10
#define DEFAULT_ARRAY_NAME "default_name"
#define END_LINE_CHAR "\n"

#include "CTable.h"

CTable::CTable() {
    cout << "Run default constructor" << END_LINE_CHAR;
    this->name = DEFAULT_ARRAY_NAME;
    this->length = DEFAULT_ARRAY_SIZE;
    this->arr = new int[DEFAULT_ARRAY_SIZE];
}

CTable::CTable(string name, int tableLength) {
    cout << "Run parametric constructor" << END_LINE_CHAR;
    this->name = name;
    this->length = tableLength;
    this->arr = new int[tableLength];
}

CTable::CTable(const CTable &otherTable) {
    cout << "Run copying constructor" << endl;
    this->name = otherTable.name + "_copy";
    this->length = otherTable.length;
    this->arr = new int[otherTable.length];

    bool success;

    for (int i = 0; i < otherTable.length; i++) {
        this->arr[i] = otherTable.get(i, &success);
        if (!success) {
            cout << "Something goes wrong while getting " << i << "th element from " << otherTable.name << endl;
        }
    }
}

const string CTable::getName() const {
    return name;
}

void CTable::setName(const string &name, bool *success) {
    this->name = name;
    *success = true;
}

int CTable::getLength() const {
    return length;
}

void CTable::setLength(int length, bool *success) {
    *success = length >= 0;
    if (*success) {
        this->length = length;
        // Dynamically allocate memory for temp array
        int *temp = new int[length];
        // Copy values to new array from
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        // Deallocate memory for old arr
        delete[] arr;
        arr = temp;
    }
}


void CTable::insert(int position, int value, bool *success) {
    *success = (position < length && position >= 0);
    if (*success) {
        arr[position] = value;
    }
}

int CTable::get(int position, bool *success) const {
    *success = (position < length && position >= 0);
    if (*success) {
        return arr[position];
    } else {
        return -1;
    }
}

CTable *CTable::clone(bool *success) {
    return new CTable(*this);
}

string CTable::toString() {
    string result;
    result += ("Name: " + name + END_LINE_CHAR);
    result += ("Length: " + to_string(length) + END_LINE_CHAR);
    result += "Elements: ";

    for (int i = 0; i < length; i++) {
        result += to_string(arr[i]);
        result += ", ";
    }

    // Remove trailing comma and space
    result = result.substr(0, result.size() - 2);
    return result;
}

CTable::~CTable() {
    cout << "Running destructor of table " << name << END_LINE_CHAR;
    delete[] arr;
}
