//
// Created by Lebediev, Danylo on 08/10/2018.
//

#ifndef LAB1_CTABLEMANAGER_H
#define LAB1_CTABLEMANAGER_H

#include "CTable.h"
#include "vector"

using namespace std;

class CTableManager {
private:
    int size;

    bool isTableValid(CTable &table);

public:
    void createTables(vector<CTable *> &tablesVector, bool *success);

    void setTableLength(vector<CTable *> &tablesVector,  bool *success);

    void removeTable(vector<CTable *> &tablesVector, bool *success);

    void removeTables(vector<CTable *> &tablesVector, bool *success);

    void setTableName(vector<CTable *> &tablesVector, bool *success);

    void cloneTable(vector<CTable *> &tablesVector, bool *success);

    void printTableInfo(vector<CTable *> &tablesVector, bool *success);

    void printTableElement(vector<CTable *> &tablesVector, bool *success);

    void insertElementIntoTable(vector<CTable *> &tablesVector, bool *success);

    void validateOperation(bool *success);

    bool isTableValid(CTable *&table);

    int getIntValue(std::string hint);

    bool isIndexValid(int index);

    bool isIndexValid(int index, int size);

    void printAllTables(vector<CTable*>& tablesVector, bool* success);

    void executeTest(vector<CTable*>& tablesVector, bool* success);

    void doNothing(CTable cTable, bool* success);
};

#endif //LAB1_CTABLEMANAGER_H
