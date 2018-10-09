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
    CTable **table_arr;
    vector<CTable *> *tables;

    bool isTableValid(CTable &table);

public:
    void createTables(vector<CTable *> &tablesVector, int numberOfTables, bool *success);

    void setTableLength(CTable &table, int tableLength, bool *success);

    void removeTable(vector<CTable *> &tablesVector, int tablePosition, bool *success);

    void removeTables(vector<CTable *> &tablesVector, bool *success);

    void setTableName(CTable &table, string tableName, bool *success);

    void cloneTable(vector<CTable *> &tablesVector, int tablePosition, bool *success);

    void printTableInfo(CTable &table, bool *success);

    void printTableElement(CTable &table, int elementPosition, bool *success);

    void insertElementIntoTable(CTable &table, int element, int position, bool *success);
};

#endif //LAB1_CTABLEMANAGER_H
