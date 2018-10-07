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
    int* arr;
    int length;

public:
    CTable();
    CTable(string name, int tableLength);
    CTable(CTable& otherTable);

    void changeLenght(int newLength, int* succ);
    void put(int position, int value, int* succ);
    int get(int position, int* succ);
    CTable* clone(int* succ);
    string toString(int* succ);
};
#endif //LAB1_CTABLE_H
