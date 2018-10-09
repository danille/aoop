//
// Created by Lebediev, Danylo on 08/10/2018.
//

#include "CTableManager.h"


void CTableManager::createTables(vector<CTable *> &tablesVector, int numberOfTables, bool *success) {
    for (int i = 0; i < numberOfTables; i++) {
        cout << "Creating table #" << i << endl;
        string name = "Table " + to_string(i);
        CTable *temp = new CTable(name, i);
        cout << "Table #" << i << ": " << temp << endl;
        tablesVector.push_back(temp);
    }
}


bool CTableManager::isTableValid(CTable &table) {
    return &table != nullptr;
}

void CTableManager::setTableLength(CTable &table, int tableLength, bool *success) {
    cout << "Setting " << table.getName() << " table new length" << endl;
    cout << "Table info before setting new length : " << table.toString() << endl;
    table.setLength(tableLength, success);
    cout << "After setting : " << table.toString() << endl;
}

void CTableManager::removeTable(vector<CTable *> &tablesVector, int tablePosition, bool *success) {
    *success = tablePosition >= 0 && tablePosition < tablesVector.size();
    if (*success) {
        // Explicitly delete object, if not - memory leak. Why? Does vector::erase() not run delete?
        delete tablesVector[tablePosition];
        tablesVector.erase(tablesVector.begin() + tablePosition);
    }
}

void CTableManager::removeTables(vector<CTable *> &tablesVector, bool *success) {
    for (int i = 0; i < tablesVector.size(); i++) {
        removeTable(tablesVector, i, success);
    }
}

void CTableManager::setTableName(CTable &table, string tableName, bool *success) {
    cout << "Setting new name. Before setting : " << table.toString() << endl;
    table.setName(tableName, success);
    cout << "After setting : " << table.toString() << endl;
    *success = true;
}

void CTableManager::cloneTable(vector<CTable *> &tablesVector, int tablePosition, bool *success) {
    CTable *temp = tablesVector[tablePosition]->clone(success);
    if (*success)
        tablesVector.push_back(temp);
}

void CTableManager::printTableInfo(CTable &table, bool *success) {
    cout << table.toString() << endl;
}

void CTableManager::printTableElement(CTable &table, int elementPosition, bool *success) {
    string elementString = to_string(table.get(elementPosition, success));
    if (*success) {
        cout << "Element of " << table.getName() << " table at " << to_string(elementPosition) << ": " << elementString;
    }
}

void CTableManager::insertElementIntoTable(CTable &table, int element, int position, bool *success) {
    table.insert(position, element, success);
}
