//
// Created by Lebediev, Danylo on 07/10/2018.
//
#define DEFAULT_ARRAY_SIZE 10
#define DEFAULT_ARRAY_NAME "default_name"

#include "CTable.h"

CTable::CTable() {
    this->name = DEFAULT_ARRAY_NAME;
    this->length = DEFAULT_ARRAY_SIZE;
    this->arr = new int[DEFAULT_ARRAY_SIZE];
}

CTable::CTable(string name, int tableLength) {
    this->name = name;
    this->length = tableLength;
    this->arr = new int[tableLength];
}

CTable::CTable(const CTable &otherTable) {
    this->name = otherTable.name + "_copy";
    this->length = otherTable.length;
    this->arr = new int[otherTable.length];

    int successor;

    for (int i = 0; i < otherTable.length; i++){
        this->arr[i] = otherTable.get(i, &successor);
        if (successor != 0) {
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
    this->length = length;
    *success = true;
}


CTable::~CTable() {
    delete[] arr;
}
