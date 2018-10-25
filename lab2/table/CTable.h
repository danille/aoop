//
// Created by Lebediev, Danylo on 07/10/2018.
//

#ifndef LAB1_CTABLE_H
#define LAB1_CTABLE_H

#include "iostream"

using namespace std;

class CTable {
private:
    string name;
    int *arr;
    int length;

public:
    // Constructors
    CTable();

    CTable(string name, int length);

    CTable(const CTable &otherTable);

    void insert(int position, int value, bool *success);

    int get(int position, bool *success) const;

    const string getName() const;

    void setName(const string &name, bool *success);

    int getLength() const;

    void setLength(int length, bool *success);

    CTable *clone(bool *success);

    string toString();

    ~CTable();
};

#endif //LAB1_CTABLE_H
